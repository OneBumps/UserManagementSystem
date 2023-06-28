#include <fstream>
#include "Init.h"
#include "management.h"
using namespace std;
// �������ݵ��ļ�
bool save(Hash* hash, const vector<unsigned int>& id, int op) //op=0:����ȫ�����ݲ��˳���op=1:���沢���¼�������
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
// �����ļ�����
bool load(Hash* hash, AVLNode* avl)
{
    ifstream file_id("id.dat");
    if (!file_id) // �ļ��������򴴽��ļ�
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
    if (!file_user) // �ļ��������򴴽��ļ�
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