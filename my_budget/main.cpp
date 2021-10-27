#include <iostream>

#include "MyBudget.h"
#include "FileWithUsers.h"
#include "UserMenager.h"

using namespace std;

int main()
{
    MyBudget myBudget("users.xml");
    FileWithUsers fileWithUsers("users.xml");

    fileWithUsers.loadUsersFromFile();
    myBudget.listOfAllUsers();

    return 0;
}
