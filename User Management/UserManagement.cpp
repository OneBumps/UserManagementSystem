#include "UserManagement.h"
using namespace std;

//����һ��hash��
Hash* createHash()
{
    Hash* pHash = new Hash();
    if (NULL == pHash)
    {
        cout << "����Hash��ʧ��" << endl;
        return NULL;
    }
    memset(pHash, 0, sizeof(Hash));
    return pHash;
}

//hash����
int hashFunc(int key)
{
    int pos;
    pos = key % 13;
    return pos;
}

//��ӹ���
int add(Hash* pHash, data_type pData)
{
    if (pHash == NULL)
    {
        cout << "δ�ҵ�Hash��" << endl;
        return NOEXIST;
    }
    int res = 0;
    res = find(pHash, pData);
    //��ǰ����Ԫ���Ƿ��Ѿ�����
    if (res == OK)
    {
        printf("-----------------------------------------\n");
        printf("��ID��Ӧ��Ա�Ѵ��ڣ������ظ����!\n");
        printf("-----------------------------------------\n");
        return EXIST;
    }
    //����һ���½��
    Node* pNew = new Node();
    if (NULL == pNew)
    {
        perror("malloc error");
        return MALLOCERROR;
    }
    //memset(pNew, 0, sizeof(Node));
    pNew->data = pData;
    int pos = hashFunc(pData.id);
    //�����ú���Ľ��
    pNew->next = pHash->pArr[pos];
    pHash->pArr[pos] = pNew;

    return OK;
}

// ���ҹ���
int find(Hash* pHash, data_type pData)
{
    if (NULL == pHash)
    {
        cout << "δ�ҵ�Hash��" << endl;
        return NOEXIST;
    }
    int pos = hashFunc(pData.id);
    Node* pTmp = NULL;
    pTmp = pHash->pArr[pos];
    if (NULL == pTmp)
    {
        return NOEXIST;
    }
    while (pTmp != NULL)
    {
        if (pData.id == pTmp->data.id)
        {
            printf("IDΪ%d����Ա��Ϣ����:\n", pData.id);
            printf("-----------------------------------------\n");
            printf("ID:%d    ", pTmp->data.id);
            printf("����:%s    ", pTmp->data.name);
            printf("����:%d    ", pTmp->data.age);
            printf("ְλ:%s\n", pTmp->data.status);
            printf("-----------------------------------------\n");
            return OK;
        }
    }
}

int show(Hash* pHash)
{
    if (NULL == pHash)
    {
        perror("malloc error");
        return MALLOCERROR;
    }
    //�������
    int i = 0;
    Node* pTmp = NULL;
    for (i = 0; i < SIZE; i++)
    {
        //�ṹ��ָ��ָ�������׵�ַ
        pTmp = pHash->pArr[i];
        while (pTmp != NULL)
        {
            printf("-----------------------------------------\n");
            printf("ID:%d    ", pTmp->data.id);
            printf("����:%s    ", pTmp->data.name);
            printf("����:%d    ", pTmp->data.age);
            printf("ְλ:%s\n", pTmp->data.status);
            printf("-----------------------------------------\n");
            pTmp = pTmp->next;
        }
    }
    return OK;
}
int del(Hash* pHash, data_type pData)
{
    if (NULL == pHash)
    {
        perror("malloc error");
        return MALLOCERROR;
    }
    int res = 0;
    res = find(pHash, pData);
    if (res != OK)
    {

        printf("-----------------------------------------\n");
        printf("û�и�IDΪ%d����Ա!\n", pData.id);
        printf("-----------------------------------------\n");
        return ERROR;
    }
    if (pData.id < 0)
    {
        return ERROR;
    }
    int pos = hashFunc(pData.id);
    Node* pTmp = NULL;
    pTmp = pHash->pArr[pos];
    Node* pPre = pTmp;
    Node* pDel = pTmp->next;
    if (pData.id = pPre->data.id)
    {
        pDel = pPre;
        pHash->pArr[pos] = pPre->next;
        printf("-----------------------------------------\n");
        printf("ɾ���ɹ�!\n");
        printf("-----------------------------------------\n");
        free(pDel);
        pHash->count--;
        return OK;
    }
    else
    {
        while (NULL != pDel)
            if (pData.id == pDel->data.id)
            {
                pPre->next = pDel->next;
                printf("-----------------------------------------\n");
                printf("ɾ���ɹ�!ɾ����Ա��Ϣ����:\n");
                printf("ID:%d    ", pTmp->data.id);
                printf("����:%s    ", pTmp->data.name);
                printf("����:%d    ", pTmp->data.age);
                printf("ְλ:%s\n", pTmp->data.status);
                printf("-----------------------------------------\n");
                free(pDel);
                return OK;
            }
            else
            {
                pPre = pDel;
                pDel = pDel->next;
            }
    }
    if (NULL == pDel)
    {
        printf("-----------------------------------------\n");
        printf("��ID��Ӧ��Ա��Ϣ������\n");
        printf("-----------------------------------------\n");
    }
    return OK;
}
int change(Hash* pHash, data_type pData)
{
    if (NULL == pHash)
    {
        perror("malloc error");
        return MALLOCERROR;
    }
    if (pData.id < 0)
    {
        return ERROR;
    }
    int res = 0;
    res = find(pHash, pData);
    if (res != OK)
    {
        printf("-----------------------------------------\n");
        printf("û�и�IDΪ%d����Ա!\n", pData.id);
        printf("-----------------------------------------\n");
        return ERROR;
    }
    int pos = hashFunc(pData.id);
    Node* pTmp = NULL;
    pTmp = pHash->pArr[pos];
    while (pTmp->data.id != pData.id)
    {
        pTmp = pTmp->next;
    }
    printf("������IDΪ%d����Ա�޸ĺ������:\n", pData.id);
    scanf("%s", pTmp->data.name);
    printf("������IDΪ%d����Ա�޸ĺ������:\n", pData.id);
    scanf("%d", &pTmp->data.age);
    printf("������IDΪ%d����Ա�޸ĺ��ְλ:\n", pData.id);
    scanf("%s", pTmp->data.status);
    return OK;
}
int destroy(Hash** pHash)
{
    if (NULL == pHash)
    {
        return ERROR;
        printf("-----------------------------------------\n");
        printf("���ٳɹ�!\n");
        printf("-----------------------------------------\n");
    }
    int i;
    Node* pDel = NULL;
    Node* pTmp = NULL;
    for (i = 0; i < SIZE; i++)
    {
        pTmp = (*pHash)->pArr[i];
        while (pTmp != NULL)
        {
            //ͷɾ��
            pDel = pTmp;
            pTmp = pTmp->next;
            free(pDel);
            pDel = NULL;
        }
    }
    free(*pHash);
    *pHash = NULL;
    return OK;
}
int load(Hash* pHash, const char* filename)
{
    data_type infodata;
    if (pHash == NULL)
    {
        perror("malloc error");
        return ERROR;
    }
    int fp = _open(filename, _O_RDONLY); // Changed 'open' to '_open' as recommended by the warning message
    if (fp < 0)
    {
        perror("open error");
        return ERROR;
    }
    while (1)
    {
        int res = _read(fp, &infodata, sizeof(data_type)); // Changed 'read' to '_read' as recommended by the warning message
        if (0 == res)
        {
            std::cout << "��Ϣ�ѵ���!\n";
            break;
        }
        else if (res < 0)
        {
            std::cout << "����ʧ��!\n";
            return ERROR;
        }
        else
        {
            add(pHash, infodata);
            pHash->count++;
        }
    }
    _close(fp); // Changed 'close' to '_close' as recommended by the warning message
    return OK;
}
int save(Hash* pHash, const char* filename)
{
    int fw = _open(filename, _O_WRONLY | _O_CREAT | _O_TRUNC, 0666);
    if (fw < 0)
    {
        perror("open error");
        return ERROR;
    }
    int i;
    for (i = 0; i < SIZE; i++)
    {
        Node* pTmp = pHash->pArr[i];
        while (pTmp != NULL)
        {
            // memset(&pTmp->data,0,sizeof(data_type));
            // write data to the file
            int res = _write(fw, &pTmp->data, sizeof(data_type));
            if (res < 0)
            {
                printf("save error");
            }
            else if (0 == res)
            {
                printf("save error");
                break;
            }
            pTmp = pTmp->next;
        }
    }
    _close(fw);
    return OK;
}

// ��ʾ���˵�
void menu() {
    cout << "���������̳� - �û�����" << endl;
    puts("");
    puts("");
    cout << "1. ���" << endl;
    cout << "2. չʾ" << endl;
    cout << "3. ����" << endl;
    cout << "4. ɾ��" << endl;
    cout << "5. �޸�" << endl;
    cout << "6. ����" << endl;
    cout << "7. ����" << endl;
}
int main()
{
    int op = 0;
    data_type item;
    Hash* pHash = createHash();
    if (pHash == NULL) {
        return ERROR;
    }
    char filename[20] = "info.txt";
    int res = load(pHash, filename);
    if (res == OK) {
        printf("��Ϣ����ɹ�!\n");
    }
    else {
        printf("��Ϣ����ʧ��!\n");
    }
    load(pHash, "info.txt");
    while (true)
    {
        menu();
        int res = 0;
        std::cin >> op;
        if (op == 0)
            break;
        switch (op)
        {
        case 1:
            std::cout << "��������ԱID:" << std::endl;
            std::cin >> item.id;
            std::cout << "��������Ա����:" << std::endl;
            std::cin >> item.name;
            std::cout << "��������Ա����:" << std::endl;
            std::cin >> item.age;
            std::cout << "��������Աְλ:" << std::endl;
            std::cin >> item.status;
            res = add(pHash, item);
            if (res == OK)
            {
                std::cout << "-----------------------------------------" << std::endl;
                std::cout << "��ӳɹ���" << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
            }
            break;
        case 2:
            show(pHash);
            break;
        case 3:
            std::cout << "������Ҫ������Ա��ID:" << std::endl;
            std::cin >> item.id;
            res = find(pHash, item);
            if (res != OK)
            {
                std::cout << "-----------------------------------------" << std::endl;
                std::cout << "û��IDΪ" << item.id << "����Ա!" << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
            }
            break;
        case 4:
            std::cout << "������Ҫɾ����Ա��ID:" << std::endl;
            std::cin >> item.id;
            del(pHash, item);
            break;
        case 5:
            std::cout << "������Ҫ�޸���Ա��ID:" << std::endl;
            std::cin >> item.id;
            res = change(pHash, item);
            if (res == OK)
            {
                std::cout << "-----------------------------------------" << std::endl;
                std::cout << "IDΪ" << item.id << "����Ա�޸���Ϣ�ɹ�!" << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
            }
            break;
        case 6:
            res = destroy(&pHash);
            if (res == OK)
            {
                std::cout << "-----------------------------------------" << std::endl;
                std::cout << "���ٳɹ�!" << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
            }
            break;
        case 7:
            res = save(pHash, "info.txt");
            if (res == OK)
            {
                std::cout << "-----------------------------------------" << std::endl;
                std::cout << "����ɹ�!" << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
            }
            break;
        }
    }
}
