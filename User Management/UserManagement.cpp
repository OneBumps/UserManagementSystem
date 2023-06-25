//#include "UserManagement.h"
//using namespace std;
//
////创建一个hash表
//Hash* createHash()
//{
//    Hash* pHash = new Hash();
//    if (NULL == pHash)
//    {
//        cout << "创建管理表失败" << endl;
//        return NULL;
//    }
//    memset(pHash, 0, sizeof(Hash));
//    return pHash;
//}
//
////hash函数
//int hashFunc(int key)
//{
//    int pos;
//    pos = key % 13;
//    return pos;
//}
//
////添加功能
//int add(Hash* pHash, User pData)
//{
//    if (pHash == NULL)
//    {
//        cout << "未找到Hash表" << endl;
//        return NOEXIST;
//    }
//    int res = 0;
//    res = findUser(pHash, pData);
//    //当前数据元素是否已经存在
//    if (res == OK)
//    {
//        printf("-----------------------------------------\n");
//        printf("该ID对应人员已存在，请勿重复添加!\n");
//        printf("-----------------------------------------\n");
//        return EXIST;
//    }
//    //创建一个新结点
//    Node* pNew = new Node();
//    if (NULL == pNew)
//    {
//        perror("malloc error");
//        return MALLOCERROR;
//    }
//    //memset(pNew, 0, sizeof(Node));
//    pNew->data = pData;
//    int pos = hashFunc(pData.id);
//    //保护好后面的结点
//    pNew->next = pHash->pArr[pos];
//    pHash->pArr[pos] = pNew;
//
//    return OK;
//}
//
//// 查找功能
//int findUser(Hash* pHash, User pData)
//{
//    if (NULL == pHash)
//    {
//        cout << "未找到Hash表" << endl;
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
//            printf("ID为%d的人员信息如下:\n", pData.id);
//            printf("-----------------------------------------\n");
//            printf("ID:%d    ", pTmp->data.id);
//            printf("姓名:%s    ", pTmp->data.name);
//            printf("年龄:%d    ", pTmp->data.age);
//            printf("职位:%s\n", pTmp->data.status);
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
//    //遍历输出
//    int i = 0;
//    Node* pTmp = NULL;
//    for (i = 0; i < SIZE; i++)
//    {
//        //结构体指针指向链表首地址
//        pTmp = pHash->pArr[i];
//        while (pTmp != NULL)
//        {
//            printf("-----------------------------------------\n");
//            printf("ID:%d    ", pTmp->data.id);
//            printf("姓名:%s    ", pTmp->data.name);
//            printf("年龄:%d    ", pTmp->data.age);
//            printf("职位:%s\n", pTmp->data.status);
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
//        printf("没有该ID为%d的人员!\n", pData.id);
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
//        printf("删除成功!\n");
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
//                printf("删除成功!删除人员信息如下:\n");
//                printf("ID:%d    ", pDel->data.id);
//                printf("姓名:%s    ", pDel->data.name);
//                printf("年龄:%d    ", pDel->data.age);
//                printf("职位:%s\n", pDel->data.status);
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
//        printf("此ID对应人员信息不存在\n");
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
//        printf("没有该ID为%d的人员!\n", pData.id);
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
//    printf("请输入ID为%d的人员修改后的名字:\n", pData.id);
//    scanf("%s", pTmp->data.name);
//    printf("请输入ID为%d的人员修改后的年龄:\n", pData.id);
//    scanf("%d", &pTmp->data.age);
//    printf("请输入ID为%d的人员修改后的职位:\n", pData.id);
//    scanf("%s", pTmp->data.status);
//    return OK;
//}
//int destroy(Hash** pHash)
//{
//    if (NULL == pHash)
//    {
//        return ERROR;
//        printf("-----------------------------------------\n");
//        printf("销毁成功!\n");
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
//            //头删法
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
//// 加载用户信息文件
//int load(Hash* pHash, const char* filename)
//{
//    User userInfo;
//    int fp = open(filename, O_RDONLY);
//    if (fp < 0)
//    {
//        cout << "正在建立用户信息数据文件" << endl;
//        return ERROR;
//    }
//    while (1)
//    {
//        int res = read(fp, &userInfo, sizeof(User));
//        if (0 == res) break;
//        else if (res < 0)
//        {
//            cout << "导入失败!\n";
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
//// 显示主菜单
//void menu() {
//    puts("");
//    puts("");
//    cout << "1. 添加" << endl;
//    cout << "2. 展示" << endl;
//    cout << "3. 查找" << endl;
//    cout << "4. 删除" << endl;
//    cout << "5. 修改" << endl;
//    cout << "6. 销毁" << endl;
//    cout << "7. 保存" << endl;
//}
//int mains()
//{
//    cout << "在线零售商城 - 用户中心" << endl;
//    //初始化选项
//    int op = 0;
//    //创建用户对象
//    User user;
//    //建立Hash表
//    Hash* pHash = createHash();
//    if (pHash == NULL) {
//        return ERROR;
//    }
//    char filename[20] = "user.txt";
//    if (load(pHash, filename) != OK) {
//        cout << "用户信息获取失败" << endl;
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
//            cout << "请输入用户ID:" << endl;
//            std::cin >> user.id;
//            cout << "请输入用户昵称:" << endl;
//            std::cin >> user.name;
//            cout << "请输入人员年龄:" << endl;
//            std::cin >> user.age;
//            cout << "请输入人员职位:" << endl;
//            std::cin >> user.status;
//            res = add(pHash, user);
//            if (res == OK)
//            {
//                cout << "-----------------------------------------" << endl;
//                cout << "添加成功！" << endl;
//                cout << "-----------------------------------------" << endl;
//            }
//            break;
//        case 2:
//            show(pHash);
//            break;
//        case 3:
//            cout << "请输入要查找人员的ID:" << endl;
//            std::cin >> user.id;
//            res = findUser(pHash, user);
//            if (res != OK)
//            {
//                cout << "-----------------------------------------" << endl;
//                cout << "没有ID为" << user.id << "的人员!" << endl;
//                cout << "-----------------------------------------" << endl;
//            }
//            break;
//        case 4:
//            cout << "请输入要删除人员的ID:" << endl;
//            std::cin >> user.id;
//            delUser(pHash, user);
//            break;
//        case 5:
//            cout << "请输入要修改人员的ID:" << endl;
//            std::cin >> user.id;
//            res = change(pHash, user);
//            if (res == OK)
//            {
//                cout << "-----------------------------------------" << endl;
//                cout << "ID为" << user.id << "的人员修改信息成功!" << endl;
//                cout << "-----------------------------------------" << endl;
//            }
//            break;
//        case 6:
//            res = destroy(&pHash);
//            if (res == OK)
//            {
//                cout << "-----------------------------------------" << endl;
//                cout << "销毁成功!" << endl;
//                cout << "-----------------------------------------" << endl;
//            }
//            break;
//        case 7:
//            res = save(pHash, "user.txt");
//            if (res == OK)
//            {
//                cout << "-----------------------------------------" << endl;
//                cout << "保存成功!" << endl;
//                cout << "-----------------------------------------" << endl;
//            }
//            break;
//        }
//    }
//}
