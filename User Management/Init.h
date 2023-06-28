#pragma once
#include <vector>
#include "Hash.h"
#include "IdAvl.h"
using namespace std;
bool save(Hash* hash, const vector<unsigned int>& id, int op = 0);
bool load(Hash* hash, AVLNode* avl);