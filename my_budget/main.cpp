#include <iostream>

#include "MyBudget.h"
#include "FileWithUsers.h"
#include "UserMenager.h"

using namespace std;

int main()
{
    MyBudget myBudget("users.xml");

    myBudget.userLogin();
    myBudget.changePasswordOfLoggedInUser();

    return 0;
}
