#include "MyBudget.h"

void MyBudget::userRegistration()
{
    userMenager.userRegistration();
}

void MyBudget::listOfAllUsers()
{
    userMenager.listOfAllUsers();
}

int MyBudget::userLogin()
{
    userMenager.userLogin();
    if(userMenager.isUserLoggedIn())
    {
        incomeMenager = new IncomeMenager(userMenager.getIdNumberOfLoggedInUser());
    }
}

void MyBudget::logoutUser()
{
    userMenager.logoutUser();
}

bool MyBudget::isUserLoggedIn()
{
    userMenager.isUserLoggedIn();
}

void MyBudget::changePasswordOfLoggedInUser()
{
    userMenager.changePasswordOfLoggedInUser();
}

void MyBudget::addNewIncome()
{
    if(userMenager.isUserLoggedIn())
    {
        incomeMenager->addNewIncome();
    }
    else
        cout << "Aby dodac przychod nalezy sie zalogowac" << endl;

}
