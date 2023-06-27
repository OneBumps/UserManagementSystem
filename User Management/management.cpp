#include "Management.h"
#include "init.h"
using namespace std;
int showAll(Hash* hash)
{
    Node* p;
    cout << "ID\t\t�û���\t\t����\t\t����\t\t���ﳵ\t\t������" << endl;
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
bool findUser(Hash* hash, int id, int op = 0) //op=0:�����û���Ϣ��op=1:�����û��Ƿ����
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
            cout << "                           �û�  " << id << "  ����  " << endl;
            cout << "-----------------------------------------------------------------------------------" << endl;
            User::showDetails(p->data);
            return true;
        }
        p = p->next;
    }
    return false;
}
bool findUser(Hash* hash, string username, int op) //op=0:�����û���Ϣ��op=1:�����û��Ƿ����
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
            cout << "                           �û�  " << p->data.getId() << "  ����  " << endl;
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
bool addUser(Hash* hash, User user, int op = 1) //op=0:�ֶ�����û���op=1:���ļ�����û���op=2:�û�ע�ᣬ op=3:�����µ�hash����
{
    if ((op == 0 || op == 2) && findUser(hash, user.getId(), 1))
    {
        if(op == 0) puts("���û��Ѵ���, �����������");
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
        printf("û��IDΪ%d����Ա���޷�ɾ����\n", id);
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
            puts("��   ɾ���ɹ�!  ��");
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
                    puts(" -----------------����ɾ���û�----------------");
                    cout << "�û�ID��" << pdel->data.getId() << endl;
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
        puts("  û������û�  ");
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
                puts("------���޸ĸ��û�����Ϣ------");
                puts("�������µ��û�����");
                string username;
                cin >> username;
                puts("�������µ����룺");
                string password;
                cin >> password;
                p->data.setUsername(username);
                p->data.setPassword(password);
                puts("------�޸ĳɹ�------");
                return true;
            }
            p = p->next;
        }
        puts("�޸�ʧ�ܣ������ԣ�");
        return false;
    }
}

int hashFunction(int key)
{
    return key % SIZE;
}

int hashFunction(const string& str) {
    // ���ַ���ת��ΪUnicode��������
    wstring unicodeStr;
    for (size_t i = 0; i < str.length(); i++) {
        unicodeStr += static_cast<wchar_t>(str[i]);
    }
    // ��Unicode��������ת��ΪUTF-8�ֽ�����
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
    // �����ϣֵ ʹ��BKDRHash
    int seed = 31;
    int hash = 0;
    for (size_t i = 0; i < newStr.length(); i++) {
        hash = (hash * seed) + newStr[i];
    }
    return hash;
}

void showMenu()
{
    puts("���������̳� - �û����� - ����Ա���");
    puts(" ------��ѡ�����------");
    puts("|");
    puts("| 1. ��ʾ�����û���Ϣ");
    puts("| 2. ����û�");
    puts("| 3. ɾ���û�");
    puts("| 4. �޸��û���Ϣ");
    puts("| 5. �����û�");
    puts("| 6. ���沢�˳�");
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
        case 1: //�鿴�����û���Ϣ
        {
            system("cls");
            puts("���������̳� - �û����� - ����Ա���");
            showAll(hash);
            break;
        }
        case 2: //�����û�
        {
            system("cls");
            puts("���������̳� - �û�����");
            puts("------���ڵ����û���Ϣ------");
            unsigned int id;
            string username;
            string password;
            unsigned int points;
            string cartId;
            string orderId;
            printf("�û�ID��");
            cin >> id;
            printf("�û�����");
            cin >> username;
            printf("���룺");
            cin >> password;
            printf("���֣�");
            cin >> points;
            printf("���ﳵ��");
            cin >> cartId;
            printf("�����ţ�");
            cin >> orderId;
            User user(id, username, password, points, cartId, orderId);
            if (addUser(hash, user, 0)) puts("��ӳɹ�");
            break;
        }
        case 3: //ɾ���û�
        {
            system("cls");
            puts("���������̳� - �û����� - ����Ա���");
            while (1)
            {
                puts("------����ɾ���û���Ϣ------");
                int id;
                puts("�������û�ID:");
                cin >> id;
                if (delUser(hash, id)) puts("��Ҫɾ����?[yes/no]");
                else puts("ɾ��ʧ�ܣ���Ҫ������?[yes/no]");
                string op3;
                cin >> op3;
                if (op3 != "yes") break;
            }
        }
        case 4: //�޸��û���Ϣ
        {
            system("cls");
            puts("���������̳� - �û����� - ����Ա���");
            puts("------���ڲ����û���Ϣ------");
            puts("�������û�ID��");
            int id;
            cin >> id;
            change(hash, id);
        }
        break;
        case 5: //�����û�
        {
            system("cls");
            puts("���������̳� - �û����� - ����Ա���");
            puts("------���ڲ����û���Ϣ------");
            puts("�������û�ID��");
            int id;
            cin >> id;
            findUser(hash, id);
        }
        break;
        case 6: //���沢�˳�
            if (save(hash, 0))
            {
                system("cls");
                puts("�������ر�ϵͳ�����������ѱ���");
                return;
            }
        default:
            system("cls");
        }
    }
}