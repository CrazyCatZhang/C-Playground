//
// Created by CatZhang on 2020/7/13.
//

#ifndef COMPUTERROOMRS_IDENTITY_H
#define COMPUTERROOMRS_IDENTITY_H
#pragma once

#include <iostream>

using namespace std;

class Identity {
private:
    string username;
    string password;
public:
    const string &getUsername() const {
        return username;
    }

    void setUsername(const string &username) {
        Identity::username = username;
    }

    const string &getPassword() const {
        return password;
    }

    void setPassword(const string &password) {
        Identity::password = password;
    }

    Identity() {}

    Identity(const string &username, const string &password) : username(username), password(password) {}

    virtual ~Identity() {}

    virtual void showMenu() = 0;

    virtual void exitLogin(Identity * &identity) = 0;
};


#endif //COMPUTERROOMRS_IDENTITY_H
