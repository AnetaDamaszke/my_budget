#ifndef MYBUDGET_H
#define MYBUDGET_H

#include <iostream>

#include "UserMenager.h"
#include "FileWithUsers.h"
#include "IncomeMenager.h"
#include "ExpenseMenager.h"

using namespace std;

class MyBudget {

    UserMenager userMenager;
    IncomeMenager *incomeMenager;
    ExpenseMenager *expenseMenager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
    MyBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses): userMenager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes),
    NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses)
    {
            incomeMenager = NULL;
            expenseMenager = NULL;
    };
    ~MyBudget()
    {
        delete incomeMenager;
        delete expenseMenager;
        incomeMenager = NULL;
        expenseMenager = NULL;
    };
    void userRegistration();
    void listOfAllUsers();
    int userLogin();
    void logoutUser();
    bool isUserLoggedIn();
    void changePasswordOfLoggedInUser();
    void addNewIncome();
    void addNewExpense();
    void displayIncomes();
    void displayExpenses();

};

#endif
