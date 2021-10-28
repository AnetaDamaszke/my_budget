#include "UserMenager.h"
#include "AccessoryMethods.h"

void UserMenager::userRegistration() {

    User user = getDataOfNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");

}

User UserMenager::getDataOfNewUser() {

    User user;

    user.setUserId(getIdOfNewUser());

    string name;

    cout << "Podaj imie: ";
    name = AccessoryMethods::getLine();
    name = AccessoryMethods::changeFirstLetterToCapitalLetterAndOtherToSmall(name);
    user.setUserName(name);

    string surname;

    cout << "Podaj nazwisko: ";
    surname = AccessoryMethods::getLine();
    surname = AccessoryMethods::changeFirstLetterToCapitalLetterAndOtherToSmall(surname);
    user.setUserSurname(surname);

    string login;

    do
    {
        cout << "Podaj login: ";
        login = AccessoryMethods::getLine();
        user.setUserLogin(login);
    } while (isLoginExists(user.getUserLogin()) == true);

    string password;

    cout << "Podaj haslo: ";
    password = AccessoryMethods::getLine();
    user.setUserPassword(password);

    return user;
}

int UserMenager::getIdOfNewUser() {

    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;

}

bool UserMenager::isLoginExists(string userLogin)
{
    for(int i=0; i<users.size(); i++)
    {
        if(users[i].getUserLogin() == userLogin)
        {
           cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
        }
    }
    return false;
}

void UserMenager::listOfAllUsers() {

    for(int i=0; i<users.size(); i++) {
        cout << users[i].getUserId() << endl;
        cout << users[i].getUserName() << endl;
        cout << users[i].getUserSurname() << endl;
        cout << users[i].getUserLogin() << endl;
        cout << users[i].getUserPassword() << endl;
        cout << endl;
    }
}

int UserMenager::userLogin()
{
    User user;
    string login = "", password = "";

    cout << "Podaj login: ";
    login = AccessoryMethods::getLine();

    for(int i=0; i<users.size(); i++)
    {
        if (users[i].getUserLogin() == login)
        {
            for (int test = 3; test > 0; test--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << test << ": ";
                password = AccessoryMethods::getLine();

                if (users[i].getUserPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idNumberLoggedInUser = users[i].getUserId();
                    return idNumberLoggedInUser;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UserMenager::logoutUser() {
    idNumberLoggedInUser = 0;
}
bool UserMenager::isUserLoggedIn() {
    if (idNumberLoggedInUser > 0)
        return true;
    else
        return false;
}

int UserMenager::getIdNumberOfLoggedInUser() {
    return idNumberLoggedInUser;
}

void UserMenager::changePasswordOfLoggedInUser() {

    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AccessoryMethods::getLine();

    for(int i=0; i<users.size(); i++)
    {
        if (users[i].getUserId() == getIdNumberOfLoggedInUser())
        {
            users[i].setUserPassword(newPassword);
            fileWithUsers.saveNewPasswordInFile(users[i]);
            cout << "Haslo zostalo zmienione." << endl << endl;
        }
    }
}
