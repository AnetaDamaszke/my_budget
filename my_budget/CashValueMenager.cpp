#include "CashValueMenager.h"
#include "AccessoryMethods.h"

bool CashValueMenager::isYearLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int CashValueMenager::getNumberDaysInMonth(string date)
{
    int howManyDays;

    int year = getYear(date);
    int month = getMonth(date);

    if (month == 4 || month == 6 || month == 9 || month == 11)
        howManyDays = 30;
    else if (month == 02)
    {
        bool leapYear = isYearLeapYear(year);

        if (!leapYear)
                howManyDays = 28;
        else
                howManyDays = 29;
    }
    else
    howManyDays = 31;

    return howManyDays;
}

int CashValueMenager::getYear(string date)
{
    return AccessoryMethods::conversionStringToInt(date.substr(0,4));
}

int CashValueMenager::getMonth(string date)
{
    string monthStr = date.substr(5,2);

    if( monthStr[0] == '0')
        monthStr = monthStr.substr(1,1);

    return AccessoryMethods::conversionStringToInt(monthStr);
}

int CashValueMenager::getDay(string date)
{
    string dayStr = date.substr(8,2);

    if( dayStr[0] == '0')
        dayStr = dayStr.substr(1,1);

    return AccessoryMethods::conversionStringToInt(dayStr);
}

string CashValueMenager::getCurrentDate()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    string currentYear = AccessoryMethods::conversionIntToString(st.wYear);
    string currentMonth = AccessoryMethods::conversionIntToString(st.wMonth);
    string currentDay = AccessoryMethods::conversionIntToString(st.wDay);

    if(st.wMonth <= 9)
        currentMonth = "0" + currentMonth;

    if(st.wDay <= 9)
        currentDay = "0" + currentDay;

    return (currentYear + "-" + currentMonth + "-" + currentDay);
}

string CashValueMenager::changeAmountToCorrect(string amount)
{
    for(int i = 0; i < amount.size(); i++)
    {
        if(amount[i] == ',')
            amount[i] = '.';
    }

    return amount;
}

float CashValueMenager::conversionStringToFloat(string num)
{
    return atof(num.c_str());
}

bool CashValueMenager::isDateCorrect(string date)
{
    int year = getYear(date);
    int month = getMonth(date);
    int day = getDay(date);

    int currentYear = getYear(getCurrentDate());
    int currentMonth = getMonth(getCurrentDate());
    int numberDaysInMonth = getNumberDaysInMonth(date);

    if((year < 2000))
    {
        cout << "Bledna data. Podaj date po 2000-01-01" << endl;
        return false;
    }
    else if((year == currentYear) && (month > currentMonth))
    {
        cout << "Bledna data. Podaj date przed ostatnim dniem biezaego miesiaca." << endl;
        return false;
    }
    else if(day > numberDaysInMonth)
    {
        cout << "Bledna data. Podaj poprawna date." << endl;
        return false;
    }
    else if((date[4] != '-') || (date[7] != '-'))
    {
        cout << "Bledny format daty. Sprobuj jeszcze raz." << endl;
        return false;
    }
    return true;
}

int CashValueMenager::conversionDateToInteger(string date)
{
    string dateInNewFormat;
    string dayStr, monthStr, yearStr;

    dayStr = date.substr(8,2);
    monthStr = date.substr(5,2);
    yearStr = date.substr(0,4);

    dateInNewFormat = yearStr + monthStr + dayStr;

    return AccessoryMethods::conversionStringToInt(dateInNewFormat);
}

string CashValueMenager::conversionDateToString(int date)
{
    string dateInString;
    string year, month, day;

    dateInString = AccessoryMethods::conversionIntToString(date);

    year = dateInString.substr(0,4);
    month = dateInString.substr(4,2);
    day = dateInString.substr(6,2);

    dateInString = year + "-" + month + "-" + day;

    return dateInString;
}
