//
// Created by CatZhang on 2020/7/13.
//

#include "Management.h"

Management::Management() {}

Management::~Management() {

}

void Management::ShowMenu() {
    cout << "------ 欢迎使用机房预约管理系统 ------" << endl;
    cout << "************ 0.退出系统 ************" << endl;
    cout << "************ 1.学生模块 ************" << endl;
    cout << "************ 2.教师模块 ************" << endl;
    cout << "************ 3.管理模块 ************" << endl;
    cout << "----------------------------------" << endl;
}

void Management::exitSystem() {
    cout << "欢迎下次使用..." << endl;
    cout << "按任意键继续...";
    getchar();
    cin.get();
    exit(0);
}

void Management::login(string filename, int type) {
    Identity *identity = NULL;
    cout << "----- 请登录 -----" << endl;
    ifstream ifs;
    ifs.open(filename, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在或者为空" << endl;
        ifs.close();
        cout << "按任意键继续...";
        getchar();
        cin.get();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件不存在或者为空..." << endl;
        ifs.close();
        cout << "按任意键继续...";
        getchar();
        cin.get();
        return;
    }
    int id;
    if (type == 1) {
        cout << "请输入你的学号：" << endl;
        cin >> id;
    } else if (type == 2) {
        cout << "请输入你的职工号：" << endl;
        cin >> id;
    }
    string name;
    string pwd;
    cout << "请输入你的用户名：" << endl;
    cin >> name;
    cout << "请输入你的用户密码：" << endl;
    cin >> pwd;
    ifs.putback(ch);
    if (type == 1) {
        int stuId;
        string username;
        string password;
        while (ifs >> stuId && ifs >> username && ifs >> password) {
            if (id == stuId && name == username && password == pwd) {
                cout << "登录成功..." << endl;
                cout << "按任意键继续...";
                getchar();
                cin.get();
                identity = new Student(name, pwd, id);
                StudentMenu(identity);
                return;
            }
        }
    } else if (type == 2) {
        int teachId;
        string username;
        string password;
        while (ifs >> teachId && ifs >> username && ifs >> password) {
            if (id == teachId && name == username && password == pwd) {
                cout << "登录成功..." << endl;
                cout << "按任意键继续...";
                getchar();
                cin.get();
                identity = new Teacher(name, pwd, id);
                TeacherMenu(identity);
                return;
            }
        }
    } else {
        string username;
        string password;
        while (ifs >> username && ifs >> password) {
            if (name == username && pwd == password) {
                cout << "登录成功..." << endl;
                cout << "按任意键继续...";
                getchar();
                cin.get();
                identity = new Admin(name, pwd);
                AdminMenu(identity);
                return;
            }
        }
    }
    cout << "登录失败 用户名或者密码不正确..." << endl;
    cout << "按任意键继续...";
    getchar();
    cin.get();
}

void Management::StudentMenu(Identity *&identity) {
    while (true) {
        identity->showMenu();
        Student *student = (Student *) identity;
        int select = 0;
        cout << "请选择：" << endl;
        cin >> select;
        if (select == 1) {
            student->applyOrder();
        } else if (select == 2) {
            student->selectMyOrder();
        } else if (select == 3) {
            student->selectAllOrder();
        } else if (select == 4) {
            student->cancelOrder();
        } else {
            student->exitLogin(identity);
            return;
        }
    }
}

void Management::TeacherMenu(Identity *&identity) {
    while (true) {
        identity->showMenu();
        Teacher *teacher = (Teacher *) identity;
        int select = 0;
        cout << "请选择：" << endl;
        cin >> select;
        if (select == 1) {
            teacher->selectAllOrder();
        } else if (select == 2) {
            teacher->auditOrder();
        } else {
            teacher->exitLogin(identity);
            return;
        }
    }
}

void Management::AdminMenu(Identity *&identity) {
    while (true) {
        identity->showMenu();
        Admin *admin = (Admin *) identity;
        int select = 0;
        cout << "请选择：" << endl;
        cin >> select;
        if (select == 1) {
            admin->addAccount();
        } else if (select == 2) {
            admin->selectAccount();
        } else if (select == 3) {
            admin->selectComputerRoom();
        } else if (select == 4) {
            admin->clearOrder();
        } else {
            admin->exitLogin(identity);
            return;
        }
    }
}
