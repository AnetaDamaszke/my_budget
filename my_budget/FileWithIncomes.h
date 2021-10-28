#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "XmlFile.h"

using namespace std;

class FileWithIncomes : public XmlFile {

    int idNumberLastIncome;
    vector<Income> incomes;

public:
    FileWithIncomes(string fileName): XmlFile(fileName)
    {
        idNumberLastIncome = 0;
    };
    void addIncomeToFile(Income income);
    vector<Income> loadIncomesFromFile();
    string conversionDateToString(int date);
};

#endif
