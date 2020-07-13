//
// Created by CatZhang on 2020/7/13.
//

#ifndef COMPUTERROOMRS_TEACHER_H
#define COMPUTERROOMRS_TEACHER_H
#pragma once
#include <iostream>
#include <vector>
#include "../Header/Time.h"
#include "../Header/Identity.h"
#include "../Order/Order.h"

using namespace std;

class Teacher: public Identity{
private:
    int teacherId;
public:
    int getTeacherId() const;

    void setTeacherId(int teacherId);

    Teacher();

    Teacher(const string &username, const string &password, int teacherId);

    virtual ~Teacher();

    void showMenu() override;

    void selectAllOrder();

    void auditOrder();

    void exitLogin(Identity *&identity) override;
};


#endif //COMPUTERROOMRS_TEACHER_H
