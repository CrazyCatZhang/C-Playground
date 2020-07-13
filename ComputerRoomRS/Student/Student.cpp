//
// Created by CatZhang on 2020/7/13.
//

#include "Student.h"


int Student::getStudentId() const {
    return studentId;
}

void Student::setStudentId(int studentId) {
    Student::studentId = studentId;
}

Student::Student() {

}

Student::Student(const string &username, const string &password, int studentId) : Identity(username, password),
                                                                                  studentId(studentId) {
    this->computerRoom.clear();
    this->loadComputerRoom();

}

Student::~Student() {

}

void Student::showMenu() {
    cout << "---------- 欢迎使用学生模块 ----------" << endl;
    cout << "************ 0.注销登录 ************" << endl;
    cout << "************ 1.申请预约 ************" << endl;
    cout << "************ 2.查看预约 ************" << endl;
    cout << "************ 3.查看所有预约 ************" << endl;
    cout << "************ 4.取消预约 ************" << endl;
    cout << "-----------------------------------" << endl;
}

void Student::applyOrder() {
    cout << "请选择你要预约的日期：" << endl;
    cout << "1.周一" << endl;
    cout << "2.周二" << endl;
    cout << "3.周三" << endl;
    cout << "4.周四" << endl;
    cout << "5.周五" << endl;
    int date;
    int interval;
    int roomNumber;
    cin >> date;
    cout << "请选择你要预约的时间：" << endl;
    cout << "1.上午" << endl;
    cout << "2.下午" << endl;
    cin >> interval;
    cout << "请选择你要预约的机房：" << endl;
    cout << "机房编号：" << this->computerRoom[0].getRoomNumber()
         << "\t机房容量：" << this->computerRoom[0].getRoomSize() << endl;
    cout << "机房编号：" << this->computerRoom[1].getRoomNumber()
         << "\t机房容量：" << this->computerRoom[1].getRoomSize() << endl;
    cout << "机房编号：" << this->computerRoom[2].getRoomNumber()
         << "\t机房容量：" << this->computerRoom[2].getRoomSize() << endl;
    cin >> roomNumber;
    cout << "申请预约成功 请等待审核..." << endl;

    ofstream ofs;
    ofs.open(ORDERFILE, ios::out | ios::app);
    ofs << "date:" << date << " "
        << "interval:" << interval << " "
        << "roomNumber:" << roomNumber << " "
        << "stuId:" << this->getStudentId() << " "
        << "stuName:" << this->getUsername() << " "
        << "status:" << 1 << " "
        << "time:" << (new Time)->getCurrentSystemTime() << endl;
    ofs.close();
    cout << "按任意键继续...";
    getchar();
    cin.get();
}

void Student::selectMyOrder() {
    Order order;
    if (order.getIndex() == 0){
        cout << "无预约记录..." << endl;
        cout << "按任意键继续...";
        getchar();
        cin.get();
        return;
    }
    for (int i = 0; i < order.getIndex(); ++i) {
        if (atoi(order.orderInfo[i]["stuId"].c_str()) == this->getStudentId()){
            cout << "预约日期：周" << order.orderInfo[i]["date"];
            cout << "\t时段：" << (order.orderInfo[i]["interval"] == "1" ? "上午" : "下午");
            cout << "\t机房：" << order.orderInfo[i]["roomNumber"];
            string status = "\t状态：";
            if (order.orderInfo[i]["status"] == "1"){
                status += "审核中";
            } else if (order.orderInfo[i]["status"] == "2"){
                status += "已预约成功";
            } else if(order.orderInfo[i]["status"] == "0"){
                status += "已取消预约";
            } else if (order.orderInfo[i]["status"] == "-1"){
                status += "预约失败";
            }
            cout << status << endl;
        }
    }
    cout << "按任意键继续...";
    getchar();
    cin.get();
}

void Student::selectAllOrder() {
    Order order;
    if (order.getIndex() == 0){
        cout << "无预约记录..." << endl;
        cout << "按任意键继续...";
        getchar();
        cin.get();
        return;
    }
    for (int i = 0; i < order.getIndex(); ++i) {
        cout << "预约日期：周" << order.orderInfo[i]["date"];
        cout << "\t时段：" << (order.orderInfo[i]["interval"] == "1" ? "上午" : "下午");
        cout << "\t机房：" << order.orderInfo[i]["roomNumber"];
        cout << "\t学号：" << order.orderInfo[i]["stuId"];
        cout << "\t用户名：" << order.orderInfo[i]["stuName"];
        string status = "\t状态：";
        if (order.orderInfo[i]["status"] == "1"){
            status += "审核中";
        } else if (order.orderInfo[i]["status"] == "2"){
            status += "已预约成功";
        } else if(order.orderInfo[i]["status"] == "0"){
            status += "已取消预约";
        } else if (order.orderInfo[i]["status"] == "-1"){
            status += "预约失败";
        }
        cout << status;
        cout << "\t提交时间：" << order.orderInfo[i]["time"] << endl;
    }
    cout << "按任意键继续...";
    getchar();
    cin.get();
}

void Student::cancelOrder() {
    Order order;
    if (order.getIndex() == 0){
        cout << "无预约记录..." << endl;
        cout << "按任意键继续...";
        getchar();
        cin.get();
        return;
    }
    int index = 0;
    vector<int> vector1;
    cout << "审核中或者审核成功的预约才可取消 你的可取消预约记录如下：" << endl;
    for (int i = 0; i < order.getIndex(); ++i) {
        if (atoi(order.orderInfo[i]["stuId"].c_str()) == this->getStudentId()){
            if (order.orderInfo[i]["status"] == "1" || order.orderInfo[i]["status"] == "2"){
                vector1.push_back(i);
                cout << "第 " << ++index << " 预约" << endl;
                cout << "预约日期：周" << order.orderInfo[i]["date"];
                cout << "\t时段：" << (order.orderInfo[i]["interval"] == "1" ? "上午" : "下午");
                cout << "\t机房：" << order.orderInfo[i]["roomNumber"];
                string status = "\t状态：";
                if (order.orderInfo[i]["status"] == "1"){
                    status += "审核中";
                } else if (order.orderInfo[i]["status"] == "2"){
                    status += "已预约成功";
                } else if(order.orderInfo[i]["status"] == "0"){
                    status += "已取消预约";
                } else if (order.orderInfo[i]["status"] == "-1"){
                    status += "预约失败";
                }
                cout << status << endl;
            }
        }
    }
    cout << "请选择你要取消的预约：" << endl;
    cout << "1.确认取消" << endl;
    cout << "0.返回" << endl;
    int select;
    while (true){
        cin >> select;
        if (select >= 0 && select <= vector1.size()){
            if (select == 0){
                break;
            } else{
                order.orderInfo[vector1.at(select - 1)]["status"] = "0";
                order.orderInfo[vector1.at(select - 1)]["time"] = (new Time)->getCurrentSystemTime();
                order.updateOrder();
                cout << "已成功取消预约..." << endl;
                break;
            }
        }
        cout << "输入错误 请重新输入..." << endl;
    }
    cout << "按任意键继续...";
    getchar();
    cin.get();
}

void Student::exitLogin(Identity *&identity) {
    delete identity;
    cout << "注销成功..." << endl;
    cout << "按任意键继续...";
    getchar();
    cin.get();
}

void Student::loadComputerRoom() {
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

    int roomNumber;
    int roomSize;
    ComputerRoom computerRoom1;
    while (ifs >> roomNumber && ifs >> roomSize) {
        computerRoom1.setRoomNumber(roomNumber);
        computerRoom1.setRoomSize(roomSize);
        this->computerRoom.push_back(computerRoom1);
    }
    ifs.close();
}










