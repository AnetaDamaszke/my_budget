#include <iostream>

#include "MyBudget.h"
#include "FileWithUsers.h"
#include "UserMenager.h"
#include "IncomeMenager.h"

using namespace std;

int main()
{
    MyBudget myBudget("users.xml", "incomes.xml");

    myBudget.userLogin();
    myBudget.addNewIncome();
    myBudget.addNewIncome();
    myBudget.addNewIncome();
    myBudget.displayIncomes();

    return 0;
}
