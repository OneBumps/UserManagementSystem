#include <iostream>
#include "UserFrame.h"
using namespace std;
void showUserFrame(User user)
{
    puts("在线零售商城 - 用户中心");
    cout << user.getUsername() << " 用户下午好！" << endl;
    puts(" ------请选择操作------");
    puts("|");
    puts("| 1. 购物车");
    puts("| 2. 订单");
    puts("| 3. 积分");
    puts("| 4. 修改个人信息");
    puts("| 5. 查找其它用户");
    puts("| 6. 退出登录");
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