//
// Created by CatZhang on 2020/7/9.
//

#include "../Header/Manager.h"


Manager::Manager(int empId, const string &name, int depId) : Worker(empId, name, depId) {}

void Manager::ShowInfo() {
    cout << "职工编号：" << this->getEmpId()
         << "\t职工姓名：" << this->getName()
         << "\t岗位：" << this->getDepartmentName()
         << "\t岗位职责：完成老板交代的任务" << endl;
}

string Manager::getDepartmentName() {
    return "经理";
}

