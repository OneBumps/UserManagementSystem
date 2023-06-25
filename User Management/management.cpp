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
            cout << "�û�ID��" << p->data.getId() << endl;
            cout << "�û�����" << p->data.getUsername() << endl;
            cout << "���룺" << p->data.getPassword() << endl;
            puts("----------------");
            p = p->next;
        }
    }
    return 0;
}
bool findUser(Hash* hash, User user, int op = 0) //op=0:�����û���Ϣ��op=1:�����û��Ƿ����
{
    int pos = hashFunction(user.getId());
    Node* p = hash->data[pos];
    if (p == NULL) return false;
    while (p != NULL)
    {
        if (p->data.getId() == user.getId())
        {
            if (op == 1) return true;
            cout << "------�û���Ϣ------" << endl;
            cout << "�û�ID��" << p->data.getId() << endl;
            cout << "�û�����" << p->data.getUsername() << endl;
            cout << "���룺" << p->data.getPassword() << endl;
            //cout << "���ﳵ��" << p->data.getCart() <<endl;
            //cout << "����" << p->data.getOrder() <<endl;
            cout << "--------------------" << endl;
            return true;
        }
        p = p->next;
    }
    return false;
}
bool addUser(Hash* hash, User user, int op = 1) //op=0:�ֶ�����û���op=1:���ļ�����û�
{
    if (op == 0 && findUser(hash, user, 1))
    {
        puts("���û��Ѵ���, �����������");
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
                    cout << "�û��ǳƣ�" << pdel->data.getUsername() << endl;
                    cout << "�û����룺" << pdel->data.getPassword() << endl;
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
    puts("------��ѡ�����------");
    puts("");
    puts("1. �鿴�����û���Ϣ");
    puts("2. ����û�");
    puts("3. ɾ���û�");
    puts("4. �޸��û���Ϣ");
    puts("5. �����û�");
    puts("6. ���沢�˳�");
    puts("");
    puts("----------------------");
}
int main()
{
    puts("���������̳� - �û�����");
    Hash* hash = new Hash();
    if (!load(hash)) return 0;
    while (1)
    {
        menu();
        int op;
        cin >> op;
        switch (op)
        {
        case 1: //�鿴�����û���Ϣ
        {
            show(hash);
            break;
        }
        case 2: //����û�
        {
            puts("------��������û���Ϣ------");
            int id;
            string username;
            string password;
            puts("�������û�ID��");
            cin >> id;
            puts("�������û�����");
            cin >> username;
            puts("���������룺");
            cin >> password;
            User user;
            user.setId(id);
            user.setUsername(username);
            user.setPassword(password);
            if (addUser(hash, user)) puts("��ӳɹ�");
            break;
        }
        case 3: //ɾ���û�
        {
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
            puts("------���ڲ����û���Ϣ------");
            puts("�������û�ID��");
            int id;
            cin >> id;
            change(hash, id);
        }
        break;
        case 5: //�����û�
        {
            puts("------���ڲ����û���Ϣ------");
            puts("�������û�ID��");
            int id;
            cin >> id;
            User user;
            user.setId(id);
            findUser(hash, user);
        }
        break;
        case 6: //���沢�˳�
            if (save(hash)) return 0;
        }
    }
}