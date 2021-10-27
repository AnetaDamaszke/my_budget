#ifndef MYBUDGET_H
#define MYBUDGET_H

#include <iostream>

#include "UserMenager.h"
#include "FileWithUsers.h"

using namespace std;

class MyBudget {

    UserMenager userMenager;

public:
    MyBudget(string nameOfFileWithUsers): userMenager(nameOfFileWithUsers) {};
    void userRegistration();
    void listOfAllUsers();

};

#endif
