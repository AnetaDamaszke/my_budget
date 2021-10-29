#include "MyBudget.h"
#include "AccessoryMethods.h"

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
        incomeMenager = new IncomeMenager(NAME_OF_FILE_WITH_INCOMES, userMenager.getIdNumberOfLoggedInUser());
        expenseMenager = new ExpenseMenager(NAME_OF_FILE_WITH_EXPENSES, userMenager.getIdNumberOfLoggedInUser());
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

void MyBudget::addNewExpense()
{
    if(userMenager.isUserLoggedIn())
    {
        expenseMenager->addNewExpense();
    }
    else
        cout << "Aby dodac przychod nalezy sie zalogowac" << endl;
}

char MyBudget::selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AccessoryMethods::getSign();
    cout << endl;

    return choice;
}

char MyBudget::selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj nowy przychod" << endl;
    cout << "2. Dodaj nowy wydatek" << endl;
    cout << "3. Pokaz bilans z biezacego miesiaca" << endl;
    cout << "4. Pokaz bilans z poprzedniego miesiaca" << endl;
    cout << "5. Pokaz bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AccessoryMethods::getSign();
    cout << endl;

    return choice;
}
