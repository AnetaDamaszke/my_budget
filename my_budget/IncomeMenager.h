#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H

#include <iostream>
#include <vector>

#include "CashValueMenager.h"
#include "FileWithIncomes.h"
#include "Income.h"

using namespace std;

class IncomeMenager : public CashValueMenager {

    const int ID_NUMBER_OF_LOGGED_IN_USER;
    vector<Income> incomes;
    FileWithIncomes fileWithIncomes;

    Income getDataOfNewIncome();
    int getIdOfNewIncome();
    int getIdNumberOfLoggedInUser();

public:
    IncomeMenager(string nameOfFileWithIncomes, int idNumberOfLoggedInUser): fileWithIncomes(nameOfFileWithIncomes), ID_NUMBER_OF_LOGGED_IN_USER(idNumberOfLoggedInUser) {};
    void addNewIncome();
    void displayIncomes();
};

#endif
