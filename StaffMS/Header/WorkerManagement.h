//
// Created by CatZhang on 2020/7/9.
//

#ifndef STAFFMS_WORKERMANAGEMENT_H
#define STAFFMS_WORKERMANAGEMENT_H
#pragma once
#define FILENAME "employee.txt"

#include <iostream>
#include <fstream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

using namespace std;

class WorkerManagement {
private:
    int MemberNum;
    bool FileIsEmpty;
    Worker ** memberArray;
public:
    WorkerManagement();

    virtual ~WorkerManagement();

    void ShowMenu();

    void Exit();

    void addEmployee();

    void saveEmployee();

    void initialize();

    int getNumber();

    void initIndex();

    void ShowEmployee();

    void deleteEmployee();

    int isExist(int id);

    int isExist(string name);

    void updateEmployee();

    void selectEmployee();

    void sortEmployee();

    void swapEmployee(int index,int minOrMax);

    void emptyFile();

    int getMemberNum() const;

    void setMemberNum(int memberNum);

    bool isFileIsEmpty() const;

    void setFileIsEmpty(bool fileIsEmpty);

    Worker **getMemberArray() const;

    void setMemberArray(Worker **memberArray);

};

#endif //STAFFMS_WORKERMANAGEMENT_H
