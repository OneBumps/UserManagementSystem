#include "management.h"
int show(Hash* hash)
{
    Node* p;
    for (int i = 0; i < SIZE; i++)
    {
        p = hash->data[i];
        while (p != NULL)
        {
            puts("----------------");
            cout << "用户ID：" << p->data.getId() << endl;
            cout << "用户名：" << p->data.getUsername() << endl;
            cout << "密码：" << p->data.getPassword() << endl;
            puts("----------------");
            p = p->next;
        }
    }
    return 0;
}
bool findUser(Hash* hash, User user, int op = 0) //op=0:查找用户信息，op=1:查找用户是否存在
{
    int pos = hashFunction(user.getId());
    Node* p = hash->data[pos];
    if (p == NULL) return false;
    while (p != NULL)
    {
        if (p->data.getId() == user.getId())
        {
            if (op == 1) return true;
            cout << "------用户信息------" << endl;
            cout << "用户ID：" << p->data.getId() << endl;
            cout << "用户名：" << p->data.getUsername() << endl;
            cout << "密码：" << p->data.getPassword() << endl;
            //cout << "购物车：" << p->data.getCart() <<endl;
            //cout << "订单" << p->data.getOrder() <<endl;
            cout << "--------------------" << endl;
            return true;
        }
        p = p->next;
    }
    return false;
}
bool addUser(Hash* hash, User user, int op = 1) //op=0:手动添加用户，op=1:从文件添加用户
{
    if (op == 0 && findUser(hash, user, 1))
    {
        puts("该用户已存在, 不能再添加了");
        return false;
    }
    Node* p = new Node();
    p->data = user;
    int pos = hashFunction(user.getId());
    p->next = hash->data[pos];
    hash->data[pos] = p;
    return true;
}
bool delUser(Hash* hash, int id)
{
    User user;
    user.setId(id);
    if (id <= 0 || !findUser(hash, user, 1))
    {
        puts("------------");
        printf("没有ID为%d的人员，无法删除！\n", id);
        puts("------------");
        return false;
    }
    else
    {
        int pos = hashFunction(id);
        Node* p = hash->data[pos];
        Node* ppre = p;
        Node* pdel = p->next;
        if (id == ppre->data.getId())
        {
            pdel = ppre;
            hash->data[pos] = ppre->next;
            puts(" ---------------");
            puts("︱   删除成功!  ︱");
            puts(" ---------------");
            delete pdel;
            hash->count--;
            return true;
        }
        else
        {
            while (pdel != NULL)
            {
                if (id == pdel->data.getId())
                {
                    ppre->next = pdel->next;
                    puts(" --------------------------------------------");
                    puts(" -----------------您已删除用户----------------");
                    cout << "用户ID：" << pdel->data.getId() << endl;
                    cout << "用户昵称：" << pdel->data.getUsername() << endl;
                    cout << "用户密码：" << pdel->data.getPassword() << endl;
                    puts(" --------------------------------------------");
                    delete pdel;
                    hash->count--;
                    return true;
                }
                ppre = pdel;
                pdel = pdel->next;
            }
        }
    }
}
bool change(Hash* hash, int id)
{
    User user;
    user.setId(id);
    if (id <= 0 && !findUser(hash, user, 0))
    {
        puts("---------------");
        puts("  没有这个用户  ");
        puts("---------------");
        return false;
    }
    else
    {
        int pos = hashFunction(id);
        Node* p = hash->data[pos];
        while (p != NULL)
        {
            if (id == p->data.getId())
            {
                puts("");
                puts("------请修改该用户的信息------");
                puts("请输入新的用户名：");
                string username;
                cin >> username;
                puts("请输入新的密码：");
                string password;
                cin >> password;
                p->data.setUsername(username);
                p->data.setPassword(password);
                puts("------修改成功------");
                return true;
            }
            p = p->next;
        }
        puts("修改失败，请重试！");
        return false;
    }
}
bool save(Hash* hash)
{
    ofstream file("user_management.txt");
    for (int i = 0; i < SIZE; i++)
    {
        Node* p = hash->data[i];
        while (p != NULL)
        {
            file.write((char*)&p->data, sizeof(User));
            p = p->next;
        }
    }
    file.close();
    return true;
}

bool load(Hash* hash)
{
    ifstream file("user_management.txt");
    User user;
    if (!file) return false;
    while (file.read((char*)&user, sizeof(User)))
    {
        addUser(hash, user, 1);
        hash->count++;
    }
    file.close();
    return true;
}
int hashFunction(int key)
{
    return key % SIZE;
}
void menu()
{
    puts("------请选择操作------");
    puts("");
    puts("1. 查看所有用户信息");
    puts("2. 添加用户");
    puts("3. 删除用户");
    puts("4. 修改用户信息");
    puts("5. 查找用户");
    puts("6. 保存并退出");
    puts("");
    puts("----------------------");
}
int main()
{
    puts("在线零售商城 - 用户中心");
    Hash* hash = new Hash();
    if (!load(hash)) return 0;
    while (1)
    {
        menu();
        int op;
        cin >> op;
        switch (op)
        {
        case 1: //查看所有用户信息
        {
            show(hash);
            break;
        }
        case 2: //添加用户
        {
            puts("------正在添加用户信息------");
            int id;
            string username;
            string password;
            puts("请输入用户ID：");
            cin >> id;
            puts("请输入用户名：");
            cin >> username;
            puts("请输入密码：");
            cin >> password;
            User user;
            user.setId(id);
            user.setUsername(username);
            user.setPassword(password);
            if (addUser(hash, user)) puts("添加成功");
            break;
        }
        case 3: //删除用户
        {
            while (1)
            {
                puts("------正在删除用户信息------");
                int id;
                puts("请输入用户ID:");
                cin >> id;
                if (delUser(hash, id)) puts("还要删除吗?[yes/no]");
                else puts("删除失败！还要尝试吗?[yes/no]");
                string op3;
                cin >> op3;
                if (op3 != "yes") break;
            }
        }
        case 4: //修改用户信息
        {
            puts("------正在查找用户信息------");
            puts("请输入用户ID：");
            int id;
            cin >> id;
            change(hash, id);
        }
        break;
        case 5: //查找用户
        {
            puts("------正在查找用户信息------");
            puts("请输入用户ID：");
            int id;
            cin >> id;
            User user;
            user.setId(id);
            findUser(hash, user);
        }
        break;
        case 6: //保存并退出
            if (save(hash)) return 0;
        }
    }
}