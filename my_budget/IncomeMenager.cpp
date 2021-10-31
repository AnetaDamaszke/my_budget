#include "IncomeMenager.h"
#include "CashValueMenager.h"
#include "AccessoryMethods.h"

void IncomeMenager::addNewIncome()
{
    Income income = getDataOfNewIncome();

    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);

    cout << "Przychod dodany pomyslnie." << endl;
    system("pause");
}

Income IncomeMenager::getDataOfNewIncome()
{
    Income income;

    income.setIncomeId(getIdOfNewIncome());
    income.setUserId(getIdNumberOfLoggedInUser());

    string date, item, amount;
    float amountFl;
    int dateInt;

    cout << "Podaj date przychodu w formacie RRRR-MM-DD: ";
    date = AccessoryMethods::getLine();

    if(isDateCorrect(date))
    {
        dateInt = conversionDateToInteger(date);
        income.setDate(dateInt);
    }

    cout << "Podaj nazwe przychodu: ";
    item = AccessoryMethods::getLine();
    income.setItem(item);

    cout << "Podaj wartosc przychodu: ";
    amount = AccessoryMethods::getLine();
    amount = changeAmountToCorrect(amount);
    amountFl = conversionStringToFloat(amount);
    income.setAmount(amountFl);

    return income;
}

void IncomeMenager::displayAllIncomes()
{
    sort(incomes.begin(), incomes.end());

    cout << "PRZYCHODY:" << endl;
    for(int i=0; i<incomes.size(); i++)
    {
        cout << incomes[i].getAmount() << " - " << incomes[i].getItem() << endl;
    }
}

int IncomeMenager::getIdOfNewIncome()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

int IncomeMenager::getIdNumberOfLoggedInUser()
{
    return ID_NUMBER_OF_LOGGED_IN_USER;
}

//float IncomeMenager::sumIncomes()
//{
//    float sumIncomes = 0;
//
//    for(int i=0; i<incomes.size(); i++)
//    {
//        sumIncomes += incomes[i].getAmount();
//    }
//
//    return sumIncomes;
//}

void IncomeMenager::sortIncomesByDate()
{
    sort(incomes.begin(), incomes.end());
}

float IncomeMenager::getIncomesFromCurrenthMonth()
{
    float sumIncomes = 0;
    string currentDate = getCurrentDate();
    int currentMonth = getMonth(currentDate);

    sort(incomes.begin(), incomes.end());

    for(int i=0; i < incomes.size(); i++)
    {
        string incomeDate = conversionDateToString(incomes[i].getDate());

        int incomeMonth = getMonth(incomeDate);

        if(incomeMonth == currentMonth)
        {
            cout << incomes[i].getAmount() << " - " << incomes[i].getItem() << endl;
            sumIncomes += incomes[i].getAmount();
        }
    }
    return sumIncomes;
}

float IncomeMenager::getIncomesFromLastMonth()
{
    float sumIncomes = 0;
    string currentDate = getCurrentDate();
    int lastMonth = getMonth(currentDate) - 1;

    if(getMonth(currentDate) == 1)
    {
        lastMonth = 12;
    }

    sortIncomesByDate();

    for(int i=0; i < incomes.size(); i++)
    {
        string incomeDate = conversionDateToString(incomes[i].getDate());
        int incomeMonth = getMonth(incomeDate);

        if(incomeMonth == lastMonth)
        {
            cout << incomes[i].getAmount() << " - " << incomes[i].getItem() << endl;
            sumIncomes += incomes[i].getAmount();
        }
    }
    return sumIncomes;
}

float IncomeMenager::getIncomesFromSelectedDate(string firstDateStr, string secondDateStr)
{
    float sumIncomes;

    int firstDate = conversionDateToInteger(firstDateStr);
    int secondDate = conversionDateToInteger(secondDateStr);

    sortIncomesByDate();

    for(int i=0; i < incomes.size(); i++)
    {
        int incomeDate = incomes[i].getDate();

        if((incomeDate >= firstDate) && (incomeDate <= secondDate))
        {
            cout << incomes[i].getAmount() << " - " << incomes[i].getItem() << " - " << conversionDateToString(incomes[i].getDate()) << endl;
            sumIncomes += incomes[i].getAmount();
        }
    }
    return sumIncomes;
}
