#pragma once
// ”√ªß¿‡
#include <string>
using namespace std;

struct ShoppingCart
{
    string productName;
};
struct Order
{
    string productName;
};

class User {
private:
    int id;
    char username[30];
    char password[15];
    ShoppingCart cart;
    Order order;
public:
    User();
    User(int, string, string, ShoppingCart, Order);
    User()
    {
        id = 0;
        strcpy(username, "");
        strcpy(password, "");
    }

    User(int id, string username, string password, ShoppingCart cart, Order order)
    {
        this->id = id;
        strcpy(this->username, username.c_str());
        strcpy(this->password, password.c_str());
        //this->cart = cart;
        //this->order = order;
    }

    int getId()
    {
        return id;
    }

    void setId(int id)
    {
        this->id = id;
    }

    string getUsername()
    {
        return username;
    }

    void setUsername(string username)
    {
        strcpy(this->username, username.c_str());
    }

    string getPassword()
    {
        return password;
    }

    void setPassword(string password)
    {
        strcpy(this->password, password.c_str());
    }

    //string getCart()
    //{
    //    return cart.productName;
    //}

    //void setCart(ShoppingCart cart)
    //{
    //    this->cart = cart;
    //}

    //string getOrder()
    //{
    //    return order.productName;
    //}

    //void setOrder(Order order)
    //{
    //    this->order = order;
    //}
};