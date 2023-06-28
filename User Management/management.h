#pragma once
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include "Hash.h"
using namespace std;

void openManagement(Hash* hash, vector<unsigned int>& id); //���˵�ѭ��
void showMenu(); //��ʾ�˵�
int showAll(Hash* hash); //��ʾ�û���Ϣ(��ϣ��)
bool addUser(Hash* hash, User user, int op); //����û�
bool delUser(Hash* hash, string username); //ɾ���û�
bool change(Hash* hash, string username); //�޸��û�
bool findUser(Hash* hash, string username, User& user); //�����û�(�����û�)
bool findUser(Hash* hash, string username, int op = 0); //�����û�
int hashFunction(const string& str); //�ַ�����ϣ����