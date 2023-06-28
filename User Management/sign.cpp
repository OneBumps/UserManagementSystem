#include <Windows.h>
#include <cstring>
#include <iostream>
#include "Sign.h"
#include "Hash.h"
#include "init.h"
#include "management.h"
#include "IdAvl.h"
void signUp(Hash* hash, vector<unsigned int>& id)
{
    system("cls");
    puts("���������̳� - �û�����");
    puts("------�û�ע��------");
    puts("");
    unsigned int userId;
    string username;
    string password;
    printf("�û�ID��");
    cin >> userId;
    printf("�û�����");
    cin >> username;
    printf("���룺");
    cin >> password;
    User user(userId, username, password, 0, "", "");
    if (addUser(hash, user, 2))
    {
        puts("ע��ɹ���������ת����ҳ");
        save(hash, id, 1);
        Sleep(500);
        system("cls");
        return;
    }
    else
    {
        puts("�û�ID�ظ���ע��ʧ�ܣ�");
        Sleep(500);
        system("cls");
        signUp(hash, id);
    }
}
void signIn(Hash* hash, vector<unsigned int>& id)
{
    puts("���������̳� - �û�����");
    string username;
    char password[15];
    User user;
    puts("------�û���¼------");
    puts("");
    cout << "�������û��ǳƣ�";
    cin >> username;
    cout << "�������û����룺";
    cin >> password;
    system("cls");
    if (findUser(hash, username, user) == true && user.getPassword() == password)
    {
        system("cls");
        puts("���ڽ���ϵͳ...");
        Sleep(2000);
        //if (user.getIsAdmin() == true) openManagement(hash);
        openManagement(hash, id);
        return;
    }
    else
    {
        system("cls");
        puts("�˻���������������µ�¼��");
        puts("--------------------");
        puts("����E������һ������������������");
        puts("");
        char choice;
        cin >> choice;
        system("cls");
        if (choice == 'E' || choice == 'e') return;
    }
    signIn(hash, id);
}

void choose(Hash* hash, vector<unsigned int>& id)
{
    while (1)
    {
        puts("���������̳� - �û�����");
        puts("------ʹ���û�------");
        puts("");
        puts("     1. ��¼");
        puts("     2. ע��");
        puts("");
        puts("--------------------");
        puts("����E�˳��̳�");
        char choice;
        cin >> choice;
        switch (choice)
        {
        case '1':
        {
            system("cls");
            signIn(hash, id);
            break;
        }
        case '2':
        {
            system("cls");
            signUp(hash, id);
            break;
        }
        case 'E':;
        case 'e':
            return;
        }
    }
}

int main()
{
    Hash* hash = new Hash();
    vector<unsigned int> id;
    AVLNode* root = nullptr;
    if (!load(hash, root)) return 0;
    choose(hash, id);
    return 0;
}