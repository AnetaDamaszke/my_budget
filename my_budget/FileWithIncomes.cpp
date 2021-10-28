#include "FileWithIncomes.h"

//void FileWithIncomes::addIncomeToFile()
//{
//    CMarkup xml;
//
//    int idNumber = ++ lastIdIncome;
//    float amount = 0;
//    string date = "", item = "";
//
//    bool fileExists = xml.Load( "incomes.xml" );
//
//    if (!fileExists)
//    {
//        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
//        xml.AddElem("Income");
//    }
//
//    cout << "Podaj date przychodu: ";
//    cin >> date;
//
//    cout << "Podaj nazwe przychodu: ";
//    cin >> item;
//
//    cout << "Podaj wartosc: ";
//    cin >> amount;
//
//    xml.FindElem();
//    xml.IntoElem();
//    xml.AddElem("Income");
//    xml.IntoElem();
//    xml.AddElem("IncomeId", idNumber);
//    xml.AddElem("UserId", userId);
//    xml.AddElem("Date", date);
//    xml.AddElem("Item", item);
//    xml.AddElem("Amount", amount);
//
//    xml.Save("money.xml");
//}
