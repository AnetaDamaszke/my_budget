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

void ExpenseMenager::displayAllExpenses()
{
    sort(expenses.begin(), expenses.end());

    cout << "WYDATKI:" << endl;
    for(int i=0; i<expenses.size(); i++)
    {
        cout << expenses[i].getAmount() << " - " << expenses[i].getItem() << endl;
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

void ExpenseMenager::sortExpensesByDate()
{
    sort(expenses.begin(), expenses.end());
}

float ExpenseMenager::getExpensesFromCurrenthMonth()
{
    float sumExpenses;
    string currentDate = getCurrentDate();
    int currentMonth = getMonth(currentDate);

    sortExpensesByDate();

    for(int i=0; i < expenses.size(); i++)
    {
        string expenseDate = conversionDateToString(expenses[i].getDate());

        int expenseMonth = getMonth(expenseDate);

        if(expenseMonth == currentMonth)
        {
            cout << expenses[i].getAmount() << " - " << expenses[i].getItem() << endl;
            sumExpenses += expenses[i].getAmount();
        }
    }

    return sumExpenses;
}

float ExpenseMenager::getExpensesFromLastMonth()
{
    float sumExpenses;
    string currentDate = getCurrentDate();
    int lastMonth = getMonth(currentDate) - 1;

    if(getMonth(currentDate) == 1)
    {
        lastMonth = 12;
    }

    sortExpensesByDate();

    for(int i=0; i < expenses.size(); i++)
    {
        string expenseDate = conversionDateToString(expenses[i].getDate());

        int expenseMonth = getMonth(expenseDate);

        if(expenseMonth == lastMonth)
        {
            cout << expenses[i].getAmount() << " - " << expenses[i].getItem() << endl;
            sumExpenses += expenses[i].getAmount();
        }
    }

    return sumExpenses;
}

float ExpenseMenager::getExpensesFromSelectedDate(string firstDateStr, string secondDateStr)
{
    float sumExpenses;

    int firstDate = conversionDateToInteger(firstDateStr);
    int secondDate = conversionDateToInteger(secondDateStr);

    sortExpensesByDate();

    for(int i=0; i < expenses.size(); i++)
    {
        int expenseDate = expenses[i].getDate();

        if((expenseDate >= firstDate) && (expenseDate <= secondDate))
        {
            cout << expenses[i].getAmount() << " - " << expenses[i].getItem() << " - " << conversionDateToString(expenses[i].getDate()) << endl;
            sumExpenses += expenses[i].getAmount();
        }
    }

    return sumExpenses;
}
