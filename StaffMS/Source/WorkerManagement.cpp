#include "../Header/WorkerManagement.h"
#include "../Source/Employee.cpp"
#include "../Source/Manager.cpp"
#include "../Source/Boss.cpp"
//
// Created by CatZhang on 2020/7/9.
//
WorkerManagement::WorkerManagement() {
    this->initialize();
}

void WorkerManagement::ShowMenu() {
    cout << "****** 欢迎使用职工管理系统 ******" << endl;
    cout << "********** 0.退出系统 **********" << endl;
    cout << "********** 1.添加职工 **********" << endl;
    cout << "********** 2.显示职工 **********" << endl;
    cout << "********** 3.删除职工 **********" << endl;
    cout << "********** 4.修改职工 **********" << endl;
    cout << "********** 5.查找职工 **********" << endl;
    cout << "********** 6.排序职工 **********" << endl;
    cout << "********** 7.清空文件 **********" << endl;
    cout << "*******************************" << endl;
}

void WorkerManagement::Exit() {
    cout << "欢迎下次使用..." << endl;
    cout << "按Enter键继续...";
    getchar();
    cin.get();
    exit(0);
}

void WorkerManagement::addEmployee() {
    int addNumber = 0;
    cout << "请输入要添加的职工人数： " << endl;
    cin >> addNumber;
    if (addNumber > 0) {
        //记录新的空间大小
        int newSize = this->getMemberNum() + addNumber;
        //开辟新空间
        Worker **newSpace = new Worker *[newSize];
        if (this->getMemberArray() != NULL) {
            for (int i = 0; i < this->getMemberNum(); i++) {
                newSpace[i] = this->getMemberArray()[i];
            }
        }
        for (int i = 0; i < addNumber; i++) {
            cout << "这是你要添加的第 " << i + 1 << " 个职工..." << endl;
            cout << "请输入你要添加的职工id：" << endl;
            int empId;
            cin >> empId;
            cout << "请输入你要添加的职工姓名：" << endl;
            string name;
            cin >> name;
            cout << "请输入你要添加的部门id：" << endl;
            cout << "1.普通职工..." << endl;
            cout << "2.经理..." << endl;
            cout << "3.老板..." << endl;
            int depId;
            cin >> depId;
            Worker *worker = NULL;
            switch (depId) {
                case 1:
                    worker = new Employee(empId, name, depId);
                    break;
                case 2:
                    worker = new Manager(empId, name, depId);
                    break;
                case 3:
                    worker = new Boss(empId, name, depId);
                    break;
                default:
                    break;
            }
            newSpace[this->getMemberNum() + i] = worker;
        }
        //释放原有内存空间
        delete[] this->getMemberArray();
        //指向新的内存空间
        this->setMemberArray(newSpace);
        this->setMemberNum(newSize);
        saveEmployee();
        cout << "添加成功..." << endl;
        this->initialize();
    } else {
        cout << "输入有误 请重新输入..." << endl;
    }
    cout << "按Enter键继续...";
    getchar();
    cin.get();
    system("clear");
}

WorkerManagement::~WorkerManagement() {
    if (this->getMemberArray() != NULL) {
        for (int i = 0; i < this->getMemberNum(); ++i) {
            delete this->getMemberArray()[i];
            this->getMemberArray()[i] = NULL;
        }
        delete[] this->getMemberArray();
        this->setMemberArray(NULL);
    }
}

void WorkerManagement::saveEmployee() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->getMemberNum(); i++) {
        ofs << this->getMemberArray()[i]->getEmpId() << " "
            << this->getMemberArray()[i]->getName() << " "
            << this->getMemberArray()[i]->getDepId() << endl;
    }
    ofs.close();
    this->setFileIsEmpty(false);
}

void WorkerManagement::initialize() {
    //文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open()) {
//        cout << "文件不存在" << endl;
//        WorkerManagement(0, true, NULL);
        this->setMemberNum(0);
        this->setFileIsEmpty(true);
        this->setMemberArray(NULL);
        ifs.close();
        return;
    }
    //文件为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
//        WorkerManagement(0, true, NULL);
        this->setMemberNum(0);
        this->setFileIsEmpty(true);
        this->setMemberArray(NULL);
        ifs.close();
        return;
    }

    //文件有数据
    this->setMemberNum(this->getNumber());
    this->setFileIsEmpty(false);
    this->setMemberArray(new Worker *[this->getMemberNum()]);
    this->initIndex();
}

int WorkerManagement::getMemberNum() const {
    return MemberNum;
}

void WorkerManagement::setMemberNum(int memberNum) {
    MemberNum = memberNum;
}

bool WorkerManagement::isFileIsEmpty() const {
    return FileIsEmpty;
}

void WorkerManagement::setFileIsEmpty(bool fileIsEmpty) {
    FileIsEmpty = fileIsEmpty;
}

Worker **WorkerManagement::getMemberArray() const {
    return memberArray;
}

void WorkerManagement::setMemberArray(Worker **memberArray) {
    WorkerManagement::memberArray = memberArray;
}

int WorkerManagement::getNumber() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int empId;
    string name;
    int depId;
    int num = 0;
    while (ifs >> empId && ifs >> name && ifs >> depId) {
        num++;
    }
    return num;
}

void WorkerManagement::initIndex() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int empId;
    string name;
    int depId;
    int index = 0;
    while (ifs >> empId && ifs >> name && ifs >> depId) {
        Worker *worker = NULL;
        if (depId == 1) {
            worker = new Employee(empId, name, depId);
        } else if (depId == 2) {
            worker = new Manager(empId, name, depId);
        } else {
            worker = new Boss(empId, name, depId);
        }
        this->getMemberArray()[index] = worker;
        index++;
    }
}

void WorkerManagement::ShowEmployee() {
    if (!this->isFileIsEmpty()) {
        Worker *worker = NULL;
        for (int i = 0; i < this->getMemberNum(); ++i) {
            if (this->getMemberArray()[i]->getDepId() == 1) {
                worker = new Employee(this->getMemberArray()[i]->getEmpId(), this->getMemberArray()[i]->getName(),
                                      this->getMemberArray()[i]->getDepId());
                worker->ShowInfo();
            } else if (this->getMemberArray()[i]->getDepId() == 2) {
                worker = new Manager(this->getMemberArray()[i]->getEmpId(), this->getMemberArray()[i]->getName(),
                                     this->getMemberArray()[i]->getDepId());
                worker->ShowInfo();
            } else {
                worker = new Boss(this->getMemberArray()[i]->getEmpId(), this->getMemberArray()[i]->getName(),
                                  this->getMemberArray()[i]->getDepId());
                worker->ShowInfo();
            }
        }
        delete worker;
        worker = NULL;
    } else {
        cout << "文件不存在或者为空..." << endl;
    }
    cout << "按Enter键继续...";
    getchar();
    cin.get();
    system("clear");
}

void WorkerManagement::deleteEmployee() {
    //判断职工是否存在
    if (!this->isFileIsEmpty()) {
        cout << "请输入你要删除的职工id：" << endl;
        int id = 0;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1) {
            for (int i = index; i < this->getMemberNum(); ++i) {
                this->getMemberArray()[i] = this->getMemberArray()[i + 1];
            }
            this->setMemberNum(this->getMemberNum() - 1);
            this->saveEmployee();
            cout << "删除成功..." << endl;
        }
    } else {
        cout << "文件不存在或者为空..." << endl;
    }
    cout << "按Enter键继续...";
    getchar();
    cin.get();
    system("clear");
}

int WorkerManagement::isExist(int id) {
    int index = -1;
    for (int i = 0; i < this->getMemberNum(); ++i) {
        if (this->getMemberArray()[i]->getEmpId() == id) {
            index = i;
        }
    }
    return index;
}

void WorkerManagement::updateEmployee() {
    if (!this->isFileIsEmpty()) {
        cout << "请输入你要修改的职工的id：" << endl;
        int id = 0;
        cin >> id;
        if (this->isExist(id) != -1) {
            delete this->getMemberArray()[this->isExist(id)];
            int empId;
            string name;
            int depId;
            cout << "请输入新的职工id：" << endl;
            cin >> empId;
            cout << "请输入新的职工姓名：" << endl;
            cin >> name;
            cout << "请输入新的部门id：" << endl;
            cout << "1.普通职工..." << endl;
            cout << "2.经理..." << endl;
            cout << "3.老板..." << endl;
            cin >> depId;
            Worker *worker = NULL;
            switch (depId) {
                case 1:
                    worker = new Employee(empId, name, depId);
                    break;
                case 2:
                    worker = new Manager(empId, name, depId);
                    break;
                case 3:
                    worker = new Boss(empId, name, depId);
                    break;
                default:
                    break;
            }
            this->getMemberArray()[this->isExist(id)] = worker;
            cout << "修改成功" << endl;
            this->saveEmployee();
        } else {
            cout << "输入的职工id不存在 请添加..." << endl;
        }
    } else {
        cout << "文件不存在或者为空..." << endl;
    }
    cout << "按Enter键继续...";
    getchar();
    cin.get();
    system("clear");
}

void WorkerManagement::selectEmployee() {
    if (!this->isFileIsEmpty()) {
        cout << "请输入你要查询的方式：" << endl;
        cout << "1.按id查询..." << endl;
        cout << "2.按姓名查询..." << endl;
        int select = 0;
        cin >> select;
        if (select == 1) {
            int empId;
            cout << "请输入你要查询的职工id：" << endl;
            cin >> empId;
            if (this->isExist(empId) != -1) {
                cout << "查询到的职工信息为：" << endl;
                Worker *worker = NULL;
                if (this->getMemberArray()[this->isExist(empId)]->getDepId() == 1) {
                    worker = new Employee(this->getMemberArray()[this->isExist(empId)]->getEmpId(),
                                          this->getMemberArray()[this->isExist(empId)]->getName(),
                                          this->getMemberArray()[this->isExist(empId)]->getDepId());
                    worker->ShowInfo();
                } else if (this->getMemberArray()[this->isExist(empId)]->getDepId() == 2) {
                    worker = new Manager(this->getMemberArray()[this->isExist(empId)]->getEmpId(),
                                         this->getMemberArray()[this->isExist(empId)]->getName(),
                                         this->getMemberArray()[this->isExist(empId)]->getDepId());
                    worker->ShowInfo();
                } else {
                    worker = new Boss(this->getMemberArray()[this->isExist(empId)]->getEmpId(),
                                      this->getMemberArray()[this->isExist(empId)]->getName(),
                                      this->getMemberArray()[this->isExist(empId)]->getDepId());
                    worker->ShowInfo();
                }
                delete worker;
                worker = NULL;
            }
        } else {
            string name;
            cout << "请输入你要查询的职工姓名：" << endl;
            cin >> name;
            if (this->isExist(name) != -1) {
                cout << "查询到的职工信息为：" << endl;
                Worker *worker = NULL;
                if (this->getMemberArray()[this->isExist(name)]->getDepId() == 1) {
                    worker = new Employee(this->getMemberArray()[this->isExist(name)]->getEmpId(),
                                          this->getMemberArray()[this->isExist(name)]->getName(),
                                          this->getMemberArray()[this->isExist(name)]->getDepId());
                    worker->ShowInfo();
                } else if (this->getMemberArray()[this->isExist(name)]->getDepId() == 2) {
                    worker = new Manager(this->getMemberArray()[this->isExist(name)]->getEmpId(),
                                         this->getMemberArray()[this->isExist(name)]->getName(),
                                         this->getMemberArray()[this->isExist(name)]->getDepId());
                    worker->ShowInfo();
                } else {
                    worker = new Boss(this->getMemberArray()[this->isExist(name)]->getEmpId(),
                                      this->getMemberArray()[this->isExist(name)]->getName(),
                                      this->getMemberArray()[this->isExist(name)]->getDepId());
                    worker->ShowInfo();
                }
                delete worker;
                worker = NULL;
            }
        }
    } else {
        cout << "文件不存在或者为空..." << endl;
    }
    cout << "按Enter键继续...";
    getchar();
    cin.get();
    system("clear");
}

int WorkerManagement::isExist(string name) {
    int index = -1;
    for (int i = 0; i < this->getMemberNum(); ++i) {
        if (this->getMemberArray()[i]->getName() == name) {
            index = i;
        }
    }
    return index;
}

void WorkerManagement::sortEmployee() {
    if (!this->isFileIsEmpty()) {
        cout << "请选择排序方式：" << endl;
        cout << "1.按照升序排列..." << endl;
        cout << "2.按照降序排列..." << endl;
        int select = 0;
        cin >> select;
        for (int i = 0; i < this->getMemberNum() - 1; ++i) {
            int minOrMax = i;
            for (int j = i + 1; j < this->getMemberNum(); ++j) {
                if (select == 1) {
                    minOrMax = this->getMemberArray()[j]->getEmpId() < this->getMemberArray()[minOrMax]->getEmpId() ? j
                                                                                                                    : minOrMax;
                } else {
                    minOrMax = this->getMemberArray()[j]->getEmpId() > this->getMemberArray()[minOrMax]->getEmpId() ? j
                                                                                                                    : minOrMax;
                }
            }
            if (i != minOrMax) {
                this->swapEmployee(i, minOrMax);
            }
        }
        cout << "排序成功..." << endl;
        this->saveEmployee();
    } else {
        cout << "文件不存在或者为空..." << endl;
    }
    cout << "按Enter键继续...";
    getchar();
    cin.get();
    system("clear");
}

void WorkerManagement::swapEmployee(int index, int minOrMax) {
    Worker *temp = this->getMemberArray()[index];
    this->getMemberArray()[index] = this->getMemberArray()[minOrMax];
    this->getMemberArray()[minOrMax] = temp;
}

void WorkerManagement::emptyFile() {
    if (!this->isFileIsEmpty()) {
        cout << "是否确认清空文件？" << endl;
        cout << "1.确定清空..." << endl;
        cout << "2.返回..." << endl;
        int select = 0;
        cin >> select;
        if (select == 1) {
            ofstream ofs(FILENAME, ios::trunc);
            ofs.close();
            if (this->getMemberArray() != NULL) {
                for (int i = 0; i < this->getMemberNum(); ++i) {
                    delete this->getMemberArray()[i];
                    this->getMemberArray()[i] = NULL;
                }
                this->setMemberNum(0);
                delete[] this->getMemberArray();
                this->setFileIsEmpty(true);
                this->setMemberArray(NULL);
//                WorkerManagement(0, true, NULL);
            }
        }
        cout << "清空成功..." << endl;
    } else {
        cout << "文件不存在或者为空..." << endl;
    }
    cout << "按Enter键继续...";
    getchar();
    cin.get();
    system("clear");
}


