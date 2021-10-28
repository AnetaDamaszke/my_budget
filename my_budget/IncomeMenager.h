#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H

#include <iostream>
#include <vector>

#include "CashValueMenager.h"
#include "FileWithIncomes.h"
#include "Income.h"

using namespace std;

class IncomeMenager : public CashValueMenager {

    int idNumberOfLoggedInUser;
    vector<Income> incomes;
    //FileWithIncomes fileWithIncomes;

    Income getDataOfNewIncome();
    int getIdOfNewIncome();
    int getIdNumberOfLoggedInUser();

public:
    IncomeMenager(int idNumberOfLoggedInUser): CashValueMenager(idNumberOfLoggedInUser) {};
    void addNewIncome();
};

#endif
