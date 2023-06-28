#include <fstream>
#include "Init.h"
#include "management.h"
using namespace std;
// 保存数据到文件
bool save(Hash* hash, AVLNode*& root, int op) //op=0:保存全部数据并退出，op=1:保存并重新加载数据
{
    vector<pair<unsigned, int>> value = AVLNode::convertToSortedArray(root); // 将AVL树转换为有序数组
    ofstream file_id("id.dat");
    for (pair<unsigned, int> v : value) file_id << v.first << " " << v.second << " "; // 将有序数组写入文件
    file_id.close();
    ofstream file_user("user_management.dat");
    for (int i = 0; i < SIZE; i++)
    {
        Node* p = hash->data[i];
        while (p != NULL)
        {
            // 将哈希表中的数据写入文件
            file_user.write((char*)&p->data, sizeof(User));
            p = p->next;
        }
    }
    if (op == 0) file_user.close();
    return true;
}
// 导入文件数据
bool load(Hash* hash, AVLNode*& avl)
{
    ifstream file_id("id.dat");
    if (!file_id) // 文件不存在则创建文件
    {
        ofstream cfile("id.dat");
        cfile.close();
        load(hash, avl);
    }
    vector<pair<unsigned, int>> id;
    unsigned int value;
    int pos;
    while (file_id >> value >> pos) id.push_back(make_pair(value, pos));// 从文件中读取数据
    file_id.close();
    avl = AVLNode::convertToAVLTree(id);// 将数据导入AVL树
    ifstream file_user("user_management.dat");
    User user;
    if (!file_user) // 文件不存在则创建文件
    {
        ofstream cfile("user_management.dat");
        cfile.close();
        load(hash, avl);
    }
    while (file_user.read((char*)&user, sizeof(User)))
    {
        // 文件数据导入哈希表
        addUser(hash, user, avl, 1);
        hash->count++;
    }
    file_user.close();
    return true;
}