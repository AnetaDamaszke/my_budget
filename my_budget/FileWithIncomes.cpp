#include "FileWithIncomes.h"
#include "AccessoryMethods.h"
#include "CashValueMenager.h"
#include "Income.h"
#include "Markup.h"

void FileWithIncomes::addIncomeToFile(Income income)
{
    CMarkup xml;

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
    xml.AddElem("Date", cashValueMenager.conversionDateToString(income.getDate()));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

    xml.Save(getFileName());
}

vector<Income> FileWithIncomes::loadIncomesFromFile(int ID_NUMBER_OF_LOGGED_IN_USER)
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    Income income;
    int loggedInUser;
    int date;
    float amount;

    if(fileExists)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();

        while( xml.FindElem("Income") )
        {
            xml.IntoElem();
            xml.FindElem("UserId");
            loggedInUser = atoi(MCD_2PCSZ(xml.GetData()));

            if(loggedInUser == ID_NUMBER_OF_LOGGED_IN_USER)
            {
                xml.FindElem("IncomeId");
                income.setIncomeId(atoi( MCD_2PCSZ(xml.GetData())));
                xml.FindElem("UserId");
                income.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Date");
                date = cashValueMenager.conversionDateToInteger(xml.GetData());
                income.setDate(date);
                xml.FindElem("Item");
                income.setItem(xml.GetData());
                xml.FindElem("Amount");
                amount = cashValueMenager.conversionStringToFloat(xml.GetData());
                income.setAmount(amount);
                incomes.push_back(income);
            }
            xml.OutOfElem();
        }
    }
    else
        cout << "Blad pliku!" << endl;

    return incomes;
}
