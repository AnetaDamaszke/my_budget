#include <iostream>

#include "MyBudget.h"
#include "FileWithUsers.h"
#include "UserMenager.h"
#include "IncomeMenager.h"

using namespace std;

int main()
{
    //MyBudget myBudget("users.xml", "incomes.xml");
    IncomeMenager incomeMenager("incomes.xml", 1);

    incomeMenager.sortIncomesByDate();

    return 0;
}
