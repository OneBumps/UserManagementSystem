#pragma once
#include <vector>
using namespace std;
class AVLNode {
private:
    unsigned int id; // 存储id
    int pos; // 记录在哈希数组中的位置
    int balanceFactor; // 平衡因子
    AVLNode* left; // 左子树
    AVLNode* right; // 右子树
    static AVLNode* buildAVLTree(const vector<pair<unsigned, int>>& arr, int start, int end);
    static int getHeight(AVLNode* node);
    static void updateBalanceFactor(AVLNode* node);
    static AVLNode* rotateLeft(AVLNode* node);
    static AVLNode* rotateRight(AVLNode* node);
    static void inOrderTraversalToArray(AVLNode* root, vector<pair<unsigned, int>>& result);
    static AVLNode* findSuccessor(AVLNode* node);
    static void inOrderTraversal(AVLNode* root);
    static int AVLtoArray();

    //static int testArrayToAVL();
    //static int testSaveAndLoad();
    //static int testInsertAndDelete();
    //static int testSearch();
public:
    AVLNode(pair<unsigned, int> val);
    unsigned int getId();
    void setId(unsigned int val);
    int getPos();
    void setPos(int val);
    static AVLNode* insertNode(AVLNode* root, pair<unsigned, int> value); // 插入节点
    static AVLNode* removeNode(AVLNode* root, pair<unsigned, int> value); // 删除节点
    static AVLNode* searchNode(AVLNode* root, unsigned int id); // 查找节点
    static AVLNode* convertToAVLTree(const vector<pair<unsigned, int>>& arr); // 将数组转换为AVL树
    static vector<pair<unsigned, int>> convertToSortedArray(AVLNode* root); // 将AVL树转换为数组
};

