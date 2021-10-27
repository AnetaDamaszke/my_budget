#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {

    int userId;
    string userLogin;
    string userPassword;
    string userName;
    string userSurname;

public:
    void setUserId(int newUserId);
    void setUserLogin(string newUserLogin);
    void setUserPassword(string newUserPassword);
    void setUserName(string newUserName);
    void setUserSurname(string newUserSurname);

    int getUserId();
    string getUserLogin();
    string getUserPassword();
    string getUserName();
    string getUserSurname();
};

#endif
