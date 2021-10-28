#include "IncomeMenager.h"
#include "CashValueMenager.h"
#include "AccessoryMethods.h"

void IncomeMenager::addNewIncome()
{
    Income income = getDataOfNewIncome();

    incomes.push_back(income);
    //fileWithIncomes.addIncomeToFile(income);

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
    amount = AccessoryMethods::getNumber();
    amount = changeAmountToCorrect(amount);
    amountFl = conversionStringToFloat(amount);
    income.setAmount(amountFl);

    return income;
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
    return idNumberOfLoggedInUser;
}
