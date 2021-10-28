#include <iostream>

#include "MyBudget.h"
#include "FileWithUsers.h"
#include "UserMenager.h"
#include "IncomeMenager.h"

using namespace std;

int main()
{
    MyBudget myBudget("users.xml");

    myBudget.userLogin();
    myBudget.addNewIncome();

    return 0;
}
