#pragma once
#include <vector>
using namespace std;
class AVLNode {
private:
    unsigned int id; // �洢id
    int pos; // ��¼�ڹ�ϣ�����е�λ��
    int balanceFactor; // ƽ������
    AVLNode* left; // ������
    AVLNode* right; // ������
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
    static AVLNode* insertNode(AVLNode* root, pair<unsigned, int> value); // ����ڵ�
    static AVLNode* removeNode(AVLNode* root, pair<unsigned, int> value); // ɾ���ڵ�
    static AVLNode* searchNode(AVLNode* root, unsigned int id); // ���ҽڵ�
    static AVLNode* convertToAVLTree(const vector<pair<unsigned, int>>& arr); // ������ת��ΪAVL��
    static vector<pair<unsigned, int>> convertToSortedArray(AVLNode* root); // ��AVL��ת��Ϊ����
};

