#include "User.h"

void setUserId(int newUserId) {
    userId = newUserId;
}

void setUserLogin(string newUserLogin) {
    userLogin = newUserLogin;
}

void setUserPassword(string newUserPassword) {
    userPassword = newUserPassword;
}

void setUserName(string newUserName) {
    userName = newUserName;
}

void setUserSurname(string newUserSurname) {
    userSurname = newUserSurname;
}

int getUserId() {
    return userId;
}

string getUserLogin() {
    return userLogin;
}

string getUserPassword() {
    return userPassword;
}

string getUserName() {
    return userName;
}

string getUserSurname() {
    return userSurname;
}
