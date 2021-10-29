#include "FileWithExpenses.h"
#include "AccessoryMethods.h"
#include "CashValueMenager.h"
#include "Expense.h"
#include "Markup.h"

void FileWithExpenses::addExpenseToFile(Expense expense)
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", cashValueMenager.conversionDateToString(expense.getDate()));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", expense.getAmount());

    xml.Save(getFileName());
}

string FileWithExpenses::conversionDateToString(int date)
{
    string dateInString;
    string year, month, day;

    dateInString = AccessoryMethods::conversionIntToString(date);

    year = dateInString.substr(0,4);

    month = dateInString.substr(4,2);

    if(month.size() == 1)
        month = "0" + month;

    day = dateInString.substr(6,2);

    if(day.size() == 1)
        day = "0" + day;

    dateInString = year + "-" +month + "-" + day;

    return dateInString;
}

vector<Expense> FileWithExpenses::loadExpensesFromFile(int ID_NUMBER_OF_LOGGED_IN_USER)
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    Expense expense;
    int date;
    float amount;

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    if (fileExists)
    {
        while ( xml.FindElem("Expense") )
        {
        xml.IntoElem();
        xml.FindElem("ExpenseId");
        expense.setExpenseId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem("UserId");
        expense.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Date");
        date = cashValueMenager.conversionDateToInteger(xml.GetData());
        expense.setDate(date);
        xml.FindElem("Item");
        expense.setItem(xml.GetData());
        xml.FindElem("Amount");
        amount = cashValueMenager.conversionStringToFloat(xml.GetData());
        expense.setAmount(amount);
        expenses.push_back(expense);
        xml.OutOfElem();
        }
    }
    else
        cout << "Blad pliku!" << endl;

    return expenses;
}
