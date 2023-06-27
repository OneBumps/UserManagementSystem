#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "User.h"
using namespace std;
User::User()
{
    id = 0;
    strcpy(username, "");
    strcpy(password, "");
    isAdmin = false;
    points = 0;
    strcpy(cartId, "");
    strcpy(orderId, "");
}
User::User(unsigned int id, string username, string password, unsigned int points, string cartId, string orderId)
{
    this->id = id;
    strcpy(this->username, username.c_str());
    strcpy(this->password, password.c_str());
    this->isAdmin = false;
    this->points = points;
    strcpy(this->cartId, cartId.c_str());
    strcpy(this->orderId, orderId.c_str());
}

// ���������ʽ
string User::setStringType(string str)
{
    if (str.length() >= 8) return str + "\t";
    else return str + "\t\t";
}

// ��ʾ�û���ϸ��Ϣ
void User::showDetails(User user, int op) //op=0:��ʾ������Ϣ��op=1:����ʾ�û�ID
{
    if (op == 1)
    {
        cout << "�û���\t\t����\t\t����\t\t���ﳵ\t\t������" << endl;
        cout << "-----------------------------------------------------------------------------------" << endl;
        cout << setStringType(user.getUsername())
            << setStringType(user.getPassword())
            << user.getPoints() << "\t\t"
            << user.getCartId() << "\t\t"
            << user.getOrderId() << endl;
        cout << "-----------------------------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "---------------------------------------------------------------------------------------------------" << endl;
        cout << setStringType(to_string(user.getId()))
            << setStringType(user.getUsername())
            << setStringType(user.getPassword())
            << setStringType(to_string(user.getPoints()))
            << setStringType(user.getCartId())
            << setStringType(user.getOrderId()) << endl;
    }
}

unsigned int User::getId()
{
    return id;
}

void User::setId(unsigned int id)
{
    this->id = id;
}

string User::getUsername()
{
    return string(username);
}

void User::setUsername(string username)
{
    strcpy(this->username, username.c_str());
}

string User::getPassword()
{
    return string(password);
}

void User::setPassword(string password)
{
    strcpy(this->password, password.c_str());
}

unsigned int User::getPoints()
{
    return points;
}

void User::setPoints(unsigned int points)
{
    this->points = points;
}

string User::getCartId()
{
    return string(cartId);
}

void User::setCartId(string cartId)
{
    strcpy(this->cartId, cartId.c_str());
}

string User::getOrderId()
{
    return string(orderId);
}

void User::setOrderId(string orderId)
{
    strcpy(this->orderId, orderId.c_str());
}
bool User::getIsAdmin()
{
    return isAdmin;
}
void User::setIsAdmin(bool isAdmin)
{
    this->isAdmin = isAdmin;
}