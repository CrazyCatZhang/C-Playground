//
// Created by CatZhang on 2020/7/9.
//

#ifndef STAFFMS_WORKER_H
#define STAFFMS_WORKER_H

#pragma once

#include <iostream>

using namespace std;

class Worker {
private:
    int empId;
    string name;
    int depId;
public:
    int getEmpId() const {
        return empId;
    }

    void setEmpId(int empId) {
        Worker::empId = empId;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Worker::name = name;
    }

    int getDepId() const {
        return depId;
    }

    void setDepId(int depId) {
        Worker::depId = depId;
    }

    Worker() {}

    Worker(int empId, const string &name, int depId) : empId(empId), name(name), depId(depId) {}

    virtual ~Worker() {}

    virtual void ShowInfo() = 0;

    virtual string getDepartmentName() = 0;

};

#endif //STAFFMS_WORKER_H
