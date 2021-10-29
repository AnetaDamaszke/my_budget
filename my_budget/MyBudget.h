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
    const string NAME_OF_FILE_WITH_INCOMES;

public:
    MyBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes): userMenager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes) {
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
    void displayIncomes();

};

#endif
