#pragma once
#include <vector>
#include "Hash.h"
#include "AVLNode.h"
using namespace std;
bool save(Hash* hash, AVLNode*& root, int op = 0);
bool load(Hash* hash, AVLNode*& root);