//
// Created by CatZhang on 2020/7/12.
//

#include "SpeakerManager.h"

SpeakerManager::SpeakerManager() {
    this->initialize();
}

SpeakerManager::~SpeakerManager() {

}

void SpeakerManager::ShowMenu() {
    cout << "--------------------------------" << endl;
    cout << "***** 欢迎使用演讲比赛管理系统 *****" << endl;
    cout << "********* 0.退出管理系统 *********" << endl;
    cout << "********* 1.开始演讲比赛 *********" << endl;
    cout << "********* 2.查看往届信息 *********" << endl;
    cout << "********* 3.清空比赛记录 *********" << endl;
    cout << "--------------------------------" << endl;
}

void SpeakerManager::exitSystem() {
    cout << "欢迎下次使用..." << endl;
    cout << "按Enter键继续...";
    getchar();
    cin.get();
    exit(0);
}

void SpeakerManager::initialize() {
    this->FirstCompetitor.clear();
    this->SecondCompetitor.clear();
    this->VictoryCompetitor.clear();
    this->competitorInfo.clear();
    this->competitorRecord.clear();
    this->roundNumber = 1;

    this->creatCompetitor();
    this->loadRecord();
}

void SpeakerManager::creatCompetitor() {
    string arr = "ABCDEFGHIJKL";
    for (int i = 0; i < COMPETITORNUM; ++i) {
        string name = "选手";
        name += arr[i];
        Competitor competitor;
        competitor.setName(name);
        competitor.setFirstScore(0.0f);
        competitor.setSecondScore(0.0f);
        this->FirstCompetitor.push_back(i + 10001);
        this->competitorInfo.insert(make_pair(i + 10001, competitor));
    }
}

void SpeakerManager::startCompetition() {
    for (; this->roundNumber < 3; this->roundNumber++) {
        this->startDram();
        this->startSpeech();
        this->showScore();
    }
    this->saveRecord();
    this->initialize();

    system("clear");
}

void SpeakerManager::startDram() {
    cout << "第 " << this->roundNumber << " 轮选手抽签顺序如下：" << endl;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    if (this->roundNumber == 1) {
        shuffle(this->FirstCompetitor.begin(), this->FirstCompetitor.end(), default_random_engine(seed));
//        random_shuffle(this->FirstCompetitor.begin(), this->FirstCompetitor.end());
        for (vector<int>::iterator it = this->FirstCompetitor.begin(); it != this->FirstCompetitor.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    } else {
        shuffle(this->SecondCompetitor.begin(), this->SecondCompetitor.end(), default_random_engine(seed));
//        random_shuffle(this->SecondCompetitor.begin(), this->SecondCompetitor.end());
        for (vector<int>::iterator it = this->SecondCompetitor.begin(); it != this->SecondCompetitor.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "按Enter键继续...";
    if (this->roundNumber == 1) {
        getchar();
    }
    cin.get();

}

void SpeakerManager::startSpeech() {
    cout << "---------------第 " << this->roundNumber << " 轮比赛开始---------------" << endl;
    cout << endl;
    multimap<double, int, greater<double> > temporary;
    int num = 0;
    vector<int> vector1;
    if (this->roundNumber == 1) {
        vector1 = this->FirstCompetitor;
    } else {
        vector1 = this->SecondCompetitor;
    }
    for (vector<int>::iterator it = vector1.begin(); it != vector1.end(); it++) {
        num++;
        deque<double> record;
        for (int i = 0; i < JUDGENUMBER; ++i) {
            double score = (rand() % 401 + 600) / 10.f;
            record.push_back(score);
        }
        sort(record.begin(), record.end());
        record.pop_front();
        record.pop_back();
        double sum = accumulate(record.begin(), record.end(), 0.0f);
        double average = sum / (double) record.size();
        if (this->roundNumber == 1) this->competitorInfo.find(*it)->second.setFirstScore(average);
        if (this->roundNumber == 2) this->competitorInfo.find(*it)->second.setSecondScore(average);
        temporary.insert(make_pair(average, *it));
        if (num % 6 == 0) {
            cout << "---------------------------------" << endl;
            cout << "第 " << num / 6 << " 小组成绩如下：" << endl;
            for (multimap<double, int, greater<double> >::iterator it = temporary.begin(); it != temporary.end(); it++) {
                cout << "选手编号：" << it->second << "\t选手最终成绩：" << it->first << endl;
            }
            cout << endl;
            int count = 0;
            for (multimap<double, int, greater<double> >::iterator it = temporary.begin();
                 it != temporary.end() && count < 3; it++, count++) {
                if (this->roundNumber == 1) {
                    this->SecondCompetitor.push_back(it->second);
                } else {
                    this->VictoryCompetitor.push_back(it->second);
                }
            }
            temporary.clear();
        }
    }
    cout << "---------------第 " << this->roundNumber << " 轮比赛完毕---------------" << endl;
    cout << "按Enter键继续...";
    cin.get();
}

void SpeakerManager::showScore() {
    cout << "---------------第 " << this->roundNumber << " 晋级选手信息---------------" << endl;
    vector<int> temporary;
    if (this->roundNumber == 1) {
        temporary = this->SecondCompetitor;
    } else {
        temporary = this->VictoryCompetitor;
    }
    for (vector<int>::iterator it = temporary.begin(); it != temporary.end(); it++) {
        if (this->roundNumber == 1) {
            cout << "选手编号：" << *it << "\t姓名：" << this->competitorInfo.find(*it)->second.getName()
                 << "\t最终得分：" << this->competitorInfo.find(*it)->second.getFirstScore() << endl;
        } else {
            cout << "选手编号：" << *it << "\t姓名：" << this->competitorInfo.find(*it)->second.getName()
                 << "\t最终得分：" << this->competitorInfo.find(*it)->second.getSecondScore() << endl;
        }
    }
    cout << endl;
    cout << "按Enter键继续...";
    cin.get();
}

void SpeakerManager::saveRecord() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out | ios::app);
    for (vector<int>::iterator it = this->VictoryCompetitor.begin(); it != this->VictoryCompetitor.end(); it++) {
        ofs << *it << ","
            << this->competitorInfo.find(*it)->second.getSecondScore() << ",";
    }
    ofs << endl;
    ofs.close();
    this->setFileIsEmpty(false);
}

void SpeakerManager::loadRecord() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open()) {
        this->setFileIsEmpty(true);
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        this->setFileIsEmpty(true);
        ifs.close();
        return;
    }
    this->setFileIsEmpty(false);
    ifs.putback(ch);
    string record;
    int index = 0;
    while (ifs >> record) {
        vector<string> vector1;
        int pos = -1;
        int start = 0;
        while (1) {
            pos = record.find(",", start);
            if (pos == -1) {
                break;
            }
            vector1.push_back(record.substr(start, pos - start));
            start = pos + 1;
        }
        this->competitorRecord.insert(make_pair(index, vector1));
        index++;
        vector1.clear();
    }
    ifs.close();
}

bool SpeakerManager::isFileIsEmpty() const {
    return fileIsEmpty;
}

void SpeakerManager::setFileIsEmpty(bool fileIsEmpty) {
    SpeakerManager::fileIsEmpty = fileIsEmpty;
}

void SpeakerManager::showRecord() {
    if (!this->isFileIsEmpty()) {
        for (int i = 0; i < this->competitorRecord.size(); ++i) {
            cout << "第 " << i + 1 << " 届" << endl;
            cout << "冠军编号：" << this->competitorRecord[i][0]
                 << "\t冠军得分：" << this->competitorRecord[i][1] << endl;
            cout << "亚军编号：" << this->competitorRecord[i][2]
                 << "\t亚军得分：" << this->competitorRecord[i][3] << endl;
            cout << "季军编号：" << this->competitorRecord[i][4]
                 << "\t季军得分：" << this->competitorRecord[i][5] << endl;
        }
    } else {
        cout << "文件为空或者不存在..." << endl;
    }
    cout << "按Enter键继续...";
    getchar();
    cin.get();
    system("clear");
}

void SpeakerManager::clearFile() {
    if (!this->isFileIsEmpty()) {
        cout << "是否要清空文件：" << endl;
        cout << "1.确认清空..." << endl;
        cout << "2.返回..." << endl;
        int select = 0;
        cin >> select;
        if (select == 1) {
            ofstream ofs;
            ofs.open(FILENAME, ios::trunc);
            ofs.close();
            this->initialize();
            cout << "清空成功..." << endl;
        } else {
            return;
        }
    } else {
        cout << "文件不存在或者为空..." << endl;
    }
    cout << "按Enter键继续...";
    getchar();
    cin.get();
    system("clear");
}




