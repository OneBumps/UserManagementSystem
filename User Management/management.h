#pragma once
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include "Hash.h"
#include "AVLNode.h"
using namespace std;

void openManagement(Hash* hash, AVLNode*& root); //主菜单循环
void showMenu(); //显示菜单
int showAll(Hash* hash); //显示用户信息(哈希表)
bool addUser(Hash* hash, User user, AVLNode*& root, int op = 1); //添加用户
bool delUser(Hash* hash, AVLNode*& root, string username); //删除用户
bool change(Hash* hash, string username); //修改用户
bool findUser(Hash* hash, string username, User& user); //查找用户(返回用户)
bool findUser(Hash* hash, string username, int op = 0); //查找用户
int hashFunction(const string& str); //字符串哈希函数
bool findUserById(Hash* hash, unsigned int id, AVLNode* root); //根据id查找哈希位置
