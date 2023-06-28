#include <iostream>
#include "AVLNode.h"
#include "Init.h"
#include "Hash.h"
using namespace std;

AVLNode::AVLNode(pair<unsigned, int> val) : balanceFactor(0), left(nullptr), right(nullptr)
{
    this->id = val.first;
    this->pos = val.second;
}

// ����AVL��
AVLNode* AVLNode::buildAVLTree(const vector<pair<unsigned, int>>& arr, int start, int end) {
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
AVLNode* AVLNode::convertToAVLTree(const vector<pair<unsigned, int>>& arr) {
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
AVLNode* AVLNode::insertNode(AVLNode* root, pair<unsigned, int> value) {
    if (root == nullptr) {
        return new AVLNode(value);
    }
    if (value.first < root->id) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }
    updateBalanceFactor(root);
    if (root->balanceFactor > 1) {
        if (value.first < root->left->id) {
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
        if (value.first > root->right->id) {
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
    cout << root->id << " ";
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
AVLNode* AVLNode::removeNode(AVLNode* root, pair<unsigned, int> value) {
    if (root == nullptr) {
        return nullptr;
    }
    if (value.first < root->id) {
        root->left = removeNode(root->left, value);
    }
    else if (value.first > root->id) {
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
            pair<unsigned, int> temp;
            root->id = successor->id;
            root->pos = successor->pos;
            root->right = removeNode(root->right, make_pair(root->id, root->pos));
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
AVLNode* AVLNode::searchNode(AVLNode* root, unsigned int id)
{
    if (root == nullptr || root->id == id) {
        return root;
    }
    if (id < root->id) {
        return searchNode(root->left, id);
    }
    else {
        return searchNode(root->right, id);
    }
}

// �������������Ϊ����
void AVLNode::inOrderTraversalToArray(AVLNode* root, vector<pair<unsigned, int>>& result)
{
    if (root == nullptr) {
        return;
    }
    inOrderTraversalToArray(root->left, result);
    result.push_back(make_pair(root->id, root->pos));
    inOrderTraversalToArray(root->right, result);
}

// ��AVL���������������Ϊ����
vector<pair<unsigned, int>> AVLNode::convertToSortedArray(AVLNode* root) {
    vector<pair<unsigned, int>> result;
    inOrderTraversalToArray(root, result);
    return result;
}

//// ���Բ���ɾ��
//int AVLNode::testInsertAndDelete() {
//    AVLNode* root = nullptr;
//    // ����ʾ������
//    root = insertNode(root, 10);
//    root = insertNode(root, 20);
//    root = insertNode(root, 30);
//    root = insertNode(root, 40);
//    root = insertNode(root, 50);
//    root = insertNode(root, 25);
//    // ���������ӡ���
//    cout << "In-order traversal: ";
//    inOrderTraversal(root);
//    cout << endl;
//    // ɾ���ڵ�
//    root = removeNode(root, 40);
//    // ���������ӡ���
//    cout << "In-order traversal after deletion: ";
//    inOrderTraversal(root);
//    cout << endl;
//    return 0;
//}
//
//// ��������
//int AVLNode::testSearch() {
//    AVLNode* root = nullptr;
//    // ����ʾ������
//    root = insertNode(root, 10);
//    root = insertNode(root, 20);
//    root = insertNode(root, 30);
//    root = insertNode(root, 40);
//    root = insertNode(root, 50);
//    root = insertNode(root, 25);
//    // ����ֵΪ30�Ľڵ�
//    AVLNode* result = searchNode(root, 40);
//    if (result != nullptr) cout << "Found: " << result->id << endl;
//    else cout << "Not found." << endl;
//    return 0;
//}

// AVl��ת��Ϊ����
//int AVLNode::testAVLtoArray() {
//    AVLNode* root = nullptr;
//    // ����ʾ������
//    root = insertNode(root, 10);
//    root = insertNode(root, 20);
//    root = insertNode(root, 30);
//    root = insertNode(root, 40);
//    root = insertNode(root, 50);
//    root = insertNode(root, 25);
//    // ��AVL���������������Ϊ����
//    vector<unsigned int> sortedArray = convertToSortedArray(root);
//    // ��ӡ���
//    cout << "Sorted Array: ";
//    for (int value : sortedArray) {
//        cout << value << " ";
//    }
//    cout << endl;
//    return 0;
//}

//// ����ת��ΪAVL��
//int AVLNode::testArrayToAVL() {
//    vector<unsigned int> arr = { 10, 20, 30, 40, 50, 25 };
//    // ������ת��ΪAVL��
//    AVLNode* root = convertToAVLTree(arr);
//    // ���������ӡ���
//    cout << "In-order traversal: ";
//    inOrderTraversal(root);
//    cout << endl;
//    return 0;
//}

unsigned int AVLNode::getId()
{
    return id;
}
void AVLNode::setId(unsigned int val)
{
    this->id = val;
}
int AVLNode::getPos()
{
    return pos;
}
void AVLNode::setPos(int val)
{
    this->pos = val;
}