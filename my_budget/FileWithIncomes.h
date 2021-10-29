#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "XmlFile.h"
#include "CashValueMenager.h"

using namespace std;

class FileWithIncomes : public XmlFile {

    int idNumberLastIncome;
    vector<Income> incomes;
    CashValueMenager cashValueMenager;

public:
    FileWithIncomes(string fileName): XmlFile(fileName)
    {
        idNumberLastIncome = 0;
    };
    void addIncomeToFile(Income income);
    vector<Income> loadIncomesFromFile(int ID_NUMBER_OF_LOGGED_IN_USER);
};

#endif
