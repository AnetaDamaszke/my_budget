#ifndef CASHVALUE_H
#define CASHVALUE_H

#include <iostream>

using namespace std;

class CashValue {

    int userId;
    int date;
    string item;
    float amount;

public:
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif
