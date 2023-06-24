#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <io.h>


using namespace std;
#define SIZE 30

enum opt
{
    OPENERROR = -7,
    ERROR,
    DOWNLOADERROR,
    UPLOOADERROR,
    EXIST,
    NOEXIST,
    MALLOCERROR,
    OK
};


struct data_type
{
    int id;
    char name[SIZE];
    int age;
    char status[SIZE];
};

struct Node
{
    data_type data;
    Node* next;
};

struct Hash
{
    Node* pArr[SIZE] = { nullptr };
    int count = 0;
};

void menu();
Hash* createHash();
int hashFunc(int key);
int show(Hash* pHash);
int add(Hash* pHash, data_type pData);
int find(Hash* pHash, data_type pData);
int del(Hash* pHash, data_type pData);
int change(Hash* pHash, data_type pData);
int destroy(Hash** pHash);
int save(Hash* pHash, const char* filename);
int load(Hash* pHash, const char* filename);

