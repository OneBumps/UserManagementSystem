#pragma once
#include <string>
using namespace std;

class User {
private:
    unsigned int id; // �û�id
    char username[30]; // �û���
    char password[15]; // ����
    bool isAdmin; // �Ƿ��ǹ���Ա
    unsigned int points; // ����
    char cartId[100]; // ���ﳵ
    char orderId[30]; // ������
    static string setStringType(string str); // �淶��ʾ��ʽ
public:
    User();
    User(unsigned int id, string username, string password, unsigned int points, string cartId, string orderId);
    static void showDetails(User user, int op = 1); // չʾ�û���Ϣ
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