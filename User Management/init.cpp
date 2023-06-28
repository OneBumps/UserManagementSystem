#include <fstream>
#include "Init.h"
#include "management.h"
using namespace std;
// 保存数据到文件
bool save(Hash* hash, const vector<unsigned int>& id, int op) //op=0:保存全部数据并退出，op=1:保存并重新加载数据
{
    ofstream file_id("id.dat");
    for (int value : id) file_id << value << " ";
    file_id.close();
    ofstream file_user("user_management.dat");
    for (int i = 0; i < SIZE; i++)
    {
        Node* p = hash->data[i];
        while (p != NULL)
        {
            file_user.write((char*)&p->data, sizeof(User));
            p = p->next;
        }
    }
    if (op == 0) file_user.close();
    return true;
}
// 导入文件数据
bool load(Hash* hash, AVLNode* avl)
{
    ifstream file_id("id.dat");
    if (!file_id) // 文件不存在则创建文件
    {
        ofstream cfile("id.dat");
        cfile.close();
        load(hash, avl);
    }
    vector<unsigned int> id;
    unsigned int value;
    while (file_id >> value) id.push_back(value);
    file_id.close();
    avl = AVLNode::convertToAVLTree(id);
    ifstream file_user("user_management.dat");
    User user;
    if (!file_user) // 文件不存在则创建文件
    {
        ofstream cfile("user_management.dat");
        cfile.close();
        load(hash, nullptr);
    }
    while (file_user.read((char*)&user, sizeof(User)))
    {
        addUser(hash, user, 1);
        hash->count++;
    }
    file_user.close();
    return true;
}