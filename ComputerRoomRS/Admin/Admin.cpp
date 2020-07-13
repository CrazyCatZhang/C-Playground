//
// Created by CatZhang on 2020/7/13.
//

#include "Admin.h"

Admin::Admin() {
}

Admin::Admin(const string &username, const string &password) : Identity(username, password) {
    this->initialize();
}

Admin::~Admin() {

}

void Admin::showMenu() {
    cout << "---------- 欢迎使用管理模块 ----------" << endl;
    cout << "************ 0.注销登录 ************" << endl;
    cout << "************ 1.添加账户 ************" << endl;
    cout << "************ 2.查看账户 ************" << endl;
    cout << "************ 3.查看机房 ************" << endl;
    cout << "************ 4.清空预约 ************" << endl;
    cout << "-----------------------------------" << endl;
}

void Admin::addAccount() {
    cout << "1.添加学生账户..." << endl;
    cout << "2.添加教师账户..." << endl;
    int select;
    cin >> select;
    string filename;
    if (select == 1) {
        filename = STUDENTFILE;
    } else {
        filename = TEACHERFILE;
    }
    ofstream ofs;
    ofs.open(filename, ios::out | ios::app);
    int id;
    string name;
    string pwd;
    if (select == 1) {
        vector<Student> vector1;
        cout << "请输入你要添加的学号：" << endl;
        while (true) {
            cin >> id;
            if (this->checkRepeat(id, 1)) {
                cout << "学号重复 请重新输入..." << endl;
            } else {
                break;
            }
        }
        cout << "请设置用户名：" << endl;
        cin >> name;
        cout << "请设置密码：" << endl;
        cin >> pwd;
        Student student1;
        student1.setStudentId(id);
        student1.setUsername(name);
        student1.setPassword(pwd);
        vector1.push_back(student1);
        for (vector<Student>::iterator it = vector1.begin(); it != vector1.end(); it++) {
            ofs << it->getStudentId() << " "
                << it->getUsername() << " "
                << it->getPassword() << endl;
        }
        vector1.clear();
        ofs.close();
        cout << "添加学生账户成功..." << endl;
        cout << "按任意键继续...";
        getchar();
        cin.get();
    } else {
        vector<Teacher> vector2;
        cout << "请输入你要添加的职工号：" << endl;
        while (true) {
            cin >> id;
            if (this->checkRepeat(id, 2)) {
                cout << "职工号重复 请重新输入..." << endl;
            } else {
                break;
            }
        }
        cout << "请设置用户名：" << endl;
        cin >> name;
        cout << "请设置密码：" << endl;
        cin >> pwd;
        Teacher teacher1;
        teacher1.setTeacherId(id);
        teacher1.setUsername(name);
        teacher1.setPassword(pwd);
        vector2.push_back(teacher1);
        for (vector<Teacher>::iterator it = vector2.begin(); it != vector2.end(); it++) {
            ofs << it->getTeacherId() << " "
                << it->getUsername() << " "
                << it->getPassword() << endl;
        }
        vector2.clear();
        ofs.close();
        cout << "添加教师账户成功..." << endl;
        cout << "按任意键继续...";
        getchar();
        cin.get();
    }
    this->initialize();
}

void Admin::selectAccount() {
    cout << "1.查看学生账户信息..." << endl;
    cout << "2.查看教师账户信息..." << endl;
    int select;
    cin >> select;
    if (select == 1) {
        for_each(this->student.begin(), this->student.end(), printStudent());
    } else {
        for_each(this->teacher.begin(), this->teacher.end(), printTeacher());
    }
    cout << "按任意键继续...";
    getchar();
    cin.get();
}

void Admin::selectComputerRoom() {
    ifstream ifs;
    ifs.open(COMPUTERROOM, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在或者为空..." << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件不存在或者为空..." << endl;
        ifs.close();
        return;
    }
    ifs.putback(ch);

    cout << "机房信息如下：" << endl;
    ComputerRoom computerRoom;
    int number;
    int size;
    while (ifs >> number && ifs >> size) {
        computerRoom.setRoomNumber(number);
        computerRoom.setRoomSize(size);
        this->computerRoom.push_back(computerRoom);
    }
    for_each(this->computerRoom.begin(), this->computerRoom.end(), printComputerRoom());
    this->computerRoom.clear();
    ifs.close();
    cout << "按任意键继续...";
    getchar();
    cin.get();
}

void Admin::clearOrder() {
    ofstream ofs;
    ofs.open(ORDERFILE, ios::trunc);
    ofs.close();
    cout << "清空成功..." << endl;
    cout << "按任意键继续...";
    getchar();
    cin.get();
}

void Admin::exitLogin(Identity *&identity) {
    delete identity;
    cout << "注销成功..." << endl;
    cout << "按任意键继续...";
    getchar();
    cin.get();
}

void Admin::initialize() {
    this->student.clear();
    this->teacher.clear();
    this->computerRoom.clear();

    ifstream ifs;
    //学生初始化
    ifs.open(STUDENTFILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在或者为空..." << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件不存在或者为空..." << endl;
        ifs.close();
        return;
    }
    ifs.putback(ch);
    Student student1;
    int id;
    string name;
    string pwd;
    while (ifs >> id && ifs >> name && ifs >> pwd) {
        student1.setStudentId(id);
        student1.setUsername(name);
        student1.setPassword(pwd);
        this->student.push_back(student1);
    }
    cout << "学生人数为：" << this->student.size() << endl;
    ifs.close();

    //教师初始化
    ifs.open(TEACHERFILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在或者为空..." << endl;
        ifs.close();
        return;
    }

    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件不存在或者为空..." << endl;
        ifs.close();
        return;
    }
    ifs.putback(ch);

    Teacher teacher1;
    while (ifs >> id && ifs >> name && ifs >> pwd) {
        teacher1.setTeacherId(id);
        teacher1.setUsername(name);
        teacher1.setPassword(pwd);
        this->teacher.push_back(teacher1);
    }
    cout << "教师人数为：" << this->teacher.size() << endl;
    ifs.close();

}

bool Admin::checkRepeat(int id, int type) {
    if (type == 1) {
        for (vector<Student>::iterator it = this->student.begin(); it != this->student.end(); it++) {
            if (id == it->getStudentId()) {
                return true;
            }
        }
    } else {
        for (vector<Teacher>::iterator it = this->teacher.begin(); it != this->teacher.end(); it++) {
            if (id == it->getTeacherId()) {
                return true;
            }
        }
    }
    return false;
}












