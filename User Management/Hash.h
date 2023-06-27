#pragma once
#include "Node.h"
using namespace std;
#define SIZE 30
struct Hash
{
    Node* data[SIZE] = { nullptr };
    int count = 0;
};