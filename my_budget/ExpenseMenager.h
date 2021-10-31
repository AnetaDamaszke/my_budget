#ifndef EXPENSEMENAGER_H
#define EXPENSEMENAGER_H

#include <iostream>
#include <vector>

#include "CashValueMenager.h"
#include "FileWithExpenses.h"
#include "Expense.h"

using namespace std;

class ExpenseMenager : public CashValueMenager {

    const int ID_NUMBER_OF_LOGGED_IN_USER;
    vector<Expense> expenses;
    FileWithExpenses fileWithExpenses;

    Expense getDataOfNewExpense();
    int getIdOfNewExpense();
    int getIdNumberOfLoggedInUser();

public:
    ExpenseMenager(string nameOfFileWithExpenses, int idNumberOfLoggedInUser): fileWithExpenses(nameOfFileWithExpenses), ID_NUMBER_OF_LOGGED_IN_USER(idNumberOfLoggedInUser)
    {
        expenses = fileWithExpenses.loadExpensesFromFile(ID_NUMBER_OF_LOGGED_IN_USER);
    };
    void addNewExpense();
    void displayAllExpenses();
    //float sumExpenses();
    void sortExpensesByDate();
    float getExpensesFromCurrenthMonth();
    float getExpensesFromLastMonth();
    float getExpensesFromSelectedDate(string firstDate, string secondDate);
};

#endif
