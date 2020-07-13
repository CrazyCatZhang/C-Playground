//
// Created by CatZhang on 2020/7/13.
//

#ifndef COMPUTERROOMRS_ADMIN_H
#define COMPUTERROOMRS_ADMIN_H
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "../Header/Global.h"
#include "../Header/Identity.h"
#include "../Student/Student.h"
#include "../Teacher/Teacher.h"
#include "../Header/ComputerRoom.h"

using namespace std;

class printStudent {
public:
    void operator()(Student &student) {
        cout << "学号：" << student.getStudentId() << "\t用户名：" << student.getUsername() << "\t密码：" << student.getPassword()
             << endl;
    }
};

class printTeacher {
public:
    void operator()(Teacher &teacher) {
        cout << "职工号：" << teacher.getTeacherId() << "\t用户名：" << teacher.getUsername() << "\t密码："
             << teacher.getPassword() << endl;
    }
};

class printComputerRoom {
public:
    void operator()(ComputerRoom &computerRoom) {
        cout << "机房编号：" << computerRoom.getRoomNumber()
             << "\t机房容量：" << computerRoom.getRoomSize() << endl;
    }
};

class Admin : public Identity {
private:
    vector<Student> student;
    vector<Teacher> teacher;
    vector<ComputerRoom> computerRoom;
public:
    Admin();

    Admin(const string &username, const string &password);

    virtual ~Admin();

    void showMenu() override;

    void addAccount();

    void selectAccount();

    void selectComputerRoom();

    void clearOrder();

    void exitLogin(Identity *&identity) override;

    void initialize();

    bool checkRepeat(int id, int type);

};


#endif //COMPUTERROOMRS_ADMIN_H
