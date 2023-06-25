#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define SIZE 30

#include <iostream>
#include <cstring>
#include <fstream>
#include "user.h"
using namespace std;

struct Node
{
    User data;
    Node* next;
};

struct Hash
{
    Node* data[SIZE] = { nullptr };
    int count = 0;
};

void menu(); //主菜单显示
int hashFunction(int key); //哈希函数
int show(Hash* hash); //显示用户信息(哈希表)
bool addUser(Hash* hash, User user, int op); //添加用户
bool delUser(Hash* hash, int id); //删除用户
bool change(Hash* hash,int id); //修改用户
bool findUser(Hash* hash, User user, int op); //查找用户
bool save(Hash* hash); //保存用户信息
bool load(Hash* hash); //加载用户信息