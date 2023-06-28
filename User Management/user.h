#pragma once
#include <string>
using namespace std;

class User {
private:
    unsigned int id; // 用户id
    char username[30]; // 用户名
    char password[15]; // 密码
    bool isAdmin; // 是否是管理员
    unsigned int points; // 积分
    char cartId[100]; // 购物车
    char orderId[30]; // 订单号
    static string setStringType(string str); // 规范显示格式
public:
    User();
    User(unsigned int id, string username, string password, unsigned int points, string cartId, string orderId);
    static void showDetails(User user, int op = 1); // 展示用户信息
    unsigned int getId();
    void setId(unsigned int id);
    string getUsername();
    void setUsername(string username);
    string getPassword();
    void setPassword(string password);
    unsigned int getPoints();
    void setPoints(unsigned int points);
    string getCartId();
    void setCartId(string cartId);
    string getOrderId();
    void setOrderId(string orderId);
    bool getIsAdmin();
    void setIsAdmin(bool isAdmin);
};