#include "Management.h"
#include "init.h"
using namespace std;
int showAll(Hash* hash)
{
    Node* p;
    cout << "ID\t\t用户名\t\t密码\t\t积分\t\t购物车\t\t订单号" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        p = hash->data[i];
        while (p != NULL)
        {
            User::showDetails(p->data, 0);
            p = p->next;
        }
    }
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    return 0;
}
bool findUser(Hash* hash, int id, int op = 0) //op=0:查找用户信息，op=1:查找用户是否存在
{
    int pos = hashFunction(id);
    Node* p = hash->data[pos];
    if (p == NULL) return false;
    while (p != NULL)
    {
        if (p->data.getId() == id)
        {
            if (op == 1) return true;
            system("cls");
            cout << "-----------------------------------------------------------------------------------" << endl;
            cout << "                           用户  " << id << "  详情  " << endl;
            cout << "-----------------------------------------------------------------------------------" << endl;
            User::showDetails(p->data);
            return true;
        }
        p = p->next;
    }
    return false;
}
bool findUser(Hash* hash, string username, int op) //op=0:查找用户信息，op=1:查找用户是否存在
{
    int pos = hashFunction(username);
    Node* p = hash->data[pos];
    if (p == NULL) return false;
    while (p != NULL)
    {
        if (p->data.getUsername() == username)
        {
            if (op == 1) return true;
            system("cls");
            cout << "-----------------------------------------------------------------------------------" << endl;
            cout << "                           用户  " << p->data.getId() << "  详情  " << endl;
            cout << "-----------------------------------------------------------------------------------" << endl;
            User::showDetails(p->data);
            return true;
        }
        p = p->next;
    }
    return false;
}
bool findUser(Hash* hash, int id, User& user)
{
    int pos = hashFunction(id);
    Node* p = hash->data[pos];
    if (p == NULL) return false;
    while (p != NULL)
    {
        if (p->data.getId() == id)
        {
            user.setId(p->data.getId());
            user.setUsername(p->data.getUsername());
            user.setPassword(p->data.getPassword());
            user.setPoints(p->data.getPoints());
            user.setCartId(p->data.getCartId());
            user.setOrderId(p->data.getOrderId());
            return true;
        }
        p = p->next;
    }
    return false;
}
bool addUser(Hash* hash, User user, int op = 1) //op=0:手动添加用户，op=1:从文件添加用户，op=2:用户注册， op=3:测试新的hash函数
{
    if ((op == 0 || op == 2) && findUser(hash, user.getId(), 1))
    {
        if(op == 0) puts("该用户已存在, 不能再添加了");
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
    if (id <= 0 || !findUser(hash, id, 1))
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
    if (id <= 0 && !findUser(hash, id, 0))
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

int hashFunction(int key)
{
    return key % SIZE;
}

int hashFunction(const string& str) {
    // 将字符串转换为Unicode编码序列
    wstring unicodeStr;
    for (size_t i = 0; i < str.length(); i++) {
        unicodeStr += static_cast<wchar_t>(str[i]);
    }
    // 将Unicode编码序列转换为UTF-8字节序列
    string newStr;
    for (size_t i = 0; i < unicodeStr.length(); i++) {
        int codepoint = static_cast<int>(unicodeStr[i]);
        if (codepoint <= 0x7F) {
            newStr += static_cast<char>(codepoint);
        }
        else if (codepoint <= 0x7FF) {
            newStr += static_cast<char>(0xC0 | ((codepoint >> 6) & 0x1F));
            newStr += static_cast<char>(0x80 | (codepoint & 0x3F));
        }
        else if (codepoint <= 0xFFFF) {
            newStr += static_cast<char>(0xE0 | ((codepoint >> 12) & 0x0F));
            newStr += static_cast<char>(0x80 | ((codepoint >> 6) & 0x3F));
            newStr += static_cast<char>(0x80 | (codepoint & 0x3F));
        }
    }
    // 计算哈希值 使用BKDRHash
    int seed = 31;
    int hash = 0;
    for (size_t i = 0; i < newStr.length(); i++) {
        hash = (hash * seed) + newStr[i];
    }
    return hash;
}

void showMenu()
{
    puts("在线零售商城 - 用户中心 - 管理员面板");
    puts(" ------请选择操作------");
    puts("|");
    puts("| 1. 显示所有用户信息");
    puts("| 2. 添加用户");
    puts("| 3. 删除用户");
    puts("| 4. 修改用户信息");
    puts("| 5. 查找用户");
    puts("| 6. 保存并退出");
    puts("| ");
    puts(" ----------------------");
}

void openManagement(Hash* hash)
{
    while (1)
    {
        showMenu();
        int op;
        cin >> op;
        switch (op)
        {
        case 1: //查看所有用户信息
        {
            system("cls");
            puts("在线零售商城 - 用户中心 - 管理员面板");
            showAll(hash);
            break;
        }
        case 2: //导入用户
        {
            system("cls");
            puts("在线零售商城 - 用户中心");
            puts("------正在导入用户信息------");
            unsigned int id;
            string username;
            string password;
            unsigned int points;
            string cartId;
            string orderId;
            printf("用户ID：");
            cin >> id;
            printf("用户名：");
            cin >> username;
            printf("密码：");
            cin >> password;
            printf("积分：");
            cin >> points;
            printf("购物车：");
            cin >> cartId;
            printf("订单号：");
            cin >> orderId;
            User user(id, username, password, points, cartId, orderId);
            if (addUser(hash, user, 0)) puts("添加成功");
            break;
        }
        case 3: //删除用户
        {
            system("cls");
            puts("在线零售商城 - 用户中心 - 管理员面板");
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
            system("cls");
            puts("在线零售商城 - 用户中心 - 管理员面板");
            puts("------正在查找用户信息------");
            puts("请输入用户ID：");
            int id;
            cin >> id;
            change(hash, id);
        }
        break;
        case 5: //查找用户
        {
            system("cls");
            puts("在线零售商城 - 用户中心 - 管理员面板");
            puts("------正在查找用户信息------");
            puts("请输入用户ID：");
            int id;
            cin >> id;
            findUser(hash, id);
        }
        break;
        case 6: //保存并退出
            if (save(hash, 0))
            {
                system("cls");
                puts("已正常关闭系统，所有数据已保存");
                return;
            }
        default:
            system("cls");
        }
    }
}