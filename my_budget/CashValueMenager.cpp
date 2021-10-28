#include "CashValueMenager.h"
#include "AccessoryMethods.h"

bool CashValueMenager::isYearLeapYear(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

int CashValueMenager::howManyDaysIsTheCurrentMonth()
{
    int howManyDays;

    int year = getYear(getCurrentDate());
    int month = getMonth(getCurrentDate());

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

int CashValueMenager::howManyDaysIsTheLastMonth()
{
    int howManyDays;

    int year = getYear(getCurrentDate());
    int month;

    if(getMonth(getCurrentDate()) == 1)
        month = 12;
    else
        month = getMonth(getCurrentDate()) - 1;

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

void CashValueMenager::compareTheDates()
{
    string firstDateInTheSpecifiedFormat, secondDateInTheSpecifiedFormat;

    cout << "Podaj pierwsza date w formacie RRRR-MM-DD: ";
    cin >> firstDateInTheSpecifiedFormat;
    cout << "Podaj druga date w formacie RRRR-MM-DD: ";
    cin >> secondDateInTheSpecifiedFormat;

    int year1 = getYear(firstDateInTheSpecifiedFormat);
    int month1 = getMonth(firstDateInTheSpecifiedFormat);
    int day1 = getDay(firstDateInTheSpecifiedFormat);
    int year2 = getYear(secondDateInTheSpecifiedFormat);
    int month2 = getMonth(secondDateInTheSpecifiedFormat);
    int day2 = getDay(secondDateInTheSpecifiedFormat);

    if( year1 > year2)
    {
        cout << "Wczeniejsza jest data " << secondDateInTheSpecifiedFormat << endl;
    }
    else if( year1 == year2)
    {
        if(month1 > month2)
            cout << "Wczeniejsza jest data " << secondDateInTheSpecifiedFormat << endl;
        else if(month1 == month2)
        {
            if(day1 > day2)
                cout << "Wczeniejsza jest data " << secondDateInTheSpecifiedFormat << endl;
            else
                cout << "Wczeniejsza jest data " << firstDateInTheSpecifiedFormat << endl;
        }
        else
            cout << "Wczeniejsza jest data " << firstDateInTheSpecifiedFormat << endl;
    }
    else
        cout << "Wczeniejsza jest data " << firstDateInTheSpecifiedFormat << endl;
}

string CashValueMenager::getDateInTheSpecifiedFormat()
{
    string dateInTheSpecifiedFormat;

    cout << "Podaj date w formacie RRRR-MM-DD: ";
    cin >> dateInTheSpecifiedFormat;

    return dateInTheSpecifiedFormat;
}

int CashValueMenager::getYear(string date)
{
    int year;

    year = AccessoryMethods::conversionStringToInt(date.substr(0,4));

    return year;
}

int CashValueMenager::getMonth(string date)
{
    string monthStr;
    int month;

    monthStr = date.substr(5,2);

    if( monthStr[0] == '0')
    {
        monthStr = monthStr.substr(1,1);
    }

    month = AccessoryMethods::conversionStringToInt(monthStr);

    return month;
}

int CashValueMenager::getDay(string date)
{
    string dayStr;
    int day;

    dayStr = date.substr(8,2);

    if( dayStr[0] == '0')
    {
        dayStr = dayStr.substr(1,1);
    }

    day = AccessoryMethods::conversionStringToInt(dayStr);

    return day;
}

string CashValueMenager::getCurrentDate()
{
    string currentDate;

    SYSTEMTIME st;
    GetSystemTime(&st);

    string currentYear, currentMonth, currentDay;

    currentYear = AccessoryMethods::conversionIntToString(st.wYear);
    currentMonth = AccessoryMethods::conversionIntToString(st.wMonth);

    if(st.wMonth < 10)
        currentMonth = "0" + currentMonth;

    currentDay = AccessoryMethods::conversionIntToString(st.wDay);

    if(st.wDay < 10)
        currentMonth = "0" + currentMonth;

    currentDate = currentYear + "-" + currentMonth + "-" + currentDay;

    return currentDate;
}

string CashValueMenager::changeAmountToCorrect(string amount)
{
    for(int i; i < amount.size(); i++)
    {
        if(amount[i] == ',')
        {
            amount[i] = '.';
        }
    }

    return amount;
}

float CashValueMenager::conversionStringToFloat(string num)
{
    float amount = atof(num.c_str());

    return amount;
}

bool CashValueMenager::isDateCorrect(string date)
{
    int year = getYear(date);
    int month = getMonth(date);

    int currentYear = getYear(getCurrentDate());
    int currentMonth = getMonth(getCurrentDate());

    if((year < 2000))
    {
        cout << "Bledna data. Podaj date po 2000-01-01" << endl;
        return false;
    }
    else if(year > currentYear)
    {
        cout << "Bledna data. Podaj date przed ostatnim dniem biezaego miesiaca." << endl;
        return false;
    }
    else if((year == currentYear) && (month > currentMonth))
    {
        cout << "Bledna data. Podaj date przed ostatnim dniem biezaego miesiaca." << endl;
        return false;
    }
    else
        return true;
}

int CashValueMenager::conversionDateToInteger(string date)
{
    int dateInInteger;

    string dateInNewFormat;
    string dayStr, monthStr, yearStr;

    dayStr = date.substr(8,2);

    if( dayStr[0] == '0')
    {
        dayStr = dayStr.substr(1,1);
    }

    monthStr = date.substr(5,2);

    if( monthStr[0] == '0')
    {
        monthStr = monthStr.substr(1,1);
    }

    yearStr = date.substr(0,4);

    if(isDateCorrect(date) == true)
    {
        dateInNewFormat = yearStr + monthStr + dayStr;
    }
    else
        cout << "Bledna data";

    dateInInteger = AccessoryMethods::conversionStringToInt(dateInNewFormat);

    return dateInInteger;
}
