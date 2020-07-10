#include "../Header/Employee.h"

//
// Created by CatZhang on 2020/7/9.
//

Employee::Employee(int empId, const string &name, int depId) : Worker(empId, name, depId) {}

void Employee::ShowInfo() {
    cout << "职工编号：" << this->getEmpId()
         << "\t职工姓名：" << this->getName()
         << "\t岗位：" << this->getDepartmentName()
         << "\t岗位职责：完成经理交代的任务" << endl;
}

string Employee::getDepartmentName() {
    return "员工";
}

