#pragma once
#include <string>
using namespace std;

class User {
private:
    // ������Ϣ
    unsigned int id;
    char username[30];
    char password[15];
    bool isAdmin;
    // ����
    unsigned int points;
    // ���ﳵ
    char cartId[100];
    // ������
    char orderId[30];
    static string setStringType(string str);
public:
    User();
    User(unsigned int id, string username, string password, unsigned int points, string cartId, string orderId);
    static void showDetails(User user, int op = 1);
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