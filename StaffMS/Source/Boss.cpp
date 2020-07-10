//
// Created by CatZhang on 2020/7/9.
//

#include "../Header/Boss.h"


Boss::Boss(int empId, const string &name, int depId) : Worker(empId, name, depId) {}

void Boss::ShowInfo() {
    cout << "职工编号：" << this->getEmpId()
         << "\t职工姓名：" << this->getName()
         << "\t岗位：" << this->getDepartmentName()
         << "\t岗位职责：管理整个公司" << endl;
}

string Boss::getDepartmentName() {
    return "老板";
}
