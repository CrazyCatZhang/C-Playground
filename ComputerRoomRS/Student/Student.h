//
// Created by CatZhang on 2020/7/13.
//

#ifndef COMPUTERROOMRS_STUDENT_H
#define COMPUTERROOMRS_STUDENT_H
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "../Order/Order.h"
#include "../Header/Time.h"
#include "../Header/Global.h"
#include "../Header/Identity.h"
#include "../Header/ComputerRoom.h"

using namespace std;

class Student : public Identity {
private:
    int studentId;
    vector<ComputerRoom> computerRoom;
public:
    int getStudentId() const;

    void setStudentId(int studentId);

    Student();

    Student(const string &username, const string &password, int studentId);

    virtual ~Student();

    void showMenu() override;

    void applyOrder();

    void selectMyOrder();

    void selectAllOrder();

    void cancelOrder();

    void exitLogin(Identity *&identity) override;

    void loadComputerRoom();
};


#endif //COMPUTERROOMRS_STUDENT_H
