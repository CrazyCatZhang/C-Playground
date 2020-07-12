//
// Created by CatZhang on 2020/7/12.
//

#ifndef SPEECHMS_COMPETITOR_H
#define SPEECHMS_COMPETITOR_H
#pragma once
#include <iostream>
using namespace std;

class Competitor {
private:
    string name;
//    double score[ROUNDNUMBER];
    double firstScore;
    double secondScore;
public:
    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Competitor::name = name;
    }

    double getFirstScore() const {
        return firstScore;
    }

    void setFirstScore(double firstScore) {
        Competitor::firstScore = firstScore;
    }

    double getSecondScore() const {
        return secondScore;
    }

    void setSecondScore(double secondScore) {
        Competitor::secondScore = secondScore;
    }

};


#endif //SPEECHMS_COMPETITOR_H
