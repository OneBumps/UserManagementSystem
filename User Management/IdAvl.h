#pragma once
#include <vector>
using namespace std;
class AVLNode {
private:
    unsigned int value;
    int balanceFactor; // Æ½ºâÒò×Ó
    AVLNode* left;
    AVLNode* right;
    static AVLNode* buildAVLTree(const vector<unsigned int>& arr, int start, int end);
    static int getHeight(AVLNode* node);
    static void updateBalanceFactor(AVLNode* node);
    static AVLNode* rotateLeft(AVLNode* node);
    static AVLNode* rotateRight(AVLNode* node);

    static int testArrayToAVL();
    static int testSaveAndLoad();
    static int testInsertAndDelete();
    static int testSearch();
public:
    AVLNode(unsigned int val);
    static void inOrderTraversal(AVLNode* root);
    static AVLNode* insertNode(AVLNode* root, unsigned int value);
    static AVLNode* convertToAVLTree(const vector<unsigned int>& arr);
    static AVLNode* findSuccessor(AVLNode* node);
    static AVLNode* removeNode(AVLNode* root, unsigned int value);
    static AVLNode* searchNode(AVLNode* root, unsigned int value);
    static void inOrderTraversalToArray(AVLNode* root, vector<unsigned int>& result);
    static vector<unsigned int> convertToSortedArray(AVLNode* root);
    static int AVLtoArray();
};

