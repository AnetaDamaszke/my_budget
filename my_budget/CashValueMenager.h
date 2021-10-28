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

    const int ID_NUMBER_OF_LOGGED_IN_USER;

    int getYear(string date);
    int getMonth(string date);
    int getDay(string date);
    string getCurrentDate();
    string getDateInTheSpecifiedFormat();
    bool isYearLeapYear(int year);
    int howManyDaysIsTheLastMonth();
    int howManyDaysIsTheCurrentMonth();

public:
    CashValueMenager(int idNumberOfLoggedInUser): ID_NUMBER_OF_LOGGED_IN_USER(idNumberOfLoggedInUser) {};

    bool isDateCorrect(string date);
    string changeAmountToCorrect(string amount);
    void compareTheDates();
    float conversionStringToFloat(string num);
    int conversionDateToInteger(string date);
    string conversionDateToString(int date);
};

#endif
