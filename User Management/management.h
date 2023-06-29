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

void openManagement(Hash* hash, AVLNode*& root); //���˵�ѭ��
void showMenu(); //��ʾ�˵�
int showAll(Hash* hash); //��ʾ�û���Ϣ(��ϣ��)
bool addUser(Hash* hash, User user, AVLNode*& root, int op = 1); //����û�
bool delUser(Hash* hash, AVLNode*& root, string username); //ɾ���û�
bool change(Hash* hash, string username); //�޸��û�
bool findUser(Hash* hash, string username, User& user); //�����û�(�����û�)
bool findUser(Hash* hash, string username, int op = 0); //�����û�
int hashFunction(const string& str); //�ַ�����ϣ����
bool findUserById(Hash* hash, unsigned int id, AVLNode* root); //����id���ҹ�ϣλ��
