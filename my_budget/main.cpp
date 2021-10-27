#include <iostream>

#include "MyBudget.h"

using namespace std;

int main()
{
    MyBudget myBudget("users.xml");

    myBudget.userRegistration();

    return 0;
}
