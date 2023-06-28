#include <iostream>
#include "IdAvl.h"
#include "Init.h"
#include "Hash.h"
using namespace std;

AVLNode::AVLNode(unsigned int val) : value(val), balanceFactor(0), left(nullptr), right(nullptr) {}

// ����AVL��
AVLNode* AVLNode::buildAVLTree(const vector<unsigned int>& arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    AVLNode* root = new AVLNode(arr[mid]);
    root->left = buildAVLTree(arr, start, mid - 1);
    root->right = buildAVLTree(arr, mid + 1, end);

    // ����ƽ������
    updateBalanceFactor(root);

    // ƽ��ά��
    if (root->balanceFactor > 1) {
        if (root->left->balanceFactor >= 0) {
            // ��-�����
            root = rotateRight(root);
        }
        else {
            // ��-�����
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
    }
    else if (root->balanceFactor < -1) {
        if (root->right->balanceFactor <= 0) {
            // ��-�����
            root = rotateLeft(root);
        }
        else {
            // ��-�����
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }

    return root;
}

// ������ת��ΪAVL��
AVLNode* AVLNode::convertToAVLTree(const vector<unsigned int>& arr) {
    int size = arr.size();
    return buildAVLTree(arr, 0, size - 1);
}

// ��ȡ�ڵ�ĸ߶�
int AVLNode::getHeight(AVLNode* node) {
    if (node == nullptr) {
        return -1;
    }
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

// ���½ڵ��ƽ������
void AVLNode::updateBalanceFactor(AVLNode* node) {
    if (node == nullptr) {
        return;
    }
    node->balanceFactor = getHeight(node->left) - getHeight(node->right);
}

// ����ת
AVLNode* AVLNode::rotateLeft(AVLNode* node) {
    AVLNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateBalanceFactor(node);
    updateBalanceFactor(newRoot);
    return newRoot;
}

// ����ת
AVLNode* AVLNode::rotateRight(AVLNode* node) {
    AVLNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateBalanceFactor(node);
    updateBalanceFactor(newRoot);
    return newRoot;
}

// ����ڵ�
AVLNode* AVLNode::insertNode(AVLNode* root, unsigned int value) {
    if (root == nullptr) {
        return new AVLNode(value);
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }
    updateBalanceFactor(root);
    if (root->balanceFactor > 1) {
        if (value < root->left->value) {
            // ��-�����
            root = rotateRight(root);
        }
        else {
            // ��-�����
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
    }
    else if (root->balanceFactor < -1) {
        if (value > root->right->value) {
            // ��-�����
            root = rotateLeft(root);
        }
        else {
            // ��-�����
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }
    return root;
}

// ��ӡAVL������������
void AVLNode::inOrderTraversal(AVLNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->value << " ";
    inOrderTraversal(root->right);
}

// ���ҽڵ�ĺ�̽ڵ㣨�������е���Сֵ�ڵ㣩
AVLNode* AVLNode::findSuccessor(AVLNode* node) {
    AVLNode* current = node->right;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// ɾ���ڵ�
AVLNode* AVLNode::removeNode(AVLNode* root, unsigned int value) {
    if (root == nullptr) {
        return nullptr;
    }
    if (value < root->value) {
        root->left = removeNode(root->left, value);
    }
    else if (value > root->value) {
        root->right = removeNode(root->right, value);
    }
    else {
        // �ҵ�Ҫɾ���Ľڵ�
        if (root->left == nullptr || root->right == nullptr) {
            // Ҫɾ���Ľڵ������һ���ӽڵ��û���ӽڵ�
            AVLNode* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                // û���ӽڵ�����
                temp = root;
                root = nullptr;
            }
            else {
                // ��һ���ӽڵ�����
                *root = *temp;
            }

            delete temp;
        }
        else {
            // Ҫɾ���Ľڵ��������ӽڵ�
            AVLNode* successor = findSuccessor(root);
            root->value = successor->value;
            root->right = removeNode(root->right, successor->value);
        }
    }
    // ����ƽ������
    updateBalanceFactor(root);
    // ƽ��ά��
    if (root->balanceFactor > 1) {
        if (root->left->balanceFactor >= 0) {
            // ��-�����
            root = rotateRight(root);
        }
        else {
            // ��-�����
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
    }
    else if (root->balanceFactor < -1) {
        if (root->right->balanceFactor <= 0) {
            // ��-�����
            root = rotateLeft(root);
        }
        else {
            // ��-�����
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }
    return root;
}

// �����ڵ�
AVLNode* AVLNode::searchNode(AVLNode* root, unsigned int value)
{
    if (root == nullptr || root->value == value) {
        return root;
    }
    if (value < root->value) {
        return searchNode(root->left, value);
    }
    else {
        return searchNode(root->right, value);
    }
}

// �������������Ϊ����
void AVLNode::inOrderTraversalToArray(AVLNode* root, vector<unsigned int>& result)
{
    if (root == nullptr) {
        return;
    }
    inOrderTraversalToArray(root->left, result);
    result.push_back(root->value);
    inOrderTraversalToArray(root->right, result);
}

// ��AVL���������������Ϊ����
vector<unsigned int> AVLNode::convertToSortedArray(AVLNode* root) {
    vector<unsigned int> result;
    inOrderTraversalToArray(root, result);
    return result;
}

// ���Բ���ɾ��
int AVLNode::testInsertAndDelete() {
    AVLNode* root = nullptr;
    // ����ʾ������
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    // ���������ӡ���
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;
    // ɾ���ڵ�
    root = removeNode(root, 40);
    // ���������ӡ���
    cout << "In-order traversal after deletion: ";
    inOrderTraversal(root);
    cout << endl;
    return 0;
}

// ��������
int AVLNode::testSearch() {
    AVLNode* root = nullptr;
    // ����ʾ������
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    // ����ֵΪ30�Ľڵ�
    AVLNode* result = searchNode(root, 40);
    if (result != nullptr) cout << "Found: " << result->value << endl;
    else cout << "Not found." << endl;
    return 0;
}

// ����ת��Ϊ����
int AVLNode::AVLtoArray() {
    AVLNode* root = nullptr;
    // ����ʾ������
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    // ��AVL���������������Ϊ����
    vector<unsigned int> sortedArray = convertToSortedArray(root);
    // ��ӡ���
    cout << "Sorted Array: ";
    for (int value : sortedArray) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}

// ����ת��ΪAVL��
int AVLNode::testArrayToAVL() {
    vector<unsigned int> arr = { 10, 20, 30, 40, 50, 25 };
    // ������ת��ΪAVL��
    AVLNode* root = convertToAVLTree(arr);
    // ���������ӡ���
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;
    return 0;
}

// ���Ա���ͼ���
//int AVLNode::testSaveAndLoad() {
//    Hash* hash = new Hash();
//    vector<unsigned int> arr = { 10, 20, 30, 40, 50, 25 };
//    // ������洢���ļ���
//    save(hash, arr);
//    vector<unsigned int> arrs;
//    // ���ļ��ж�ȡ����
//    load(hash, arrs);
//
//    // ��ӡ��ȡ������
//    cout << "Loaded Array: ";
//    for (int value : arrs) {
//        cout << value << " ";
//    }
//    cout << endl;
//    return 0;
//}