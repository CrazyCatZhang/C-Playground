//
// Created by CatZhang on 2020/7/13.
//

#ifndef COMPUTERROOMRS_TIME_H
#define COMPUTERROOMRS_TIME_H
#pragma once

#include <iostream>
#include <chrono>
#include <_types.h>

using namespace std;

class Time {
public:
    string getCurrentSystemTime() {
        auto tt = std::chrono::system_clock::to_time_t
                (std::chrono::system_clock::now());
        struct tm *ptm = localtime(&tt);
        char date[60] = {0};
        sprintf(date, "%d-%02d-%02d-%02d.%02d.%02d",
                (int) ptm->tm_year + 1900, (int) ptm->tm_mon + 1, (int) ptm->tm_mday,
                (int) ptm->tm_hour, (int) ptm->tm_min, (int) ptm->tm_sec);
        return std::string(date);
    }
};


#endif //COMPUTERROOMRS_TIME_H
