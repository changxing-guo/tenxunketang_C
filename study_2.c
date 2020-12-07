#include <stdio.h>
#include <stdlib.h>

static void printf_static()
{
    printf("printf_static is called\n");
}

void test_13()
{
    printf("this is study_2.c.test\n");
    printf_static();
}

//  项目17 链表

/*
 * 17.2 链表入门
 */

typedef struct list_node{
    int data;                   //数据域，存放数据
    struct list_node *next;     //指针域，指向下一个列表节点
}list_node_t, *list_node_pt;

void test_17_2()
{
    // 首先定义一个火车头
    list_node_pt n = (list_node_pt)malloc(sizeof (list_node_t));
    n->data = 0;
    printf("address is %p, data = %d\n", n, n->data);

    // 定义第一节车厢
    list_node_pt n1 = (list_node_pt)malloc(sizeof (list_node_t));
    n1->data = 1;
    printf("address is %p, data = %d\n", n1, n1->data);

    // 定义第二节车厢
    list_node_pt n2 = (list_node_pt)malloc(sizeof (list_node_t));
    n2->data = 2;
    printf("address is %p, data = %d\n", n2, n2->data);

    // 把车头，车厢连接起来
    n->next = n1;
    n1->next = n2;
    n2->next = NULL;

    printf("\n遍历车厢\n");
    list_node_pt list_node = n->next;
    while (list_node != NULL) {
        printf("address is %p, data = %d\n", list_node, list_node->data);
        list_node = list_node->next;
    }

    free(n);
    free(n1);
    free(n2);
    printf("\ngame is over\n");

}

/*
 * 17.3 链表的基本操作-插入
 *
 * （用火车头，车厢举例，实际c语言中没有这个说法）
 *  1）初始化节点
 *      创建头节点，就是创建一个火车头
 *  2）在尾部插入节点
 *  3）遍历节点
 *  4）删除尾部节点
 *  5）清除节点
 *      这个清除节点不包括头结点，即只是清除车厢
 *  6）销毁链表
 *      包括头结点，以及其他节点，即包括火车头，车厢
 */

//初始化链表，即创建头节点
list_node_pt list_init(void)
{
    list_node_pt head_node = (list_node_pt)malloc(sizeof (list_node_t));
    if (head_node) {
        head_node->next = NULL;
    } else {
        printf("初始化链表失败\n");
    }
    return head_node;
}

/* 在尾部插入节点。返回1表示成功，返回0表示插入失败
 *  a:先找到最后一个节点，
 *  b:最后一个节点通过next指针指向新插入的节点
 *  c:新插入的节点就就成了最后一个节点
 *  d:最后一个节点他的next一定是NULL
 */
int list_insert_last(list_node_pt p_head, int data)
{
    if (NULL == p_head) {
        printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
        return 0;
    }
    list_node_pt p_insert = (list_node_pt)malloc(sizeof (list_node_t));
    p_insert->next = NULL;
    p_insert->data = data;

    while (NULL != p_head->next) {
        p_head = p_head->next;
    }
    p_head->next = p_insert;
    return 1;
}

/*
 * 17.4 链表的基本操作--遍历
 */
// 遍历节点
void list_traverse(list_node_pt p_head)
{
    if (NULL == p_head) {
        printf("%s[%d] : p is null\n", __FUNCTION__, __LINE__);
    }
    printf("#############     遍历节点    ########\n");
    list_node_pt list_node = p_head->next;
    while (list_node != NULL) {
        printf("address is %p, data = %d\n", list_node, list_node->data);
        list_node = list_node->next;
    }
}

/*
 * 17.5 链表的基本操作--删除尾部节点
 */
/* 删除尾部节点
 *  a: 找到最后一个节点,获取此节点的值
 *  b: 找到最后节点的前一个节点,将next置为NULL（等价于最后一个节点的next）
 */
/**
 * @brief list_delete_last
 * @param p_head
 * @param data 将删除的节点的值返回到一个变量中
 * @return
 */
int list_delete_last(list_node_t *p_head, int *data)
{
    if (NULL == p_head) {
        printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
        return 0;
    }
    if (NULL == p_head->next) {
        printf("%s[%d] : p_frist is null\n", __FUNCTION__, __LINE__);
        return 0;
    }
    list_node_t *list_del = p_head->next;
    list_node_t *list_tmp = p_head;
    while (list_del->next != NULL) {
        list_del = list_del->next;
        list_tmp = list_tmp->next;  // 指向list_del的前一个节点
    }
    *data = list_del->data;
    // 指向最后一个节点的下一个节点（也是NULL），引申为假如后面还有节点，那就可以链接上（假如删除中间的节点）
    //list_tmp->next = NULL;
    // b: 找到最后节点的前一个节点,将next置为NULL（等价于最后一个节点的next）,这个是更为通用的方式
    list_tmp->next = list_del->next;
    free(list_del);
    return 1;
}

/*
 * 17.6 链表的基本操作--删除首节点
 */
int list_delete_first(list_node_t *p_head, int *data)
{
    if (NULL == p_head) {
        printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
        return 0;
    }
    // 判断首节点是否存在
    if (NULL == p_head->next) {
        printf("%s[%d] : p_frist is null\n", __FUNCTION__, __LINE__);
        return 0;
    }
    // 能跑到这里说明首节点是存在的
    list_node_t *node_first = p_head->next;
    if (data != NULL) {
        *data = node_first->data;   // 获取数目
    }
    p_head->next = node_first->next;    // 将首节点的下一个节点的值赋给头节点的next
    free(node_first);
    return 1;

}

/*
 * 17.7 链表的基本操作--清空链表节点
 */
int list_clear(list_node_t *p_head)
{
    if (NULL == p_head) {
        printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
        return 0;
    }

    // 第一种方式
    list_node_t *del = p_head->next;
    while(del != NULL) {
        p_head->next = del->next;  // 将头节点的next指向删除节点的next；
        printf("清空链表节点[%d]\n", del->data);
        free(del);  // 释放节点占用的内存
        del = p_head->next;
    }
    // 第二种方式
    /*
    int a;
    while (p_head->next != NULL) {
       list_delete_first(p_head, &a);
       printf("清空链表节点[%d]\n", a);
    }
    */

    return 1;
}

/*
 * 17.8 链表的基本操作--销毁链表
 */

/*
 * 在这儿为什么用二级指针，不太清楚，一级指针完全可以实现此功能，无非就是传入头节点的存储地址而已
 * 其实就是malloc是返回的指针，他里面存储的就是头节点的地址；
 * list_node_t *head_list = list_init();
 * 其实传入head_list就可以，
 */

void  list_deinit(list_node_t **p_head)
{
    // 1、清空清空链表节点
    list_clear(*p_head);
    // 2、清空首节点
    free(*p_head);
    *p_head = NULL;
    printf("\n销毁链表完成\n");
}

/*
 * 17.9 链表的基本操作--判断链表是否为空
 */
/**
 * @brief list_is_empty
 * @param p_head
 * @return  1 is null;
 */
int list_is_empty(list_node_t *p_head)
{
    if (NULL == p_head) {
        printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
        return 1;
    }
    if (NULL == p_head->next) {
        printf("%s[%d] : 链表为空\n", __FUNCTION__, __LINE__);
        return 1;
    }
    printf("%s[%d] : 链表不为空\n", __FUNCTION__, __LINE__);
    return 0;
}

/*
 * 17.10 链表的基本操作--链表节点个数
 */
int list_size(list_node_t *p_head)
{
    int node_size = 0;
    if (NULL == p_head) {
        printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
        return node_size;
    }
    while(p_head->next != NULL) {
        node_size+=1;
        p_head = p_head->next;
    }
    printf("%s[%d] : 链表节点的个数是 %d\n", __FUNCTION__, __LINE__, node_size);
    return node_size;
}

void test_17_3()
{
    list_node_pt head_list = NULL; // 定义一个头节点指针
    head_list = list_init();
    if (NULL == head_list) {
        printf("list_init fail !\n");
        exit(1);
    }

    // 增加节点
    for (int i=1; i<10; i++) {
        list_insert_last(head_list, i);
    }

    list_size(head_list);

    printf("未删除前遍历节点\n\n");
    list_traverse(head_list);


    printf("\n删除节点中。。。。\n");
    int a ;
    // 将节点4的值返回出来
    list_delete_last(head_list, &a);
    printf("删除的节点是 = %d\n", a);

    // 将节点3的值返回出来
    list_delete_last(head_list, &a);
    printf("删除的节点是 = %d\n", a);

    list_delete_first(head_list, &a);
    printf("删除的节点是 = %d\n", a);

    printf("删除节点完成。。。。\n\n");

    printf("删除后重新遍历节点\n");
    list_traverse(head_list);

    list_is_empty(head_list);

    // 17.7 链表的基本操作--清空链表节点
    list_clear(head_list);

    list_is_empty(head_list);

    list_size(head_list);

    // 销毁链表
    list_deinit(&head_list);
}


void test_study_2(void) {
    printf("\########       程序开始        #########\n");
    test_17_3();
    printf("\########       程序结束        #########\n");

}
