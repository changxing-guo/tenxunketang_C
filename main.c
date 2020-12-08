#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef STUDY_1_H
#include "study_1.h"
#endif
#ifndef STUDY_FUNCTION_H
#include "study_function.h"
#endif

#define CLEAR_SCREEN() system("cls")    // 宏定义的方式
#define PAUSE_SCREEN() system("pause");
static int debug = 1;
static FILE *userNamePasswdFile;       //保存用户账号密码的文件
static unsigned int port_num = 0;

// 使用“结构”来定义“端口类型”
typedef struct port {
    char name[16];
    int status; // 1 激活 0 禁止
    char ip[16];
    char type[4]; // wan , lan
}port_t;

typedef port_t *elem_t;     // 指向端口

typedef struct list_node {
    elem_t data;
    struct list_node *next; // 指向下一个节点
}list_node_t;

//
//初始化链表，即创建头节点
static list_node_t *list_init(void)
{
    list_node_t *head_node = (list_node_t *)malloc(sizeof (list_node_t));
    if (head_node) {
        head_node->next = NULL;
    } else {
        if (debug) printf("初始化链表失败\n");
    }
    return head_node;
}

// 遍历节点
static void list_traverse(list_node_t *p_head)
{
    if (NULL == p_head) {
        if (debug) printf("%s[%d] : p is null\n", __FUNCTION__, __LINE__);
    }
    list_node_t *list_node = p_head->next;
    while (list_node != NULL) {
        list_node = list_node->next;
    }
}

static int list_clear(list_node_t *p_head)
{
    if (NULL == p_head) {
        if (debug) printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
        return 0;
    }

    // 第一种方式
    list_node_t *del = p_head->next;
    while(del != NULL) {
        p_head->next = del->next;  // 将头节点的next指向删除节点的next；
        free(del);  // 释放节点占用的内存
        del = p_head->next;
    }
    return 1;
}

// 销毁链表
static void list_deinit(list_node_t **p_head)
{
    list_clear(*p_head);
    free(*p_head);
    *p_head = NULL;
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
            PAUSE_SCREEN();
            CLEAR_SCREEN();
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
void logout(list_node_t *p_head)
{
    fclose(userNamePasswdFile);
    list_deinit(&p_head);
    CLEAR_SCREEN();
    exit(0);
}

void input_error()
{
    CLEAR_SCREEN();
    printf("请输入有效的菜单选项\n");
    printf("按任意键返回主菜单\n");
    getchar();
}

// 查看端口
void show_port(struct port *port)
{
    printf("name:%-16s\t status:%s\t ip:%-16s\t type:%-4s \n",
           port->name,
           port->status ? "激活" : "禁止",
           port->ip,
           port->type);
}
void show_ports(list_node_t *p_head)
{
    CLEAR_SCREEN();
    if (port_num == 0) {
      printf("暂时没有端口，请设置\n");
    }
    for (int i=0; i<port_num; i++) {
        printf("PORT%d\t", i+1);
        //show_port(ports++);
    }
    PAUSE_SCREEN();
}

void add_ports(list_node_t *p_head)
{

}

void del_ports(list_node_t *p_head)
{

}

// 设置端口
void set_port(struct port *port)
{
    printf("请输入端口的名称：");
    scanf("%s", port->name);
    printf("请输入端口的状态[0:禁止, 1:激活]：");
    scanf("%d", &(port->status));
    printf("请输入端口的ip：");
    scanf("%s", port->ip);
    printf("请输入端口的类型[lan:wan]：");
    scanf("%s", &port->type);

}
void modify_port(list_node_t *p_head)
{

}

// 端口管理
void port_admin(list_node_t *p_head)
{
    char c;
    while (1) {
        system("cls");
        printf("----端口管理----\n");
        printf("1、查看端口\n");
        printf("2、增加端口\n");
        printf("3、删除端口\n");
        printf("4、修改端口\n");
        printf("q: 返回主菜单\n");
        printf("请选择：");

        fflush(stdin);
        c = (char)getchar();
        switch (c) {
        case '1':
            show_ports(p_head);
            break;
        case '2':
            add_ports(p_head);
            break;
        case '3':
            del_ports(p_head);
        case '4':
            modify_port(p_head);
        default:
            input_error();
            break;
        }
    }
    //return ports;
}

void main_project()
{
    init();     // 初始化
    login();    // 登陆
    list_node_t *router_head = list_init(); // 初始化链表
    if (NULL == router_head) {
        printf("链表初始化失败!\n");
        exit(1);
    }

    int menuChange = 0; //菜单选择
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
            port_admin(router_head);
            break;
        case 4:
            logout(router_head);
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
