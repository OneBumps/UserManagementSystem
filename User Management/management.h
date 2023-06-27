#pragma once
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "Hash.h"
using namespace std;

void openManagement(Hash* hash); //主菜单循环
void showMenu(); //显示菜单
int hashFunction(int key); //哈希函数
int showAll(Hash* hash); //显示用户信息(哈希表)
bool addUser(Hash* hash, User user, int op); //添加用户
bool delUser(Hash* hash, int id); //删除用户
bool change(Hash* hash,int id); //修改用户
bool findUser(Hash* hash, int id, int op); //查找用户(通过id)
bool findUser(Hash* hash, int id, User& user); //查找用户并验证(通过id)
bool findUser(Hash* hash, string username, int op = 0); //查找用户(通过用户名)
bool save(Hash* hash); //保存用户信息
bool load(Hash* hash); //加载用户信息
int hashFunction(const string& str); //字符串哈希函数