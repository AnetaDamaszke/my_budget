#include <iostream>

#include "MyBudget.h"
#include "AccessoryMethods.h"

using namespace std;

int main()
{
    MyBudget myBudget("users.xml", "incomes.xml", "expenses.xml");

    char choice;

    while (true)
    {
        if (!myBudget.isUserLoggedIn())
        {
            choice = myBudget.selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                myBudget.userRegistration();
                break;
            case '2':
                myBudget.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = myBudget.selectOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                myBudget.addNewIncome();
                break;
            case '2':
                myBudget.addNewExpense();
                break;
            case '3':
                myBudget.displayBalanceSheetForCurrentMonth();
                break;
            case '4':
                myBudget.displayBalanceSheetForLastMonth();
                break;
            case '5':
                myBudget.displayBalanceSheetForSelectedDate();
                break;
            case '6':
                myBudget.changePasswordOfLoggedInUser();
                break;
            case '7':
                myBudget.logoutUser();
                break;
            }
        }
    }

    return 0;
}
