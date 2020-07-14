//
// Created by CatZhang on 2020/7/13.
//

#ifndef COMPUTERROOMRS_ORDER_H
#define COMPUTERROOMRS_ORDER_H
#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include "../Header/Global.h"
using namespace std;

class Order {
private:
    int index;
public:
    map<int,map<string,string> > orderInfo;
public:
    int getIndex() const;

    void setIndex(int index);

    Order();

    void updateOrder();
};


#endif //COMPUTERROOMRS_ORDER_H
