//
// Created by CatZhang on 2020/7/13.
//

#include "Teacher.h"

int Teacher::getTeacherId() const {
    return teacherId;
}

void Teacher::setTeacherId(int teacherId) {
    Teacher::teacherId = teacherId;
}

Teacher::Teacher() {

}

Teacher::Teacher(const string &username, const string &password, int teacherId) : Identity(username, password),
                                                                                  teacherId(teacherId) {

}

Teacher::~Teacher() {

}

void Teacher::showMenu() {
    cout << "---------- 欢迎使用教师模块 ----------" << endl;
    cout << "************ 0.注销登录 ************" << endl;
    cout << "************ 1.查看所有预约 ************" << endl;
    cout << "************ 2.审核预约 ************" << endl;
    cout << "-----------------------------------" << endl;
}

void Teacher::exitLogin(Identity *&identity) {
    delete identity;
    cout << "注销成功..." << endl;
    cout << "按任意键继续...";
    getchar();
    cin.get();
}

void Teacher::selectAllOrder() {
    Order order;
    if (order.getIndex() == 0) {
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
        if (order.orderInfo[i]["status"] == "1") {
            status += "审核中";
        } else if (order.orderInfo[i]["status"] == "2") {
            status += "已预约成功";
        } else if (order.orderInfo[i]["status"] == "0") {
            status += "已取消预约";
        } else if (order.orderInfo[i]["status"] == "-1") {
            status += "预约失败";
        }
        cout << status;
        cout << "\t提交时间：" << order.orderInfo[i]["time"] << endl;
    }
    cout << "按任意键继续...";
    getchar();
    cin.get();
}

void Teacher::auditOrder() {
    Order order;
    if (order.getIndex() == 0) {
        cout << "无预约记录..." << endl;
        cout << "按任意键继续...";
        getchar();
        cin.get();
        return;
    }
    cout << "只能审核已申请的预约信息..." << endl;
    int index = 0;
    vector<int> vector1;
    for (int i = 0; i < order.getIndex(); ++i) {
        if (order.orderInfo[i]["status"] == "1") {
            vector1.push_back(i);
            cout << "第 " << ++index << " 预约" << endl;
            cout << "预约日期：周" << order.orderInfo[i]["date"];
            cout << "\t时段：" << (order.orderInfo[i]["interval"] == "1" ? "上午" : "下午");
            cout << "\t机房：" << order.orderInfo[i]["roomNumber"];
            cout << "\t学号：" << order.orderInfo[i]["stuId"];
            cout << "\t用户名：" << order.orderInfo[i]["stuName"];
            string status = "\t状态：";
            if (order.orderInfo[i]["status"] == "1") {
                status += "审核中";
            } else if (order.orderInfo[i]["status"] == "2") {
                status += "已预约成功";
            } else if (order.orderInfo[i]["status"] == "0") {
                status += "已取消预约";
            } else if (order.orderInfo[i]["status"] == "-1") {
                status += "预约失败";
            }
            cout << status;
            cout << "\t提交时间：" << order.orderInfo[i]["time"] << endl;
        }
    }
    if (vector1.size() != 0){
        cout << "请选择你要审核的预约信息：" << endl;
        int select = 0;
        while (true) {
            cin >> select;
            if (select >= 0 && select <= vector1.size()) {
                if (select == 0) {
                    break;
                } else {
                    cout << "1.通过申请..." << endl;
                    cout << "2.拒绝申请..." << endl;
                    int choice = 0;
                    cin >> choice;
                    if (choice == 1) {
                        order.orderInfo[vector1.at(select - 1)]["status"] = "2";
                        order.orderInfo[vector1.at(select - 1)]["time"] = (new Time)->getCurrentSystemTime();
                        order.updateOrder();
                        cout << "已成功审核预约..." << endl;
                        break;
                    } else {
                        order.orderInfo[vector1.at(select - 1)]["status"] = "-1";
                        order.orderInfo[vector1.at(select - 1)]["time"] = (new Time)->getCurrentSystemTime();
                        order.updateOrder();
                        cout << "已拒绝预约申请..." << endl;
                        break;
                    }
                }
            }
            cout << "输入错误 请重新输入..." << endl;
        }
    } else{
        cout << "暂无可审核的预约记录..." << endl;
    }
    cout << "按任意键继续...";
    getchar();
    cin.get();
}



