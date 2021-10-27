#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

using namespace std;

class XmlFile {

    const string NAME_OF_FILE;

public:
    XmlFile(string fileName) : NAME_OF_FILE(fileName) {
    }
    string getFileName();
};

#endif
