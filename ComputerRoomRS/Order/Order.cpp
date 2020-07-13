//
// Created by CatZhang on 2020/7/13.
//

#include "Order.h"

int Order::getIndex() const {
    return index;
}

void Order::setIndex(int index) {
    Order::index = index;
}

Order::Order() {
    this->orderInfo.clear();
    this->setIndex(0);
    ifstream ifs;
    ifs.open(ORDERFILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在或者为空..." << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件不存在或者为空..." << endl;
        ifs.close();
        return;
    }
    ifs.putback(ch);


    string date;
    string interval;
    string roomNumber;
    string stuId;
    string stuName;
    string status;
    string time;
    while (ifs >> date && ifs >> interval && ifs >> roomNumber && ifs >> stuId && ifs >> stuName && ifs >> status &&
           ifs >> time) {
        string key;
        string value;
        map<string, string> temporary;

        int pos = date.find(":");
        if (pos != -1) {
            key = date.substr(0, pos);
            value = date.substr(pos + 1, date.size() - pos - 1);
            temporary.insert(make_pair(key, value));
        }

        pos = interval.find(":");
        if (pos != -1) {
            key = interval.substr(0, pos);
            value = interval.substr(pos + 1, interval.size() - pos - 1);
            temporary.insert(make_pair(key, value));
        }

        pos = roomNumber.find(":");
        if (pos != -1) {
            key = roomNumber.substr(0, pos);
            value = roomNumber.substr(pos + 1, roomNumber.size() - pos - 1);
            temporary.insert(make_pair(key, value));
        }

        pos = stuId.find(":");
        if (pos != -1) {
            key = stuId.substr(0, pos);
            value = stuId.substr(pos + 1, stuId.size() - pos - 1);
            temporary.insert(make_pair(key, value));
        }

        pos = stuName.find(":");
        if (pos != -1) {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos + 1, stuName.size() - pos - 1);
            temporary.insert(make_pair(key, value));
        }

        pos = status.find(":");
        if (pos != -1) {
            key = status.substr(0, pos);
            value = status.substr(pos + 1, status.size() - pos - 1);
            temporary.insert(make_pair(key, value));
        }

        pos = time.find(":");
        if (pos != -1) {
            key = time.substr(0, pos);
            value = time.substr(pos + 1, time.size() - pos - 1);
            temporary.insert(make_pair(key, value));
        }
        this->orderInfo.insert(make_pair(this->getIndex(), temporary));
        this->setIndex(this->getIndex() + 1);
    }
    ifs.close();
}

void Order::updateOrder() {
    if (this->getIndex() == 0) {
        return;
    }

    ofstream ofs;
    ofs.open(ORDERFILE, ios::out | ios::trunc);
    for (int i = 0; i < this->getIndex(); ++i) {
        ofs << "date:" << this->orderInfo[i]["date"] << " ";
        ofs << "interval:" << this->orderInfo[i]["interval"] << " ";
        ofs << "roomNumber:" << this->orderInfo[i]["roomNumber"] << " ";
        ofs << "stuId:" << this->orderInfo[i]["stuId"] << " ";
        ofs << "stuName:" << this->orderInfo[i]["stuName"] << " ";
        ofs << "status:" << this->orderInfo[i]["status"] << " ";
        ofs << "time:" << this->orderInfo[i]["time"] << endl;
    }
    ofs.close();
}

