#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "XmlFile.h"
#include "CashValueMenager.h"

using namespace std;

class FileWithExpenses : public XmlFile {

    int idNumberLastExpense;
    vector<Expense> expenses;
    CashValueMenager cashValueMenager;

public:
    FileWithExpenses(string fileName): XmlFile(fileName)
    {
        idNumberLastExpense = 0;
    };
    void addExpenseToFile(Expense expense);
    vector<Expense> loadExpensesFromFile(int ID_NUMBER_OF_LOGGED_IN_USER);
    string conversionDateToString(int date);
};

#endif
