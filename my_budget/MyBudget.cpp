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

void MyBudget::displayBalanceSheetForCurrentMonth()
{
    float sumIncomes, sumExpenses;

    system("cls");
    cout << ">>BILANS Z BIEZACEGO MIESIACA<< " << endl;
    cout << "-------------------------------" << endl;
    cout << "PRZYCHODY:" << endl;
    sumIncomes = incomeMenager->getIncomesFromCurrenthMonth();
    cout << endl;
    cout << "WYDATKI:" << endl;
    sumExpenses = expenseMenager->getExpensesFromCurrenthMonth();
    cout << "-------------------------------" << endl;
    cout<< "Suma przychodow: " << sumIncomes << endl;
    cout<< "Suma wydatkow: " << sumExpenses << endl;
    cout << "-------------------------------" << endl;
    cout<< "Roznica: " << sumIncomes - sumExpenses << endl;
    cout << endl;
    system("pause");
}

void MyBudget::displayBalanceSheetForLastMonth()
{
    float sumIncomes, sumExpenses;

    system("cls");
    cout << ">>BILANS Z OSTATNIEGO MIESIACA<< " << endl;
    cout << "-------------------------------" << endl;
    cout << "PRZYCHODY:" << endl;
    sumIncomes = incomeMenager->getIncomesFromLastMonth();
    cout << endl;
    cout << "WYDATKI:" << endl;
    sumExpenses = expenseMenager->getExpensesFromLastMonth();
    cout << "-------------------------------" << endl;
    cout<< "Suma przychodow: " << sumIncomes << endl;
    cout<< "Suma wydatkow: " << sumExpenses << endl;
    cout << "-------------------------------" << endl;
    cout<< "Roznica: " << sumIncomes - sumExpenses << endl;
    cout << endl;
    system("pause");
}

void MyBudget::displayBalanceSheetForSelectedDate()
{
    float sumIncomes, sumExpenses;
    string firstDate, secondDate;

    system("cls");
    cout << "Podaj poczatkowa date w formacie RRRR-MM-DD: ";
    firstDate = AccessoryMethods::getLine();
    cout << "Podaj koncowa date w formacie RRRR-MM-DD: ";
    secondDate = AccessoryMethods::getLine();
    cout << endl;
    cout << ">>BILANS Z WYBRANGO OKRESU<< " << endl;
    cout << "-------------------------------" << endl;
    cout << "PRZYCHODY:" << endl;
    sumIncomes = incomeMenager->getIncomesFromSelectedDate(firstDate, secondDate);
    cout << endl;
    cout << "WYDATKI:" << endl;
    sumExpenses = expenseMenager->getExpensesFromSelectedDate(firstDate, secondDate);
    cout << "-------------------------------" << endl;
    cout<< "Suma przychodow: " << sumIncomes << endl;
    cout<< "Suma wydatkow: " << sumExpenses << endl;
    cout << "-------------------------------" << endl;
    cout<< "Roznica: " << sumIncomes - sumExpenses << endl;
    cout << endl;
    system("pause");
}
