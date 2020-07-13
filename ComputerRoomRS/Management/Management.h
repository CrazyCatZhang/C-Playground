//
// Created by CatZhang on 2020/7/13.
//

#ifndef COMPUTERROOMRS_MANAGEMENT_H
#define COMPUTERROOMRS_MANAGEMENT_H
#pragma once
#include <iostream>
#include <fstream>
#include "../Student/Student.h"
#include "../Teacher/Teacher.h"
#include "../Admin/Admin.h"
#include "../Header/Global.h"
using namespace std;

class Management {
public:
    Management();

    virtual ~Management();

    void ShowMenu();

    void exitSystem();

    void login(string filename,int type);

    void StudentMenu(Identity * &identity);

    void TeacherMenu(Identity * &identity);

    void AdminMenu(Identity * &identity);
};


#endif //COMPUTERROOMRS_MANAGEMENT_H
