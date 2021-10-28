#ifndef INCOME_H
#define INCOME_H

#include <iostream>

#include "CashValue.h"

using namespace std;

class Income : public CashValue {

    int incomeId;

public:
    Income(int incomeId = 0)
    {
        this->incomeId = incomeId;
    };
    void setIncomeId(int newIncomeId);
    int getIncomeId();
};

#endif
