#include <iostream>
#include "UserFrame.h"
using namespace std;
void showUserFrame(User user)
{
    puts("���������̳� - �û�����");
    cout << user.getUsername() << " �û�����ã�" << endl;
    puts(" ------��ѡ�����------");
    puts("|");
    puts("| 1. ���ﳵ");
    puts("| 2. ����");
    puts("| 3. ����");
    puts("| 4. �޸ĸ�����Ϣ");
    puts("| 5. ���������û�");
    puts("| 6. �˳���¼");
    puts("| ");
    puts(" ----------------------");
    int choose;
    cin >> choose;
    if (choose == 6)
    {
        system("cls");
        return;
    }
}