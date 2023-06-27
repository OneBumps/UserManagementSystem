#pragma once
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "Hash.h"
using namespace std;

void openManagement(Hash* hash); //���˵�ѭ��
void showMenu(); //��ʾ�˵�
int hashFunction(int key); //��ϣ����
int showAll(Hash* hash); //��ʾ�û���Ϣ(��ϣ��)
bool addUser(Hash* hash, User user, int op); //����û�
bool delUser(Hash* hash, int id); //ɾ���û�
bool change(Hash* hash,int id); //�޸��û�
bool findUser(Hash* hash, int id, int op); //�����û�(ͨ��id)
bool findUser(Hash* hash, int id, User& user); //�����û�����֤(ͨ��id)
bool findUser(Hash* hash, string username, int op = 0); //�����û�(ͨ���û���)
bool save(Hash* hash); //�����û���Ϣ
bool load(Hash* hash); //�����û���Ϣ
int hashFunction(const string& str); //�ַ�����ϣ����