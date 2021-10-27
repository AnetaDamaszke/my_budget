#ifndef ACCESSORYMETHODS_H
#define ACCESSORYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AccessoryMethods {

public:
    static string conversionIntToString(int num);
    static string changeFirstLetterToCapitalLetterAndOtherToSmall(string text);
    static int conversionStringToInt(string num);
    static string getLine();
    static int getIntegerNumber();
    static char getSign();
};

#endif
