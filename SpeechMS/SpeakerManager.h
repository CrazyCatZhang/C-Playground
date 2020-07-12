//
// Created by CatZhang on 2020/7/12.
//

#ifndef SPEECHMS_SPEAKERMANAGER_H
#define SPEECHMS_SPEAKERMANAGER_H
#define COMPETITORNUM 12
#define JUDGENUMBER 10
#define FILENAME "speech.csv"
#pragma once

#include "Competitor.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <random>
#include <deque>
#include <fstream>
#include <string>

using namespace std;

class SpeakerManager {
private:
    vector<int> FirstCompetitor;
    vector<int> SecondCompetitor;
    vector<int> VictoryCompetitor;
    map<int, Competitor> competitorInfo;
    map<int,vector<string> > competitorRecord;
    int roundNumber;
    bool fileIsEmpty;
public:
    SpeakerManager();

    virtual ~SpeakerManager();

    void initialize();

    void creatCompetitor();

    void startCompetition();

    void startDram();

    void startSpeech();

    void showScore();

    void saveRecord();

    void loadRecord();

    void showRecord();

    void clearFile();

    void ShowMenu();

    void exitSystem();

    bool isFileIsEmpty() const;

    void setFileIsEmpty(bool fileIsEmpty);
};


#endif //SPEECHMS_SPEAKERMANAGER_H
