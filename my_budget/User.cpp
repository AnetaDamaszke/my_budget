#include "User.h"

void User::setUserId(int newUserId) {
    userId = newUserId;
}

void User::setUserLogin(string newUserLogin) {
    userLogin = newUserLogin;
}

void User::setUserPassword(string newUserPassword) {
    userPassword = newUserPassword;
}

void User::setUserName(string newUserName) {
    userName = newUserName;
}

void User::setUserSurname(string newUserSurname) {
    userSurname = newUserSurname;
}

int User::getUserId() {
    return userId;
}

string User::getUserLogin() {
    return userLogin;
}

string User::getUserPassword() {
    return userPassword;
}

string User::getUserName() {
    return userName;
}

string User::getUserSurname() {
    return userSurname;
}
