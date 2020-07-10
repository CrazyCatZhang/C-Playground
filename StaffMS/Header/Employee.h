//
// Created by CatZhang on 2020/7/9.
//

#ifndef STAFFMS_EMPLOYEE_H
#define STAFFMS_EMPLOYEE_H

#pragma once

#include <iostream>
#include "Worker.h"

using namespace std;

class Employee : public Worker {
public:
    Employee(int empId, const string &name, int depId);

    virtual void ShowInfo();

    virtual string getDepartmentName();
};

#endif //STAFFMS_EMPLOYEE_H
