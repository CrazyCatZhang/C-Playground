//
// Created by CatZhang on 2020/7/9.
//

#ifndef STAFFMS_MANAGER_H
#define STAFFMS_MANAGER_H
#pragma once

#include <iostream>
#include "Worker.h"

using namespace std;

class Manager : public Worker {
public:
    Manager(int empId, const string &name, int depId);

    void ShowInfo();

    string getDepartmentName();
};

#endif //STAFFMS_MANAGER_H
