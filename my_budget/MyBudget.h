#ifndef MYBUDGET_H
#define MYBUDGET_H

#include <iostream>

#include "UserMenager.h"
#include "FileWithUsers.h"
#include "IncomeMenager.h"

using namespace std;

class MyBudget {

    UserMenager userMenager;
    IncomeMenager *incomeMenager;

public:
    MyBudget(string nameOfFileWithUsers): userMenager(nameOfFileWithUsers) {
            incomeMenager = NULL;
    };
    ~MyBudget()
    {
        delete incomeMenager;
        incomeMenager = NULL;
    };
    void userRegistration();
    void listOfAllUsers();
    int userLogin();
    void logoutUser();
    bool isUserLoggedIn();
    void changePasswordOfLoggedInUser();
    void addNewIncome();

};

#endif
