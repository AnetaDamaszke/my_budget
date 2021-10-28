#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "XmlFile.h"

using namespace std;

class FileWithIncomes : public XmlFile {

    int idNumerLastIncome;
    vector<Income> incomes;

public:
    FileWithIncomes();
    void addIncomeToFile();
    vector<Income> loadIncomesFromFile();
};

#endif
