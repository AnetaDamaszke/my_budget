#include <iostream>

#include "MyBudget.h"
#include "FileWithUsers.h"
#include "UserMenager.h"
#include "IncomeMenager.h"

using namespace std;

int main()
{
    //MyBudget myBudget("users.xml", "incomes.xml");
    ExpenseMenager expenseMenager("expenses.xml", 1);

    expenseMenager.addNewExpense();

    return 0;
}
