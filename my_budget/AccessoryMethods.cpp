#include "AccessoryMethods.h"

string AccessoryMethods::conversionIntToString(int num)
{
    ostringstream ss;
    ss << num;
    string str = ss.str();
    return str;
}

int AccessoryMethods::conversionStringToInt(string num)
{
    int numInt;
    istringstream iss(num);
    iss >> numInt;

    return numInt;
}

string AccessoryMethods::getLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

int AccessoryMethods::getIntegerNumber()
{
    string input = "";
    int num = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> num)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return num;
}

string AccessoryMethods::changeFirstLetterToCapitalLetterAndOtherToSmall(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

char AccessoryMethods::getSign()
{
    string input = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}
