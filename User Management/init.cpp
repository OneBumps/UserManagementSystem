#include <fstream>
#include "Init.h"
#include "management.h"
using namespace std;
// 保存数据到文件
bool save(Hash* hash, int op = 0) //op=0:保存全部数据并退出，op=1:保存并重新加载数据
{
    ofstream file("user_management.dat");
    for (int i = 0; i < SIZE; i++)
    {
        Node* p = hash->data[i];
        while (p != NULL)
        {
            file.write((char*)&p->data, sizeof(User));
            p = p->next;
        }
    }
    if (op == 0)
    {
        file.close();
        return true;
    }
    else if (op == 1)  return load(hash);
}
// 导入文件数据
bool load(Hash* hash)
{
    ifstream file("user_management.dat");
    User user;
    if (!file)
    {
        ofstream cfile("user_management.dat");
        cfile.close();
        load(hash);
    }
    while (file.read((char*)&user, sizeof(User)))
    {
        addUser(hash, user, 1);
        hash->count++;
    }
    file.close();
    return true;
}