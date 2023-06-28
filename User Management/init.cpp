#include <fstream>
#include "Init.h"
#include "management.h"
using namespace std;
// �������ݵ��ļ�
bool save(Hash* hash, AVLNode*& root, int op) //op=0:����ȫ�����ݲ��˳���op=1:���沢���¼�������
{
    vector<pair<unsigned, int>> value = AVLNode::convertToSortedArray(root); // ��AVL��ת��Ϊ��������
    ofstream file_id("id.dat");
    for (pair<unsigned, int> v : value) file_id << v.first << " " << v.second << " "; // ����������д���ļ�
    file_id.close();
    ofstream file_user("user_management.dat");
    for (int i = 0; i < SIZE; i++)
    {
        Node* p = hash->data[i];
        while (p != NULL)
        {
            // ����ϣ���е�����д���ļ�
            file_user.write((char*)&p->data, sizeof(User));
            p = p->next;
        }
    }
    if (op == 0) file_user.close();
    return true;
}
// �����ļ�����
bool load(Hash* hash, AVLNode*& avl)
{
    ifstream file_id("id.dat");
    if (!file_id) // �ļ��������򴴽��ļ�
    {
        ofstream cfile("id.dat");
        cfile.close();
        load(hash, avl);
    }
    vector<pair<unsigned, int>> id;
    unsigned int value;
    int pos;
    while (file_id >> value >> pos) id.push_back(make_pair(value, pos));// ���ļ��ж�ȡ����
    file_id.close();
    avl = AVLNode::convertToAVLTree(id);// �����ݵ���AVL��
    ifstream file_user("user_management.dat");
    User user;
    if (!file_user) // �ļ��������򴴽��ļ�
    {
        ofstream cfile("user_management.dat");
        cfile.close();
        load(hash, avl);
    }
    while (file_user.read((char*)&user, sizeof(User)))
    {
        // �ļ����ݵ����ϣ��
        addUser(hash, user, avl, 1);
        hash->count++;
    }
    file_user.close();
    return true;
}