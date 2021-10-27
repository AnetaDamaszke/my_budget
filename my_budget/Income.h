#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income : public CashValue {

    int incomeId;

public:
    void setIncomeId(int newIncomeId);
    int getIncomeId();
};

#endif
