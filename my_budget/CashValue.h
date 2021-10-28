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
    CashValue(int userId = 0, int date = 0, string item = "", float amount = 0)
    {
        this-> userId = userId;
        this-> date = date;
        this-> item = item;
        this-> amount = amount;
    }
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif
