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
    UserMenager(string nameOfFileWithUsers): fileWithUsers(nameOfFileWithUsers) {
        idNumberLoggedInUser = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    void userRegistration();
    void listOfAllUsers();
    void loadUsersFromFile();
    int userLogin();
    void logoutUser();
    bool isUserLoggedIn();
    void changePasswordOfLoggedInUser();


};

#endif
