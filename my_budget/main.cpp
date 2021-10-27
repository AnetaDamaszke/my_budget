#include <iostream>

#include "MyBudget.h"

using namespace std;

int main()
{
    MyBudget myBudget("users.xml");

    myBudget.userRegistration();
    myBudget.userRegistration();
    myBudget.userRegistration();
    myBudget.listOfAllUsers();

    return 0;
}
