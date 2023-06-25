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

void menu(); //���˵���ʾ
int hashFunction(int key); //��ϣ����
int show(Hash* hash); //��ʾ�û���Ϣ(��ϣ��)
bool addUser(Hash* hash, User user, int op); //����û�
bool delUser(Hash* hash, int id); //ɾ���û�
bool change(Hash* hash,int id); //�޸��û�
bool findUser(Hash* hash, User user, int op); //�����û�
bool save(Hash* hash); //�����û���Ϣ
bool load(Hash* hash); //�����û���Ϣ