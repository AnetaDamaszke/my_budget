#include "FileWithIncomes.h"
#include "AccessoryMethods.h"
#include "Income.h"
#include "Markup.h"

void FileWithIncomes::addIncomeToFile(Income income)
{
    CMarkup xml;

    string date = conversionDateToString(income.getDate());

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

    xml.Save(getFileName());


}

string FileWithIncomes::conversionDateToString(int date)
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
