#ifndef USERMENAGER_H
#define USERMENAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserMenager {

    int idNumberLoggedInUser;
    vector<User> users;
    FileWithUsers fileWithUsers;

    bool isLoginExists(string userLogin);
    User getDataOfNewUser();
    int getIdOfNewUser();

public:
    UserMenager(string nameOfFileWithUsers): fileWithUsers(nameOfFileWithUsers) {};
    void userRegistration();
    void listOfAllUsers();
    int userLogin();
    void logoutUser();
    bool isUserLoggedIn();
    void changePasswordOfLoggedInUser();
    void loadUsersFromFile();

};

#endif
