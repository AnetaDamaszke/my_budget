#include "CashValue.h"

void CashValue::setUserId(int newUserId)
{
    userId = newUserId;
}

void CashValue::setDate(int newDate)
{
    date = newDate;
}

void CashValue::setItem(string newItem)
{
    item = newItem;
}

void CashValue::setAmount(string newAmount)
{
    amount = newAmount;
}

int CashValue::getUserId()
{
    return userId;
}

int CashValue::getDate()
{
    return date;
}

string CashValue::getItem()
{
    return item;
}

float CashValue::getAmount()
{
    return amount;
}
