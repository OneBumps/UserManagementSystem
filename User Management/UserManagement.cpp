//#include "UserManagement.h"
//using namespace std;
//
////����һ��hash��
//Hash* createHash()
//{
//    Hash* pHash = new Hash();
//    if (NULL == pHash)
//    {
//        cout << "���������ʧ��" << endl;
//        return NULL;
//    }
//    memset(pHash, 0, sizeof(Hash));
//    return pHash;
//}
//
////hash����
//int hashFunc(int key)
//{
//    int pos;
//    pos = key % 13;
//    return pos;
//}
//
////��ӹ���
//int add(Hash* pHash, User pData)
//{
//    if (pHash == NULL)
//    {
//        cout << "δ�ҵ�Hash��" << endl;
//        return NOEXIST;
//    }
//    int res = 0;
//    res = findUser(pHash, pData);
//    //��ǰ����Ԫ���Ƿ��Ѿ�����
//    if (res == OK)
//    {
//        printf("-----------------------------------------\n");
//        printf("��ID��Ӧ��Ա�Ѵ��ڣ������ظ����!\n");
//        printf("-----------------------------------------\n");
//        return EXIST;
//    }
//    //����һ���½��
//    Node* pNew = new Node();
//    if (NULL == pNew)
//    {
//        perror("malloc error");
//        return MALLOCERROR;
//    }
//    //memset(pNew, 0, sizeof(Node));
//    pNew->data = pData;
//    int pos = hashFunc(pData.id);
//    //�����ú���Ľ��
//    pNew->next = pHash->pArr[pos];
//    pHash->pArr[pos] = pNew;
//
//    return OK;
//}
//
//// ���ҹ���
//int findUser(Hash* pHash, User pData)
//{
//    if (NULL == pHash)
//    {
//        cout << "δ�ҵ�Hash��" << endl;
//        return NOEXIST;
//    }
//    int pos = hashFunc(pData.id);
//    Node* pTmp = NULL;
//    pTmp = pHash->pArr[pos];
//    if (NULL == pTmp)
//    {
//        return NOEXIST;
//    }
//    while (pTmp != NULL)
//    {
//        if (pData.id == pTmp->data.id)
//        {
//            printf("IDΪ%d����Ա��Ϣ����:\n", pData.id);
//            printf("-----------------------------------------\n");
//            printf("ID:%d    ", pTmp->data.id);
//            printf("����:%s    ", pTmp->data.name);
//            printf("����:%d    ", pTmp->data.age);
//            printf("ְλ:%s\n", pTmp->data.status);
//            printf("-----------------------------------------\n");
//            return OK;
//        }
//    }
//}
//
//int show(Hash* pHash)
//{
//    if (NULL == pHash)
//    {
//        perror("malloc error");
//        return MALLOCERROR;
//    }
//    //�������
//    int i = 0;
//    Node* pTmp = NULL;
//    for (i = 0; i < SIZE; i++)
//    {
//        //�ṹ��ָ��ָ�������׵�ַ
//        pTmp = pHash->pArr[i];
//        while (pTmp != NULL)
//        {
//            printf("-----------------------------------------\n");
//            printf("ID:%d    ", pTmp->data.id);
//            printf("����:%s    ", pTmp->data.name);
//            printf("����:%d    ", pTmp->data.age);
//            printf("ְλ:%s\n", pTmp->data.status);
//            printf("-----------------------------------------\n");
//            pTmp = pTmp->next;
//        }
//    }
//    return OK;
//}
//int delUser(Hash* pHash, User pData)
//{
//    int res = 0;
//    res = findUser(pHash, pData);
//    if (res != OK)
//    {
//        printf("-----------------------------------------\n");
//        printf("û�и�IDΪ%d����Ա!\n", pData.id);
//        printf("-----------------------------------------\n");
//        return ERROR;
//    }
//
//    if (pData.id < 0)
//    {
//        return ERROR;
//    }
//
//    int pos = hashFunc(pData.id);
//    Node* pTmp = pHash->pArr[pos];
//    Node* pPre = pTmp;
//    Node* pDel = pTmp->next;
//
//    if (pData.id == pPre->data.id)
//    {
//        pHash->pArr[pos] = pPre->next;
//        printf("-----------------------------------------\n");
//        printf("ɾ���ɹ�!\n");
//        printf("-----------------------------------------\n");
//        free(pPre);
//        pHash->count--;
//        return OK;
//    }
//    else
//    {
//        while (NULL != pDel)
//        {
//            if (pData.id == pDel->data.id)
//            {
//                pPre->next = pDel->next;
//                printf("-----------------------------------------\n");
//                printf("ɾ���ɹ�!ɾ����Ա��Ϣ����:\n");
//                printf("ID:%d    ", pDel->data.id);
//                printf("����:%s    ", pDel->data.name);
//                printf("����:%d    ", pDel->data.age);
//                printf("ְλ:%s\n", pDel->data.status);
//                printf("-----------------------------------------\n");
//                free(pDel);
//                pHash->count--;
//                return OK;
//            }
//            else
//            {
//                pPre = pDel;
//                pDel = pDel->next;
//            }
//        }
//    }
//
//    if (NULL == pDel)
//    {
//        printf("-----------------------------------------\n");
//        printf("��ID��Ӧ��Ա��Ϣ������\n");
//        printf("-----------------------------------------\n");
//    }
//
//    return OK;
//}
//int change(Hash* pHash, User pData)
//{
//    if (NULL == pHash)
//    {
//        perror("malloc error");
//        return MALLOCERROR;
//    }
//    if (pData.id < 0)
//    {
//        return ERROR;
//    }
//    int res = 0;
//    res = findUser(pHash, pData);
//    if (res != OK)
//    {
//        printf("-----------------------------------------\n");
//        printf("û�и�IDΪ%d����Ա!\n", pData.id);
//        printf("-----------------------------------------\n");
//        return ERROR;
//    }
//    int pos = hashFunc(pData.id);
//    Node* pTmp = NULL;
//    pTmp = pHash->pArr[pos];
//    while (pTmp->data.id != pData.id)
//    {
//        pTmp = pTmp->next;
//    }
//    printf("������IDΪ%d����Ա�޸ĺ������:\n", pData.id);
//    scanf("%s", pTmp->data.name);
//    printf("������IDΪ%d����Ա�޸ĺ������:\n", pData.id);
//    scanf("%d", &pTmp->data.age);
//    printf("������IDΪ%d����Ա�޸ĺ��ְλ:\n", pData.id);
//    scanf("%s", pTmp->data.status);
//    return OK;
//}
//int destroy(Hash** pHash)
//{
//    if (NULL == pHash)
//    {
//        return ERROR;
//        printf("-----------------------------------------\n");
//        printf("���ٳɹ�!\n");
//        printf("-----------------------------------------\n");
//    }
//    int i;
//    Node* pDel = NULL;
//    Node* pTmp = NULL;
//    for (i = 0; i < SIZE; i++)
//    {
//        pTmp = (*pHash)->pArr[i];
//        while (pTmp != NULL)
//        {
//            //ͷɾ��
//            pDel = pTmp;
//            pTmp = pTmp->next;
//            free(pDel);
//            pDel = NULL;
//        }
//    }
//    free(*pHash);
//    *pHash = NULL;
//    return OK;
//}
//// �����û���Ϣ�ļ�
//int load(Hash* pHash, const char* filename)
//{
//    User userInfo;
//    int fp = open(filename, O_RDONLY);
//    if (fp < 0)
//    {
//        cout << "���ڽ����û���Ϣ�����ļ�" << endl;
//        return ERROR;
//    }
//    while (1)
//    {
//        int res = read(fp, &userInfo, sizeof(User));
//        if (0 == res) break;
//        else if (res < 0)
//        {
//            cout << "����ʧ��!\n";
//            return ERROR;
//        }
//        else
//        {
//            add(pHash, userInfo);
//            pHash->count++;
//        }
//    }
//    close(fp);
//    return OK;
//}
//int save(Hash* pHash, const char* filename)
//{
//    int fw = _open(filename, _O_WRONLY | _O_CREAT | _O_TRUNC, 0666);
//    if (fw < 0)
//    {
//        perror("open error");
//        return ERROR;
//    }
//    int i;
//    for (i = 0; i < SIZE; i++)
//    {
//        Node* pTmp = pHash->pArr[i];
//        while (pTmp != NULL)
//        {
//            // memset(&pTmp->data,0,sizeof(data_type));
//            // write data to the file
//            int res = _write(fw, &pTmp->data, sizeof(User));
//            if (res < 0)
//            {
//                printf("save error");
//            }
//            else if (0 == res)
//            {
//                printf("save error");
//                break;
//            }
//            pTmp = pTmp->next;
//        }
//    }
//    _close(fw);
//    return OK;
//}
//
//// ��ʾ���˵�
//void menu() {
//    puts("");
//    puts("");
//    cout << "1. ���" << endl;
//    cout << "2. չʾ" << endl;
//    cout << "3. ����" << endl;
//    cout << "4. ɾ��" << endl;
//    cout << "5. �޸�" << endl;
//    cout << "6. ����" << endl;
//    cout << "7. ����" << endl;
//}
//int mains()
//{
//    cout << "���������̳� - �û�����" << endl;
//    //��ʼ��ѡ��
//    int op = 0;
//    //�����û�����
//    User user;
//    //����Hash��
//    Hash* pHash = createHash();
//    if (pHash == NULL) {
//        return ERROR;
//    }
//    char filename[20] = "user.txt";
//    if (load(pHash, filename) != OK) {
//        cout << "�û���Ϣ��ȡʧ��" << endl;
//    }
//    load(pHash, "user.txt");
//    while (true)
//    {
//        menu();
//        int res = 0;
//        std::cin >> op;
//        if (op == 0)
//            break;
//        switch (op)
//        {
//        case 1:
//            cout << "�������û�ID:" << endl;
//            std::cin >> user.id;
//            cout << "�������û��ǳ�:" << endl;
//            std::cin >> user.name;
//            cout << "��������Ա����:" << endl;
//            std::cin >> user.age;
//            cout << "��������Աְλ:" << endl;
//            std::cin >> user.status;
//            res = add(pHash, user);
//            if (res == OK)
//            {
//                cout << "-----------------------------------------" << endl;
//                cout << "��ӳɹ���" << endl;
//                cout << "-----------------------------------------" << endl;
//            }
//            break;
//        case 2:
//            show(pHash);
//            break;
//        case 3:
//            cout << "������Ҫ������Ա��ID:" << endl;
//            std::cin >> user.id;
//            res = findUser(pHash, user);
//            if (res != OK)
//            {
//                cout << "-----------------------------------------" << endl;
//                cout << "û��IDΪ" << user.id << "����Ա!" << endl;
//                cout << "-----------------------------------------" << endl;
//            }
//            break;
//        case 4:
//            cout << "������Ҫɾ����Ա��ID:" << endl;
//            std::cin >> user.id;
//            delUser(pHash, user);
//            break;
//        case 5:
//            cout << "������Ҫ�޸���Ա��ID:" << endl;
//            std::cin >> user.id;
//            res = change(pHash, user);
//            if (res == OK)
//            {
//                cout << "-----------------------------------------" << endl;
//                cout << "IDΪ" << user.id << "����Ա�޸���Ϣ�ɹ�!" << endl;
//                cout << "-----------------------------------------" << endl;
//            }
//            break;
//        case 6:
//            res = destroy(&pHash);
//            if (res == OK)
//            {
//                cout << "-----------------------------------------" << endl;
//                cout << "���ٳɹ�!" << endl;
//                cout << "-----------------------------------------" << endl;
//            }
//            break;
//        case 7:
//            res = save(pHash, "user.txt");
//            if (res == OK)
//            {
//                cout << "-----------------------------------------" << endl;
//                cout << "����ɹ�!" << endl;
//                cout << "-----------------------------------------" << endl;
//            }
//            break;
//        }
//    }
//}
