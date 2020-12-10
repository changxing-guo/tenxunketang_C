#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef STUDY_1_H
#include "study_1.h"
#endif
#ifndef STUDY_FUNCTION_H
#include "study_function.h"
#endif

#define CLEAR_SCREEN() system("cls")    // 宏定义的方式， 清除屏幕函数
#define PAUSE_SCREEN() system("pause"); // 暂停函数
static int debug = 1;                   // 打印开关
static FILE *userNamePasswdFile;        // 保存用户账号密码的文件
static int port_num = 0;                // 端口个数

// 使用“结构”来定义“端口类型”
typedef struct port {
    char name[16];
    int status;                         // 1 激活 0 禁止
    char ip[16];
    char type[4];                       // wan , lan
}port_t;

typedef port_t *elem_t;                 // 指向端口

// 链表结构
typedef struct list_node {
    elem_t data;
    struct list_node *next;             // 指向下一个节点
}list_node_t;

// 显示端口数据
static void show_port(port_t *port)
{
    printf("name:%-16s\t status:%s\t ip:%-16s\t type:%-4s \n",
           port->name,
           port->status ? "激活" : "禁止",
           port->ip,
           port->type);
}

// 设置端口数据
static void set_port(port_t *port)
{
    printf("请输入端口的名称：");
    scanf("%s", port->name);
    printf("请输入端口的状态[0:禁止, 1:激活]：");
    scanf("%d", &(port->status));
    printf("请输入端口的ip：");
    scanf("%s", port->ip);
    printf("请输入端口的类型[lan:wan]：");
    scanf("%s", port->type);
}

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

// 获取指定下标的端口指针
static elem_t list_find_pos(list_node_t *p_head, int index)
{
    if (NULL == p_head) {
        if (debug) printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
        return NULL;
    }

    list_node_t *list_cur = p_head->next;
    int i = 0;

    while(list_cur != NULL) {
        i++;
        if (i == index) {
            break;
        }
        list_cur = list_cur->next;
    }
    // 如果遍历完此时还不等于，证明没找到
    if (i != index) {
        if (debug) printf("%s[%d] : 未找到此节点 \n", __FUNCTION__, __LINE__);
        return NULL;
    }
    return list_cur->data;
}

// 指定位置插入节点
static int list_insert_pos(list_node_t *p_head, int pos, elem_t data)
{
    if (NULL == p_head) {
        if (debug) printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
        return 0;
    }

    // 首先分析一下，pos允许的值为链表节点的个数+1(list_size() + 1)
    list_node_t *list_pre = p_head;
    list_node_t *list_cur = p_head->next;
    int i = 1;
    // 简单分析下
    while(list_cur != NULL) {
        // 1，如果插入的pos <= list_size()  pos == i时，break,
        // 假设pos = 1，此时直接返回，我们就将头节点和新插入的节点连接起来
        // 假设pos > 1,此时我们进行遍历
        if (i == pos) {
            break;
        }
        // 遍历, 如果此时list_pre->next == NULL， 不会再进入此循环，但是我们还是能添加，所以i++
        // pos允许的值为链表节点的个数+1(list_size() + 1)
        i++;
        list_pre = list_pre->next;
        list_cur = list_cur->next;
    }
    // 如果不等于，证明 pos > list_size() + 1,
    // 假设 链表节点个数为3，pos = 5，此时就不能添加，所以直接return
    if (i != pos) {
        if (debug) printf("%s[%d] : 插入失败， 最大能插入的为 %d \n", __FUNCTION__, __LINE__, i);
        return 0;
    }
    // 遍历结束后，我们判断pos是否等于i,如果等于 说明 pos <= list_size() + 1,此时可以插入
    list_node_t *list_insert = (list_node_t *)malloc(sizeof (list_node_t));
    list_insert->data = data;
    // 前驱节点
    list_pre->next = list_insert;
    // 插入节点的next = 当前节点
    list_insert->next = list_cur;
    return 1;
}

// 指定位置删除节点
static int list_delete_pos(list_node_t *p_head, int index)
{

}

// 遍历节点
static void list_traverse(list_node_t *p_head)
{
    if (NULL == p_head) {
        if (debug) printf("%s[%d] : p is null\n", __FUNCTION__, __LINE__);
    }
    list_node_t *list_node = p_head->next;
    while (list_node != NULL) {
        show_port(list_node->data);
        list_node = list_node->next;
    }
}

// 清除节点
static int list_clear(list_node_t *p_head)
{
    if (NULL == p_head) {
        if (debug) printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
        return 0;
    }
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

// 输入错误
void input_error()
{
    CLEAR_SCREEN();
    printf("请输入有效的菜单选项\n");
    printf("按任意键返回主菜单\n");
    PAUSE_SCREEN();
}

/*  ------------------------------------------------------------------------------
 *  --------------------     以下为项目主体    -----------------------------
 *  ------------------------------------------------------------------------------
 */

// 初始化函数-打开保存的用户密码
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
    char name[32];                              //输入的用户名
    char passwd[32];                            //输入的密码
    char line[128];
    char nameCompare[32];                       //用于比较的用户名
    char passwdCompare[32];                     //用于比较的密码
    char *getsUsersTxtLineResult;               //users.txt文件fgets读取一行的返回值

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
        if (getsUsersTxtLineResult) {           //用户名密码匹配成功
            break;
        } else {                                //匹配失败
            printf("用户名或者密码错误\n");
            PAUSE_SCREEN();
            CLEAR_SCREEN();
            fseek(userNamePasswdFile, 0, SEEK_SET);     // 将文件内部的位置指针设置到文件头
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
// ------------------------    端口管理 ------------------------

// 显示端口
void show_ports(list_node_t *p_head)
{
    fflush(stdin);
    CLEAR_SCREEN();
    list_traverse(p_head);
    printf("按任意键返回主菜单\n");
    getchar();

}

// 添加端口
void add_ports(list_node_t *p_head)
{
    CLEAR_SCREEN();
    port_t *new_port = NULL;
    char n;
    while (1) {
        if (port_num > 0) {
            printf("----已添加的端口----\n");
            for (int i=0; i<port_num; i++) {
                show_port(list_find_pos(p_head, i+1));
            }
        } else {
            printf("----目前没有端口----\n");
        }
        printf("+. 增加端口\n");
        printf("q. 返回\n");
        printf("请选择： ");
        fflush(stdin);
        scanf("%c", &n);
        if ('+' == n) {
            new_port = (port_t *)malloc(sizeof (port_t));
            set_port(new_port);
            list_insert_pos(p_head, port_num + 1, new_port);
            port_num++;
        } else if ('q' == n) {
            return;
        } else {
            input_error();
        }
        CLEAR_SCREEN();
    }

}

void del_ports(list_node_t *p_head)
{

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
        case 'q':
            return;
        default:
            input_error();
            break;
        }
    }
}
// ------------------------    端口管理 结束 ------------------------

// 退出账号
void logout(list_node_t *p_head)
{
    fclose(userNamePasswdFile);
    list_deinit(&p_head);
    CLEAR_SCREEN();
}

// ------------------------    主函数入口  ------------------------
void main_project()
{
    //init();     // 初始化
    //login();    // 登陆
    list_node_t *router_head = list_init(); // 初始化链表
    if (NULL == router_head) {
        printf("链表初始化失败!\n");
        return;
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
/*  ------------------------------------------------------------------------------
 *  --------------------     项目主体结束    -----------------------------
 *  ------------------------------------------------------------------------------
 */

int main()
{
    main_project();
    //studyTest1();
    //mainStudyFunction();
    return 0;
}
