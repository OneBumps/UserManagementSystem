#include <Windows.h>
#include <cstring>
#include <iostream>
#include "Sign.h"
#include "Hash.h"
#include "init.h"
#include "management.h"
void signUp(Hash* hash)
{
    system("cls");
    puts("���������̳� - �û�����");
    puts("------�û�ע��------");
    puts("");
    unsigned int id;
    string username;
    string password;
    printf("�û�ID��");
    cin >> id;
    printf("�û�����");
    cin >> username;
    printf("���룺");
    cin >> password;
    User user(id, username, password, 0, "", "");
    if (addUser(hash, user, 2))
    {
        puts("ע��ɹ���������ת����ҳ");
        save(hash, 1);
        Sleep(500);
        system("cls");
        return;
    }
    else
    {
        puts("�û�ID�ظ���ע��ʧ�ܣ�");
        Sleep(500);
        system("cls");
        signUp(hash);
    }
}
void signIn(Hash* hash)
{
    puts("���������̳� - �û�����");
    unsigned int id;
    char password[15];
    User user;
    puts("------�û���¼------");
    puts("");
    cout << "�������û�ID��";
    cin >> id;
    cout << "�������û����룺";
    cin >> password;
    system("cls");
    if (findUser(hash, id, user) == true && user.getPassword() == password)
    {
        system("cls");
        puts("���ڽ���ϵͳ...");
        Sleep(2000);
        //if (user.getIsAdmin() == true) openManagement(hash);
        openManagement(hash);
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
    signIn(hash);
}

void choose(Hash* hash)
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
            signIn(hash);
            break;
        }
        case '2':
        {
            system("cls");
            signUp(hash);
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
    if (!load(hash)) return 0;
    choose(hash);
    return 0;
}