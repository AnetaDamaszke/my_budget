#include "ExpenseMenager.h"
#include "CashValueMenager.h"
#include "AccessoryMethods.h"

void ExpenseMenager::addNewExpense()
{
    Expense expense = getDataOfNewExpense();

    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);

    cout << "Wydatek dodany pomyslnie." << endl;
    system("pause");
}

Expense ExpenseMenager::getDataOfNewExpense()
{
    Expense expense;

    expense.setExpenseId(getIdOfNewExpense());
    expense.setUserId(getIdNumberOfLoggedInUser());

    string date, item, amount;
    float amountFl;
    int dateInt;

    cout << "Podaj date wydatku w formacie RRRR-MM-DD: ";
    date = AccessoryMethods::getLine();

    if(isDateCorrect(date))
    {
        dateInt = conversionDateToInteger(date);
        expense.setDate(dateInt);
    }

    cout << "Podaj nazwe wydatku: ";
    item = AccessoryMethods::getLine();
    expense.setItem(item);

    cout << "Podaj wartosc wydatku: ";
    amount = AccessoryMethods::getLine();
    amount = changeAmountToCorrect(amount);
    amountFl = conversionStringToFloat(amount);
    expense.setAmount(amountFl);

    return expense;
}

void ExpenseMenager::displayExpenses()
{
    for(int i=0; i<expenses.size(); i++)
    {
        cout << expenses[i].getExpenseId() << endl;
        cout << expenses[i].getUserId() << endl;
        cout << fileWithExpenses.conversionDateToString(expenses[i].getDate()) << endl;
        cout << expenses[i].getItem() << endl;
        cout << expenses[i].getAmount() << endl;
        cout << endl;
    }
}

int ExpenseMenager::getIdOfNewExpense()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}

int ExpenseMenager::getIdNumberOfLoggedInUser()
{
    return ID_NUMBER_OF_LOGGED_IN_USER;
}

float ExpenseMenager::sumExpenses()
{
    float sumExpenses = 0;

    for(int i=0; i<expenses.size(); i++)
    {
        sumExpenses += expenses[i].getAmount();
    }

    return sumExpenses;
}

void ExpenseMenager::sortExpensesByDate()
{
    sort(expenses.begin(), expenses.end());

    for(int i=0; i < expenses.size(); i++)
    {
        cout << fileWithExpenses.conversionDateToString(expenses[i].getDate()) << ": " << expenses[i].getAmount() <<  " zl" << endl;
    }
}
