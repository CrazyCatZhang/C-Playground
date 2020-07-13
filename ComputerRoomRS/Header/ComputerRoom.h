//
// Created by CatZhang on 2020/7/13.
//

#ifndef COMPUTERROOMRS_COMPUTERROOM_H
#define COMPUTERROOMRS_COMPUTERROOM_H
#pragma once
#include <iostream>
using namespace std;

class ComputerRoom {
private:
    int roomNumber;
    int roomSize;
public:
    int getRoomNumber() const {
        return roomNumber;
    }

    void setRoomNumber(int roomNumber) {
        ComputerRoom::roomNumber = roomNumber;
    }

    int getRoomSize() const {
        return roomSize;
    }

    void setRoomSize(int roomSize) {
        ComputerRoom::roomSize = roomSize;
    }

    ComputerRoom(){}

    ComputerRoom(int roomNumber, int roomSize) : roomNumber(roomNumber), roomSize(roomSize) {}

    virtual ~ComputerRoom() {}
};


#endif //COMPUTERROOMRS_COMPUTERROOM_H
