#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef STUDY_1_H
#include "study_1.h"
#endif

#ifndef STUDY_FUNCTION_H
#include "study_function.h"
#endif

FILE *userNamePasswdFile;       //保存用户账号密码的文件

// 使用“结构”来定义“端口类型”
struct port {
    char name[16];
    int status; // 1 激活 0 禁止
    char ip[16];
    char type[4]; // wan , lan
};

// 端口初始化
void init_port(struct port *port)
{
    strcpy(port->name, "--NULL--");
    strcpy(port->ip, "0.0.0.0");
    strcpy(port->type, "LAN");
    port->status = 0;
}

// 初始化函数
void init()
{
    //打开文件
    userNamePasswdFile = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
    if(!userNamePasswdFile) {     // 等效于 file = NULL
        printf("文件打开失败\n");
        exit(1);
    }
}

// 用户的账号密码验证
void login()
{
    char name[32];      //输入的用户名
    char passwd[32];    //输入的密码

    char line[128];
    char nameCompare[32];   //用于比较的用户名
    char passwdCompare[32]; //用于比较的密码
    char *getsUsersTxtLineResult;   //users.txt文件fgets读取一行的返回值
    while (1) {

        printf("请输入用户名：");
        scanf("%s", name);
        printf(("请输入密码："));
        scanf("%s", passwd);
        // 清空缓冲区
        fflush(stdin);

        // 与特定的账号和密码进行比较
        /*if(strcmp(name, "admin") == 0 && strcmp(passwd, "123456") ==0) {
            break;
        } else {
            printf("用户名或者密码错误\n");
            system("pause");
            system("cls");
        }*/

        // 从文件中读取账号，并进行判断
        while (1) {
            // 读一行
            getsUsersTxtLineResult = fgets(line, sizeof (line), userNamePasswdFile);       // line :   "admin   12345\n"
            sscanf(line, "%s %s", nameCompare, passwdCompare);
            if(!getsUsersTxtLineResult) {
                break;
            }
            if(!strcmp(name, nameCompare) && !strcmp(passwd, passwdCompare)) {
                break;
            }
        }
        if (getsUsersTxtLineResult) {   //用户名密码匹配成功
            break;
        } else {    //匹配失败
            printf("用户名或者密码错误\n");
            system("pause");
            system("cls");
            fseek(userNamePasswdFile, 0, SEEK_SET); // 将文件内部的位置指针设置到文件头
        }
    }

}

//主菜单页面
void show_menu()
{
    // 主菜单界面
    system("cls");
    printf("---交换机管理系统---\n");
    printf("1、创建账号\n");
    printf("2、ip管理\n");
    printf("3、端口管理\n");
    printf("4、--退出--\n");
    printf("请选择：");
}

// 账号管理
void create_user()
{
    system("cls");
    printf("1、创建账号\n");
    printf("按任意键返回主菜单\n");
    getchar();
}

//ip 管理
void ip_manager()
{
    system("cls");
    printf("2、ip管理\n");
    printf("按任意键返回主菜单\n");
    getchar();
}

// 退出账号
void logout()
{
    fclose(userNamePasswdFile);
    system("cls");
    exit(0);
}

void input_error()
{
    system("cls");
    printf("请输入有效的菜单选项\n");
    printf("按任意键返回主菜单\n");
    getchar();
}

// 查看端口
void show_port(struct port *port)
{
    printf("name:%-16s\t status:%s\t ip:%-16s\t type:%-4s \n", port->name,
           port->status ? "激活" : "禁止", port->ip, port->type);
}
void show_ports(struct port *ports)
{
    struct port *port = ports;
    system("cls");
    for (int i=0; i<5; i++) {
        printf("PORT%d\t", i+1);
        show_port(ports++);
    }
    system("pause");
}

// 设置端口
void set_port(struct port *port)
{
    printf("请输入端口的名称：");
    scanf("%s", port->name);
    printf("请输入端口的状态：");
    scanf("%d", &(port->status));
    printf("请输入端口的ip：");
    scanf("%s", port->ip);
    printf("请输入端口的类型：");
    scanf("%s", &port->type);

}
void set_ports(struct port ports[])
{
    char change;
    system("cls");
    printf("====端口设置====\n");
    for (int i=0; i<5; i++) {
        printf("%d.PORT%d\n", i+1, i+1);
    }
    fflush(stdin);
    printf("请选择：");
    change = getchar();
    if (change >= '1' && change <= '5') {
        printf("change is %c \n", change);
        set_port(ports + change - '1');
    }
    system("pause");
}

// 端口管理
void port_admin(struct port ports[])
{
    char c;
    while (1) {
        system("cls");
        printf("----端口管理----\n");
        printf("1、查看端口\n");
        printf("2、设置端口\n");
        printf("3、返回\n");
        printf("请选择：");
        fflush(stdin);
        c = getchar();
        switch (c) {
        case '1':
            show_ports(ports);
            break;
        case '2':
            set_ports(ports);
            break;
        case '3':
            return;
        default:
            input_error();
            break;
        }
    }
}

void main_project()
{
    int menuChange = 0; //菜单选择
    struct port ports[5];
    for (int i=0; i<5; i++) {
        init_port(&ports[i]);
    }
    init();
    login();

    // 账号密码正确，输出主菜单
    while (1) {
        show_menu();
        scanf("%d", &menuChange);
        fflush(stdin);
        // 子功能
        switch (menuChange) {
        case 1:
            create_user();
            break;
        case 2:
            ip_manager();
            break;
        case 3:
            port_admin(ports);
            break;
        case 4:
            logout();
            break;
        default:
            input_error();
            break;
        }

    }
}


int main()
{
    main_project();
    //studyTest1();
    //mainStudyFunction();
    return 0;
}
