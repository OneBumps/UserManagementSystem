#include <iostream>
#include "IdAvl.h"
#include "Init.h"
#include "Hash.h"
using namespace std;

AVLNode::AVLNode(unsigned int val) : value(val), balanceFactor(0), left(nullptr), right(nullptr) {}

// 构建AVL树
AVLNode* AVLNode::buildAVLTree(const vector<unsigned int>& arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    AVLNode* root = new AVLNode(arr[mid]);
    root->left = buildAVLTree(arr, start, mid - 1);
    root->right = buildAVLTree(arr, mid + 1, end);

    // 更新平衡因子
    updateBalanceFactor(root);

    // 平衡维护
    if (root->balanceFactor > 1) {
        if (root->left->balanceFactor >= 0) {
            // 左-左情况
            root = rotateRight(root);
        }
        else {
            // 左-右情况
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
    }
    else if (root->balanceFactor < -1) {
        if (root->right->balanceFactor <= 0) {
            // 右-右情况
            root = rotateLeft(root);
        }
        else {
            // 右-左情况
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }

    return root;
}

// 将数组转换为AVL树
AVLNode* AVLNode::convertToAVLTree(const vector<unsigned int>& arr) {
    int size = arr.size();
    return buildAVLTree(arr, 0, size - 1);
}

// 获取节点的高度
int AVLNode::getHeight(AVLNode* node) {
    if (node == nullptr) {
        return -1;
    }
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

// 更新节点的平衡因子
void AVLNode::updateBalanceFactor(AVLNode* node) {
    if (node == nullptr) {
        return;
    }
    node->balanceFactor = getHeight(node->left) - getHeight(node->right);
}

// 左旋转
AVLNode* AVLNode::rotateLeft(AVLNode* node) {
    AVLNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateBalanceFactor(node);
    updateBalanceFactor(newRoot);
    return newRoot;
}

// 右旋转
AVLNode* AVLNode::rotateRight(AVLNode* node) {
    AVLNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateBalanceFactor(node);
    updateBalanceFactor(newRoot);
    return newRoot;
}

// 插入节点
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
            // 左-左情况
            root = rotateRight(root);
        }
        else {
            // 左-右情况
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
    }
    else if (root->balanceFactor < -1) {
        if (value > root->right->value) {
            // 右-右情况
            root = rotateLeft(root);
        }
        else {
            // 右-左情况
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }
    return root;
}

// 打印AVL树中序遍历结果
void AVLNode::inOrderTraversal(AVLNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->value << " ";
    inOrderTraversal(root->right);
}

// 查找节点的后继节点（右子树中的最小值节点）
AVLNode* AVLNode::findSuccessor(AVLNode* node) {
    AVLNode* current = node->right;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// 删除节点
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
        // 找到要删除的节点
        if (root->left == nullptr || root->right == nullptr) {
            // 要删除的节点最多有一个子节点或没有子节点
            AVLNode* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                // 没有子节点的情况
                temp = root;
                root = nullptr;
            }
            else {
                // 有一个子节点的情况
                *root = *temp;
            }

            delete temp;
        }
        else {
            // 要删除的节点有两个子节点
            AVLNode* successor = findSuccessor(root);
            root->value = successor->value;
            root->right = removeNode(root->right, successor->value);
        }
    }
    // 更新平衡因子
    updateBalanceFactor(root);
    // 平衡维护
    if (root->balanceFactor > 1) {
        if (root->left->balanceFactor >= 0) {
            // 左-左情况
            root = rotateRight(root);
        }
        else {
            // 左-右情况
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
    }
    else if (root->balanceFactor < -1) {
        if (root->right->balanceFactor <= 0) {
            // 右-右情况
            root = rotateLeft(root);
        }
        else {
            // 右-左情况
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }
    return root;
}

// 搜索节点
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

// 中序遍历并保存为数组
void AVLNode::inOrderTraversalToArray(AVLNode* root, vector<unsigned int>& result)
{
    if (root == nullptr) {
        return;
    }
    inOrderTraversalToArray(root->left, result);
    result.push_back(root->value);
    inOrderTraversalToArray(root->right, result);
}

// 将AVL树中序遍历并保存为数组
vector<unsigned int> AVLNode::convertToSortedArray(AVLNode* root) {
    vector<unsigned int> result;
    inOrderTraversalToArray(root, result);
    return result;
}

// 测试插入删除
int AVLNode::testInsertAndDelete() {
    AVLNode* root = nullptr;
    // 插入示例数据
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    // 中序遍历打印结果
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;
    // 删除节点
    root = removeNode(root, 40);
    // 中序遍历打印结果
    cout << "In-order traversal after deletion: ";
    inOrderTraversal(root);
    cout << endl;
    return 0;
}

// 测试搜索
int AVLNode::testSearch() {
    AVLNode* root = nullptr;
    // 插入示例数据
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    // 搜索值为30的节点
    AVLNode* result = searchNode(root, 40);
    if (result != nullptr) cout << "Found: " << result->value << endl;
    else cout << "Not found." << endl;
    return 0;
}

// 测试转换为数组
int AVLNode::AVLtoArray() {
    AVLNode* root = nullptr;
    // 插入示例数据
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    // 将AVL树中序遍历并保存为数组
    vector<unsigned int> sortedArray = convertToSortedArray(root);
    // 打印结果
    cout << "Sorted Array: ";
    for (int value : sortedArray) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}

// 测试转换为AVL树
int AVLNode::testArrayToAVL() {
    vector<unsigned int> arr = { 10, 20, 30, 40, 50, 25 };
    // 将数组转换为AVL树
    AVLNode* root = convertToAVLTree(arr);
    // 中序遍历打印结果
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;
    return 0;
}

// 测试保存和加载
//int AVLNode::testSaveAndLoad() {
//    Hash* hash = new Hash();
//    vector<unsigned int> arr = { 10, 20, 30, 40, 50, 25 };
//    // 将数组存储到文件中
//    save(hash, arr);
//    vector<unsigned int> arrs;
//    // 从文件中读取数组
//    load(hash, arrs);
//
//    // 打印读取的数组
//    cout << "Loaded Array: ";
//    for (int value : arrs) {
//        cout << value << " ";
//    }
//    cout << endl;
//    return 0;
//}