#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "User.h"

using namespace std;

class FileWithUsers : public XmlFile {

    vector<User> users;

public:
    FileWithUsers(string fileName): XmlFile(fileName) {};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();

};


#endif
