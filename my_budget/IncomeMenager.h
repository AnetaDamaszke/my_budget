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

    int getIdNumberOfLoggedInUser();

public:
    IncomeMenager(string nameOfFileWithIncomes, int idNumberOfLoggedInUser): fileWithIncomes(nameOfFileWithIncomes), ID_NUMBER_OF_LOGGED_IN_USER(idNumberOfLoggedInUser)
    {
        incomes = fileWithIncomes.loadIncomesFromFile(ID_NUMBER_OF_LOGGED_IN_USER);
    };
    void addNewIncome();
    void displayAllIncomes();
    void sortIncomesByDate();
    float getIncomesFromCurrenthMonth();
    float getIncomesFromLastMonth();
    float getIncomesFromSelectedDate(string firstDate, string secondDate);
    int getIdOfNewIncome();
};

#endif
