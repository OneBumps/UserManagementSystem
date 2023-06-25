//#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
//
//#include <iostream>
//#include <cstring>
//#include <fcntl.h>
//#include <io.h>
//#include <fstream>
//using namespace std;
//#define SIZE 30 //桶个数
//
//enum opt
//{
//    OPENERROR = -7,
//    ERROR,
//    DOWNLOADERROR,
//    UPLOOADERROR,
//    EXIST,
//    NOEXIST,
//    MALLOCERROR,
//    OK
//};
//
//
//struct User
//{
//    int id;
//    char name[SIZE];
//    int age;
//    char status[SIZE];
//};
//
//struct Node
//{
//    User data;
//    Node* next;
//};
//
//struct Hash
//{
//    Node* pArr[SIZE] = { nullptr }; //哈希表指针
//    int count = 0; //哈希表元素个数
//};
//
//void menu();
//Hash* createHash();
//int hashFunc(int key);
//int show(Hash* pHash);
//int add(Hash* pHash, User pData);
//int findUser(Hash* pHash, User pData);
//int delUser(Hash* pHash, User pData);
//int change(Hash* pHash, User pData);
//int destroy(Hash** pHash);
//int save(Hash* pHash, const char* filename);
//int load(Hash* pHash, const char* filename);
//
