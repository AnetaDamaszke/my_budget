#include "UserMenager.h"
#include "Markup.h"

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
    cin >> name;
    user.setUserName(name);

    string surname;

    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setUserSurname(surname);

    string login;

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setUserLogin(login);
    } while (isLoginExists(user.getUserLogin()) == true);

    string password;

    cout << "Podaj haslo: ";
    cin >> password;
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

//void UserMenager::loadUsersFromFile() {
//
//    CMarkup xml;
//
//    bool fileExists = xml.Load(getFileName());
//
//    User user;
//    vector<User> users;
//
//    xml.ResetPos();
//    xml.FindElem();
//    xml.IntoElem();
//
//    if (fileExists)
//    {
//        while ( xml.FindElem("User") )
//        {
//        xml.IntoElem();
//        xml.FindElem( "UserId");
//        user.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
//        xml.FindElem( "Login");
//        user.setUserLogin(xml.GetData());
//        xml.FindElem( "Password");
//        user.setUserPassword(xml.GetData());
//        xml.FindElem( "Name");
//        user.setUserName(xml.GetData());
//        xml.FindElem( "Surname");
//        user.setUserSurname(xml.GetData());
//        users.push_back(user);
//        xml.OutOfElem();
//        }
//    }
//    else
//        cout << "Blad pliku!" << endl;
//
//    cout << users.size() << endl;
//}

//int UserMenager::logowanieUzytkownika()
//{
//    Uzytkownik uzytkownik;
//    string login = "", haslo = "";
//
//    cout << "Podaj login: ";
//    login = MetodyPomocnicze::wczytajLinie();
//
//    for(int i=0; i<uzytkownicy.size(); i++)
//    {
//        if (uzytkownicy[i].pobierzLogin() == login)
//        {
//            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
//            {
//                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
//                haslo = MetodyPomocnicze::wczytajLinie();
//
//                if (uzytkownicy[i].pobierzHaslo() == haslo)
//                {
//                    cout << endl << "Zalogowales sie." << endl << endl;
//                    system("pause");
//                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
//                    return idZalogowanegoUzytkownika;
//                }
//            }
//            cout << "Wprowadzono 3 razy bledne haslo." << endl;
//            system("pause");
//            return 0;
//        }
//    }
//    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
//    system("pause");
//    return 0;
//}
//
//void UserMenager::zmianaHaslaZalogowanegoUzytkownika() {
//
//    Uzytkownik uzytkownik;
//    string noweHaslo = "";
//    cout << "Podaj nowe haslo: ";
//    noweHaslo = MetodyPomocnicze::wczytajLinie();
//
//    for(int i=0; i<uzytkownicy.size(); i++)
//    {
//        if (uzytkownicy[i].pobierzId() == pobierzIdZalogowanegoUzytkownika())
//        {
//            uzytkownicy[i].ustawHaslo(noweHaslo);
//            cout << "Haslo zostalo zmienione." << endl << endl;
//            system("pause");
//        }
//    }
//
//    plikZuzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
//}
//
//void UserMenager::wylogujUzytkownika() {
//    idZalogowanegoUzytkownika = 0;
//    adresaci.clear();
//}
//bool UserMenager::czyUzytkownikJestZalogowany() {
//    if (idZalogowanegoUzytkownika > 0)
//        return true;
//    else
//        return false;
//}
//
//int UserMenager::pobierzIdZalogowanegoUzytkownika() {
//    return idZalogowanegoUzytkownika;
//}
