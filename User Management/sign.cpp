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
    puts("在线零售商城 - 用户中心");
    puts("------用户注册------");
    puts("");
    unsigned int id;
    string username;
    string password;
    printf("用户ID：");
    cin >> id;
    printf("用户名：");
    cin >> username;
    printf("密码：");
    cin >> password;
    User user(id, username, password, 0, "", "");
    if (addUser(hash, user, 2))
    {
        puts("注册成功，即将跳转到首页");
        save(hash, 1);
        Sleep(500);
        system("cls");
        return;
    }
    else
    {
        puts("用户ID重复，注册失败！");
        Sleep(500);
        system("cls");
        signUp(hash);
    }
}
void signIn(Hash* hash)
{
    puts("在线零售商城 - 用户中心");
    unsigned int id;
    char password[15];
    User user;
    puts("------用户登录------");
    puts("");
    cout << "请输入用户ID：";
    cin >> id;
    cout << "请输入用户密码：";
    cin >> password;
    system("cls");
    if (findUser(hash, id, user) == true && user.getPassword() == password)
    {
        system("cls");
        puts("正在进入系统...");
        Sleep(2000);
        //if (user.getIsAdmin() == true) openManagement(hash);
        openManagement(hash);
        return;
    }
    else
    {
        system("cls");
        puts("账户或密码错误，请重新登录！");
        puts("--------------------");
        puts("输入E返回上一级，输入其他键继续");
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
        puts("在线零售商城 - 用户中心");
        puts("------使用用户------");
        puts("");
        puts("     1. 登录");
        puts("     2. 注册");
        puts("");
        puts("--------------------");
        puts("输入E退出商城");
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