#include "FileWithUsers.h"
#include "XmlFile.h"
#include "User.h"
#include "Markup.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Login", user.getUserLogin());
    xml.AddElem("Password", user.getUserPassword());
    xml.AddElem("Name", user.getUserName());
    xml.AddElem("Surname", user.getUserSurname());

    xml.Save(getFileName());
}

vector<User> FileWithUsers::loadUsersFromFile()
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    User user;
    vector<User> users;

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    if (fileExists)
    {
        while ( xml.FindElem("User") )
        {
        xml.IntoElem();
        xml.FindElem( "UserId");
        user.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "Login");
        user.setUserLogin(xml.GetData());
        xml.FindElem( "Password");
        user.setUserPassword(xml.GetData());
        xml.FindElem( "Name");
        user.setUserName(xml.GetData());
        xml.FindElem( "Surname");
        user.setUserSurname(xml.GetData());
        users.push_back(user);
        xml.OutOfElem();
        }
    }
    else
        cout << "Blad pliku!" << endl;

    return users;
}
