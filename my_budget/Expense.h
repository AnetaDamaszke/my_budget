#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

#include "CashValue.h"

using namespace std;

class Expense : public CashValue {

    int expenseId;

public:
    Expense(int expenseId = 0)
    {
        this->expenseId = expenseId;
    };
    void setExpenseId(int newExpenseId);
    int getExpenseId();
};

#endif
