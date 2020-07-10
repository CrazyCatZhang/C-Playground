//
// Created by CatZhang on 2020/7/9.
//

#ifndef STAFFMS_BOSS_H
#define STAFFMS_BOSS_H
#pragma once

#include <iostream>
#include "Worker.h"

using namespace std;

class Boss : public Worker {
public:
    Boss(int empId, const string &name, int depId);

    string getDepartmentName();

    void ShowInfo();
};

#endif //STAFFMS_BOSS_H
