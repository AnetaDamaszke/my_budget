#ifndef CASHVALUEMENAGER_H
#define CASHVALUEMENAGER_H

#include <iostream>
#include <windows.h>
#include <time.h>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

class CashValueMenager {

    int getYear(string date);
    int getDay(string date);
    bool isYearLeapYear(int year);
    int howManyDaysIsTheLastMonth();
    int howManyDaysIsTheCurrentMonth();

public:
    string getCurrentDate();
    int getMonth(string date);
    bool isDateCorrect(string date);
    string changeAmountToCorrect(string amount);
    void compareTheDates();
    float conversionStringToFloat(string num);
    int conversionDateToInteger(string date);
    string conversionDateToString(int date);
};

#endif
