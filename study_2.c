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
static list_node_pt list_init(void)
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
static int list_insert_last(list_node_pt p_head, int data)
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
static void list_traverse(list_node_pt p_head)
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
static int list_delete_last(list_node_t *p_head, int *data)
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
static int list_delete_first(list_node_t *p_head, int *data)
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
static int list_clear(list_node_t *p_head)
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

static void  list_deinit(list_node_t **p_head)
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

/*
 * 17.11 链表的基本操作--删除指定位置节点
 */
/**
 * @brief list_delete_pos
 * @param p_head 头节点
 * @param pos   指定节点
 * @param data  此节点保存的值
 * @return  0表示失败，1表示成功
 */
static int list_delete_pos(list_node_t *p_head, unsigned int pos, int *data)
{
    if (NULL == p_head) {
        printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
        return 0;
    }
    if (NULL == p_head->next) {
        printf("%s[%d] : 链表为空\n", __FUNCTION__, __LINE__);
        return 0;
    }
    // 不管你要删除那个节点，一定要找到他的前驱节点,也就是找到要删除节点的本身
    // 目前有两种情况 pos大于你节点的个数，pos小于你节点的个数
    list_node_t *p_cur = p_head;
    list_node_pt p_del = p_head->next;
    unsigned int i = 0;
    while (p_del != NULL) {
        i++;
        // 当要删除的节点下标存在时，就退出循环，获取当前要删除的节点，如果不存在，继续遍历
        if (i == pos) {
            break;
        }
        p_cur = p_cur->next;
        p_del = p_del->next;
    }
    // 当遍历结束时，此时i 和pos不相等，证明要删除的这个节点不存在。此时就不能删除，返回0
    if (i != pos) {
        printf("%s[%d] : 此节点不存在，无法删除\n", __FUNCTION__, __LINE__, *data);
        return 0;
    }
    // 反之，如果相等的话，证明已找到此节点，我们只需要删除此节点，释放内存就行
    // 将前驱节点和后一个节点连接起来
    p_cur->next = p_del->next;
    *data = p_del->data;
    free(p_del);
    printf("%s[%d] : data = %d\n", __FUNCTION__, __LINE__, *data);
    return 1;
}

/*
 * 17.12 链表的基本操作--在指定的位置插入节点
 */
static int list_insert_pos(list_node_t *p_head, int pos, int data)
{
    if (NULL == p_head) {
        printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
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
        printf("%s[%d] : 插入失败， 最大能插入的为 %d \n", __FUNCTION__, __LINE__, i);
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

/*
 * 17.13 链表的基本操作--链表逆转
 */
int list_reverse(list_node_t *p_head)
{
    if (NULL == p_head) {
        printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
        return 0;
    }
    // 这个操作主要是一个一个遍历.假设有三个节点，p1,p2,p3，头节点p
    // (1)首先    p.next = NULL;
    // (2)第1步   p1.next = p.next, p.next = p1
    // (3)第2步   p2.next = p1,     p.next = p2
    // (4)第3步   p3.next = p2,     p.next = p3
    // p->p3->p2->p1->null;
    // 经过以上步骤，就将链表逆转了
    list_node_t *p_cur = NULL;  // 指向首节点
    list_node_t *p_new = NULL;  // 指向首节点的下一个节点，遍历的新节点
    // 首先对首节点和头节点的next进行赋值
    p_new = p_head->next;
    p_head->next = p_cur;
    while (p_new != NULL) {
        // 更新当前节点
        p_cur = p_new;
        // 更新下一个新节点
        p_new = p_new->next;
        // 当前节点指向旧的节点
        p_cur->next = p_head->next;
        // 头节点每次都指向新的节点。（作为首节点）
        p_head->next = p_cur;
    }
    return 1;
}

void test_17_11()
{

    list_node_pt head_list = NULL; // 定义一个头节点指针
    head_list = list_init();
    if (NULL == head_list) {
        printf("list_init fail !\n");
        exit(1);
    }

    // 增加节点
    for (int i=1; i<4; i++) {
        list_insert_last(head_list, i);
    }

    // 遍历节点
    list_traverse(head_list);

    /*int data;
    list_delete_pos(head_list, 7, &data);
    list_delete_pos(head_list, 4, &data);
    list_delete_pos(head_list, 2, &data);
    */

    /*list_insert_pos(head_list, 4, 11);
    list_insert_pos(head_list, 1, 22);
    list_insert_pos(head_list, 1, 33);

    list_traverse(head_list);*/

    list_reverse(head_list);

    list_traverse(head_list);

    // 销毁链表
    list_deinit(&head_list);

}

/*
 * 17.14 链表的基本操作--向升序链表插入节点
 */
int list_insert_order(list_node_t *p_head, int data)
{
    if (NULL == p_head) {
        printf("%s[%d] : p_head is null\n", __FUNCTION__, __LINE__);
        return 0;
    }

    list_node_t *p_pre = (list_node_t *)malloc(sizeof (list_node_t));
    list_node_t *p_pos = (list_node_t *)malloc(sizeof (list_node_t));

    p_pre = p_head;
    p_pos = p_head->next;

    while (p_pos != NULL) {
        if (data <= p_pos->data) {
            break;
        }
        p_pre = p_pre->next;
        p_pos = p_pos->next;
    }

    list_node_t *p_insert = (list_node_t *)malloc(sizeof (list_node_t));
    p_insert->data = data;

    p_pre->next = p_insert;
    p_insert->next = p_pos;
    return 1;
}

void test_17_14()
{
    list_node_pt head_list = NULL; // 定义一个头节点指针
    head_list = list_init();
    if (NULL == head_list) {
        printf("list_init fail !\n");
        exit(1);
    }

    list_insert_order(head_list, 2);
    list_insert_order(head_list, 5);
    list_insert_order(head_list, 3);
    list_insert_order(head_list, 6);
    list_insert_order(head_list, 0);
    list_insert_order(head_list, 3);
    list_insert_order(head_list, 4);

    list_traverse(head_list);

    // 销毁链表
    list_deinit(&head_list);
}

// 项目18， 优化ip地址存储空间

// 18.1 数据类型，占用字节
static void test_18_1()
{
    // char -128 ~ 127， unsigned char 0 ~ 255;
    printf("字符型 sizeof(char)                    = %d\n", (int)sizeof (char));
    printf("字符型 sizeof(unsigned char)           = %d\n", (int)sizeof (unsigned char));
    // short -32768~32767, unsigned short 0~65535;
    printf("短整形 sizeof(short)                   = %d\n", (int)sizeof (short));
    printf("短整形 sizeof(unsigned short)          = %d\n", (int)sizeof(unsigned short));
    // int
    printf("整形 sizeof(int)                       = %d\n", (int)sizeof (int));
    printf("整形 sizeof(unsigned int)              = %d\n", (int)sizeof (unsigned int));
    printf("长整形 sizeof(long)                    = %d\n", (int)sizeof (long));
    printf("长整形 sizeof(unsigned long)           = %d\n", (int)sizeof (unsigned long));
    printf("长长整形 sizeof(long long)             = %d\n", (int)sizeof (long long));
    printf("长长整形 sizeof(unsigned long long)    = %d\n", (int)sizeof (unsigned long long));
    printf("单精度 sizeof(float)                   = %d\n", (int)sizeof (float));
    printf("双精度 sizeof(double)                  = %d\n", (int)sizeof (double));

    // 单精度和双精度的区别
    // 单精度保存小数点后6位有效小数，双精度保存小数点后14位有效小数
    float ffloat = 1.1234567891234567;
    double ddouble = 1.1234567891234567;
    printf("ffloat  = %.20f\n", ffloat);
    printf("ddouble = %.20f\n", ddouble);
}

// 18.2 printf格式化输出
/*
 * %c   字符型 [singed] char和unsigned char
 * %d   有符号类型   [signed]int 以及[signed]int以下类型，如果无符号类型表示的范围没有超出int的整数范围，也可以用%d打印
 * %u   无符号类型   unsigned int 以及unsigned int以下类型，如果有符号类型不是负数，也可以打印
 * %ld  有符号长整形 [signed] long类型
 * %lu  无符号长整形 unsigned long类型
 * %lld 有符号长长整形 [signed] long long类型
 * %llu 无符号长长整形 unsigned long long类型
 * %f   单精度浮点类型 float类型
 * %lf  双精度浮点类型 double类型
 * %x   无符号整形（如果有符号是正数也可以，但不能打印负数），以16进制方式显示
 * %lx  无符号长整形（如果有符号是正数也可以，但不能打印负数），以16进制方式显示
 * %llx 无符号长长整形（如果有符号是正数也可以，但不能打印负数），以16进制方式显示
 */
static void test_18_2()
{
    // 测试
    int test_int = 1;
    unsigned int test_uint = 2;
    printf("test_int = %d, test_uint = %u\n", test_int, test_uint);

    long test_long = 3;
    unsigned long test_ulong = 4;
    printf("test_long = %ld, test_ulong = %lu\n", test_long, test_ulong);

    long long test_llong = 5;
    unsigned long long test_ullong = 6;
    printf("test_llong = %lld, test_ullong = %llu\n", test_llong, test_ullong);

    float test_float = 1.123456789;
    double test_double = 1.123456789123456789;
    printf("test_float = %0.7f, test_double = %0.15lf\n", test_float, test_double);

    // %x, %lx, %llx, %u, %lu, %llu 这些都不能打印负数
    // 带x的使用16进制打印出来，而且只能打印正数(unsinged)(short, int, long, long long)
    printf("test_uint   = 0X%x\n", test_uint);
    printf("test_ulong  = 0X%lx\n", test_ulong);
    printf("test_ullong = 0X%llx\n", test_ullong);
}

// 18.3 数据类型转换
/*
 * 1、正数常量类型
 * （1）默认为int类型
 * （2）超过int表示范围时默认为long long类型
 * （3）可以使用后缀强制转换为某种类型
 *  U unsigned int
 *  L long 类型
 *  UL unsigned long类型
 *  LL long long 类型
 *  ULL unsigned long long类型
 *
 * 2、小数常量类型
 * （1）默认为double
 * （2）可以使用后缀强制转换为float类型
 *  F float类型
 *
 * 3、数据溢出：选择合适的数据类型，避免数据溢出
 * （1）整数溢出
 * （2）小数精度溢出
 *
 * 4、注意
 * 平常使用不需要关注后缀，设置位操作的时候需要注意以下
 */
static void test_18_3()
{
    // 主要是了解一下有这回事就行
    // 整数常量类型
    printf("sizeif(1) = %d\n", sizeof (1));
    printf("sizeif(1) = %d\n", sizeof (1U));
    printf("sizeif(1) = %d\n", sizeof (1L));
    printf("sizeif(1) = %d\n", sizeof (1UL));
    printf("sizeif(1) = %d\n", sizeof (1LL));
    printf("sizeif(1) = %d\n", sizeof (1ULL));

    // 小数常量类型
    printf("sizeif(1) = %d\n", sizeof (1.11F));
    printf("sizeif(1) = %d\n", sizeof (1.11));

    // 以下操作举例说明不同后缀
    printf("~1 = %x\n", ~1);
    printf("~1U = %x\n", ~1U);
    printf("~1U = %llx\n", ~1U);        // 对4个字节取反
    printf("~1ULL = %llx\n", ~1ULL);    // 对8个字节取反
}

// 18.4 数据类型转换2-自动转换
/*
 * 转换原则：低字节向高字节转换，极限范围小的想极限范围大的转换
 * 强制转换：当你对于类型不确定时，请自己手动进行强制转换
 */
static void test_18_4()
{
    char        test_char = 1;
    short       test_short = 2;
    int         test_int = 3;
    long        test_long = 4;
    long long   test_llong = 5;
    float       test_float = 6.66666666;
    double      test_double = 7.77777777777;

    printf("sizeof(char + short)    = %d\n", sizeof (test_char + test_short));
    printf("sizeof(char + int)      = %d\n", sizeof (test_char + test_int));
    printf("sizeof(short + int)     = %d\n", sizeof (test_short + test_int));

    printf("sizeof(char + long long)    = %d\n", sizeof (test_char + test_llong));
    printf("sizeof(short + long long)   = %d\n", sizeof (test_short + test_llong));
    printf("sizeof(int + long long)     = %d\n", sizeof (test_int + test_llong));

    printf("\nfloat test\n");
    printf("sizeof(char + float)        = %d\n", sizeof (test_char + test_float));
    printf("sizeof(short + float)       = %d\n", sizeof (test_short + test_float));
    printf("sizeof(int + float)         = %d\n", sizeof (test_int + test_float));
    printf("sizeof(float + long long)   = %d\n", sizeof (test_float + test_llong));
    printf("sizeof(float + double)      = %d\n", sizeof (test_float + test_double));

    int a = -10;
    unsigned b = 5;
    if (a + b > 0) {
        printf("这是真的吗? a + b = %u\n", a + b);
    } else {
        printf("这是假的\n");
    }
    if ((int)(a + b) > 0) {
        printf("这是真的吗? a + b = %d\n", (int)(a + b));
    } else {
        printf("这是假的\n");
    }

    // 由高往低赋值时要注意
    unsigned int c = 0x123456;
    unsigned char d = c;
    unsigned short e = c;
    printf("c = 0x%x, d = 0x%x, e = 0x%x\n", c, d, e);
    // 打印结果为：c = 0x123456, d = 0x56, e = 0x3456
    // 所以我们赋值的时候要注意

    double f = 1.123456789;
    float g = f;
    printf("f = %0.10lf, g = %0.10f\n", f, g);
}

// 18.5 原码/反码/补码
/*
 * 1、具体规则请参考res下面的18_5.png图片示例
 * 2、计算机中以补码的方式存储数据
 *      我们只需要注意负数的补码
 *      因为正数以及无符号类型数值原码/反码/补码都是一样的
 * 3、假如是char类型，则-0实际上是用来表示-128
 *    假如是short类型，则-0实际上是用来表示-32768
 *    这是计算机的一种规定，如果不去写汇编代码我们可以不去了解-0为什么标书有符号的最小值
 */
static void test_18_5()
{
    char a0 = 85;
    char a1 = -85;
    char b0 = 9;
    char b1 = -9;
    char c0 = 127;
    char c1 = -127;

    printf("a0 = 0x%x, a1 = 0x%x\n", a0, (unsigned char)a1);
    // a0 = 0x55, a1 = 0xab
    // 0xab为补码， ab -> 1010 1011(补码） -> 1010 1010(反码) ->1101 0101(原码) = -85
    char d0 = 200;
    printf("d0 = %d, d0 = 0x%x\n", d0, (unsigned char)d0);

    // 超过取值范围都会以补码形式
    char d1 = -200;
    printf("d1 = %d, d1 = 0x%x\n", d1, (unsigned char)d1);
}

// 18.6 什么是进制
/*
 * 进制是一种计数机制，对于任何一种进制，就表示某一位置上的数运算时縫x进一位
 */

// 18.7 x进制转为10进制
/*
 * 位值计数法：一种利用位值制计数的方法，位值制即每个数码所表示的数值，不仅取决于这个数码本身，
 *      而且取决于他在计数中所处的位置；
 * 例子：10进制
 * 12345 = 5*10^0 + 4*10^1 + 3*10^2 + 2*10^3 + 1*10^4
 * 例子：2进制
 * 10101  = 1*2^0 + 0*2^1 + 1*2^2 + 0*2^3 + 1*2^4 = 21
 * 例子：8进制
 * 7014 = 4*8^0 + 1*8^1 + 0*8^2 + 7*8^3 = 3596
 */

// 18.8 10进制转为x进制
/*
 * 比如10进制value转为x进制，
 * 第一位：a0 = value%x; value = int(value/x)
 * 第二位：a1 = value%x; value = int(value/x)
 * 第三位：a3 = value%x; value = int(value/x)
 * 第四位：a4 = value%x; value = int(value/x)
 * ........
 */

static void test_18_8()
{
    int value = 1234;
    int x = 16;
    int a0 ;
    for (int i=0; i<4; i++) {
        a0 = value % x;
        value = (int)(value/x);
        printf("a = %d\n", a0);
    }
    //a = 2 , a = 13, a = 4 , a = 0    -> 4D2 = 1234
}

// 18.9 二进制转为10进制
static int fun_2_to_10(char *str)
{
    int num = 0;
    while(*str != '\0') {
        int i = *str - '0';
        if (i>=0 && i<=1) {
            // 这个如果看不懂就先用用10进制的想一下
            // 要是在想不明白就从c入门到放弃吧
            num = num *2 + i;
        }
        str++;
    }
    printf("num  = %d\n", num);
    return num;
}

// 18.10 十进制转为二进制
static void fun_10_to_2(unsigned int num)
{
    if (num/2 != 0) {
        fun_10_to_2(num/2);
    }
    putchar('0' + num%2);
}

// 18.11 八进制转和十进制之间转化
static int fun_8_to_10(char *str)
{
    int num = 0;
    while(*str != '\0') {
        int i = *str - '0';
        if (i>=0 && i<=7) {
            // 这个如果看不懂就先用用10进制的想一下
            // 要是在想不明白就从c入门到放弃吧
            num = num *8 + i;
        }
        str++;
    }
    printf("num  = %d\n", num);
    return num;
}
static void fun_10_to_8(int num)
{
    if (num/8 != 0) {
        fun_10_to_8(num/8);
    }
    putchar('0' + num%8);
}

// 18.12 十进制转和十六进制之间转化
static int fun_16_to_10(char *str)
{
    int num = 0;
    while(*str != '\0') {
        char ch = *str;
        if (ch >= '0' && ch <= '9') {
            num = num *16 + (ch - '0');
        }
        if (ch >= 'A' && ch <= 'F') {
            num = num *16 + 10 + (ch - 'A');
        }
        if (ch >= 'a' && ch <= 'f') {
            num = num *16 + 10 + (ch - 'a');
        }
        str++;
    }
    printf("num  = %d\n", num);
    return num;
}

static void fun_10_to_16(int num)
{
    if (num/16 != 0) {
        fun_10_to_16(num/16);
    }
    int i = num%16;
    if (i < 10) {
        putchar('0' + i);
    } else {
        putchar('a' + i - 10);
    }
}

// 18.13 位运算-与或反
/*
 * 位（bit）
 *    来自英文bit，音译位“比特”， 表示二进制位。
 *    位是计算机内部数据存储的最小单元，例如11010100是一个8位二进制数
 * 计算机中的cpu位置真的是cpu一次性冷处理的最大位数。例如32位计算机的cpu一个机器周期内可以处理
 * 32位二进制数据的计算机
 *
 * 位运算符和位运算
 *      &   按位与
 *      |   按位或
 *      ~   取反
 *      ^   按位异或
 *      <<  左移
 *      >>  右移
 *
 * 按位与 运算符（&）
 *  操作： 1 & 1 = 1; 1 & 0 = 0; 0 & 0 = 0；
 *  特点：只有全是1的时候才是1，其他情况都是0；
 *  总结：任何数和0位与就是0，和1位与没有变化，所以位与常用在清零上（清零用为与）
 *  应用举例：
 *
 * 按位或 运算符（|）
 *  操作： 1 & 1 = 1; 1 & 0 = 1; 0 & 0 = 0；
 *  特点：只有全是0的时候才是0，其他情况都是1；
 *  总结：任何数和1位与就是1，和0位与没有变化，所以位与常用在置1上（置1用为或）
 *  应用举例：
 *
 * 取反 运算符（~）
 *  操作：~1 = 0； ~0 = 1;
 *  结果：1取反为0；0取反为1；
 */
static void test_18_13()
{
    unsigned char c = 0;
    printf("测试按位与\n");
    c = 0x45;
    //c = c & 0xBF;
    c &= 0xBF;  // 简写
    printf("0x45 & 0xBF = 0x%x\n", c);  // 0100 0101  = 0x45
                                        // 1011 1111  = 0xBF
                                        // 0000 0101  = 0x05

    c = 69;
    //c = c & 191;
    c &= 191;
    printf("69 & 191 = 0x%x\n", c);     // 0100 0101  = 69
                                        // 1011 1111  = 0xBF
                                        // 0000 0101  = 0x05

    c = 0x75;
    //c = c & 0xBF;
    c &= 0xBF;
    printf("0x75 & 0xBF = 0x%x\n", c);  // 0111 0101  = 0x75
                                        // 1011 1111  = 0xBF
                                        // 0011 0101  = 0x35

    printf("\n测试按或\n");
    c = 0x15;
    //c = c | 0x40;
    c |= 0x40;
    printf("0x15 | 0x40 = 0x%x\n", c);  // 0001 0101  = 0x15
                                        // 0100 0000  = 0x40
                                        // 0101 0101  = 0x55
    c = 0x45;
    //c = c | 0x40;
    c |= 0x40;
    printf("0x45 | 0x40 = 0x%x\n", c);  // 0100 0101  = 0x45
                                        // 0100 0000  = 0x40
                                        // 0100 0101  = 0x45


    printf("\n测试按取反\n");
    c = 0x0F;
    c = ~c;
    printf("~ 0x0F = 0x%x\n", c);       // 0000 1111 = 0x0F
                                        // 1111 0000 = 0xF0

    c = 0xA5;
    c = ~c;
    printf("~ 0xA5 = 0x%x\n", c);       // 1010 0101 = 0xA5
                                        // 0101 1010 = 0x5A
}

// 18.14 左移操作
// 18.15 右移操作
/*
 * 左移(<<) 就是把一个数的所有位数都向左移动若干位
 * 右移(>>) 的概念和左移相反，就是王右边挪动若干位，右移对符号位的处理和左移不同，
 *    对于有符号整数来说，比如int类型，右移会保持符号位不变
 * 对于有符号数：
 *      左移的时候右侧补0；
 *      右移的时候左侧补符号位(整数符号位为0，则补0。负数符号位为1，则补1)
 * 对于无符号数：
 *      左移的时候右侧补0；
 *      右移的时候左侧也是补0；
 *
 * 操作的时候要考虑有符号数和无符号数
 */
static void test_18_14()
{
    int s_int = 1;      // 本来是32bit，目前数值小数，姑且只算8位
    s_int = s_int << 2; // 0000 0001
                        // 0000 0100
    printf("s_int << 2 = %d,\t 0x%x\n", s_int, s_int);

    s_int = 1;
    s_int = s_int << 1;
    printf("s_int << 1 = %d,\t 0x%x\n", s_int, s_int);

    s_int = 100;
    s_int = s_int << 4;  // = 100 * 2 * 2 * 2 * 2 = 1600
    printf("s_int << 4 = %d, 0x%x\n", s_int, s_int);

    s_int = 1073741823; // 2147483647 / 2
    // 00111111111111111111111111111111
    s_int = s_int << 2; // s_int = s_int * 2 * 2 = 4294967292
    // 如果使用左移n位的方式计算某个数*2的n次方，要考虑溢出问题
    printf("1073741823 << 2 = %d, 0x%x\n", s_int, s_int);// 结果不是我们想要的，溢出，左移的时候符号位被改变
    // 11111111111111111111111111111100 -> 第一位为1，则为负数

    // 测试左移位数超过数据类型最大位数，比如int是32位， n = n % 32;
    printf("\n测试左移位数超过数据类型最大位数\n");
    s_int = 0x12345678;
    s_int = s_int << (32+4);        // (32 + 4) % 32 = 4;
    printf("0x12345678 << 4 = 0x%x\n", s_int);   //00010010001101000101011001111000
                                                 //00100011010001010110011110000000 = 0x23456780
    s_int = 0x12345678;
    s_int = s_int << (32+1);
    printf("0x12345678 << 1 = 0x%x\n", s_int);   //00010010001101000101011001111000
                                                 //00100100011010001010110011110000 = 0x2468acf0
    printf("\n测试右移\n");
    s_int = 0x80000000;
    //对于有符号数：右移的时候左侧补符号位(整数符号位为0，则补0。负数符号位为1，则补1)
    s_int = s_int >> 1;     // 1000 0000 0000 0000 0000 0000 0000 0000
                            // 1100 0000 0000 0000 0000 0000 0000 0000 = 0xc0000000
    printf("有符号数右移1位 s_int >> 1 = 0x%x\n", s_int);

    unsigned int u_int = 0x80000000;
    //对于无符号数：补0
    u_int = u_int >> 1;     // 1000 0000 0000 0000 0000 0000 0000 0000
                            // 0100 0000 0000 0000 0000 0000 0000 0000 = 0x40000000
    printf("无符号数右移1位 s_int >> 1 = 0x%x\n", u_int);

    s_int = 0x80000000;
    s_int = s_int >> 4;     // 1000 0000 0000 0000 0000 0000 0000 0000
                            // 1111 1000 0000 0000 0000 0000 0000 0000 = 0xf8000000
    printf("有符号数右移4位 s_int >> 4 = 0x%x,  %d\n", s_int, s_int);

    u_int = 0x80000000;
    u_int = u_int >> 4;     // 1000 0000 0000 0000 0000 0000 0000 0000
                            // 0000 1000 0000 0000 0000 0000 0000 0000 = 0x08000000
    printf("无符号数右移4位 s_int >> 4 = 0x%x\n", u_int);
}


// 18.16 位操作实战1-2
// 18.17 位操作实战3-4
// 18.18 位操作实战3-5
// 18.19 位操作实战6
// 默认规则：设置bit，默认将bit设置为1，清除bit，将bit设置为0；
// bit0 -- bit31(bit0为右边第一位）
static void test_18_16()
{
    unsigned int a = 0xc3057ad3;
    // 1、给定一个整形数a,设置a的bit3，保证其他位不变 // 1000 = 8
    a = 0xc3057ad3;
    a |= 0x8;
    printf("题目1 a = 0x%x\n", a);

    a = 0xc3057ad3;
    a |= (1<<3);    // 1<<3 = 1000 = 8
    printf("题目1 a = 0x%x\n", a);

    // 2、给定一个整形数a,设置a的bit3~bit7，保证其他位不变1111 1000
    a = 0xc3057ad3;                     // 1100 0011 0000 0101 0111 1010 1101 0011
    a |= 0xF8;                          //                               1111 1000 = 0xF8
    printf("题目2 a = 0x%x\n", a);

    a = 0xc3057ad3;
    // 1111 1000 = (1 1111) << 3
    a |= (0x1F<<3);
    printf("题目2 a = 0x%x\n", a);

    // 假如你要设置bit4~bit7,
    a = 0xc3057ad3;
    // 1111 0000 = (1111) << 4
    a |= (0xf<<4);
    printf("题目2 a = 0x%x\n", a);

    // 3、给定一个整型数a，清除a的bit14，保证其他位不变
    // 1111 1111 1111 1111 0111 1111 1111 1111  ~(1<<15)
    // 0000 0000 0000 0000 1000 0000 0000 0000  取反的操作 (1<<15)
    a = 0xc3057ad3;
    fun_10_to_2(a);
    printf("\n");
    a &= ~(1 << 14);
    fun_10_to_2(a);
    printf("\n题目3 a = 0x%x\n\n", a);

    // 4、给定一个整型数a，清除a的bit15~bit23，保证其他位不变
    // 15-23 = 1 1111 1111 = 0x1ff
    a = 0xc3057ad3;
    fun_10_to_2(a);
    printf("\n");
    a &= ~(0x1ff << 15);
    fun_10_to_2(a);
    printf("\n题目4 a = 0x%x\n\n", a);

    // 5、给定一个整型数a，取出a的bit3~bit8
    // 0011 1111 = 0x3F
    // 注意：要取出这个数，首先要把其他位清0；之后又一就可以得出那个数了
    a = 0xc3057ad3;
    a &= (0x3f << 3);
    fun_10_to_2(a);
    printf("\n");
    a = a >> 3;
    fun_10_to_2(a);
    printf("\n题目5 a = 0x%x\n\n", a);

    // 6、给定一个整型数a，a的bit7~bit17 赋值937， 其余位不受影响
    // 注意：要赋值就需要把赋值的那几个bit位清零，然后把需要赋值的数左移到那几位就可以了
    a = 0xc3057ad3;
    fun_10_to_2(a);
    printf("\n");
    a &= ~(0x7ff << 7);
    fun_10_to_2(a);
    printf("\n");
    a |= (937 << 7);
    fun_10_to_2(a);
    printf("\n题目6 a = 0x%x\n\n", a);

    //

}

// 19.1 结构体膨胀
// 19.2 内存对齐1
// 19.3 内存对齐2
/*
 * 内存对齐原因
 *      在用sizeof运算符求算某结构体所占空间时，并不是简单的将结构体中所有元素各自占
 *   的空间相加，这里涉及到内存字节对齐的问题。
 *      从理论上讲，对任何变量的访问都可以从任何地址开始访问。但是事实上不是如此，实际上
 *    访问特定类型的变量只能在特定的地址访问，这就需要各个变量在空间上按一定的规则排列，
 *    而不是简单的顺序排列，这就是内存对齐。
 *
 * 结构体对齐规则
 *  （0）变量起始地址是自身字节数的整数倍
 *  （1）结构体成员在内存中顺序存放，所占内存地址一次增高，第一个成员处在最低某处，最后一个
 *   成员处在高地址处，但结构体成员之间的内存分配不一定是连续的。
 *  （2）对于n个字节的元素，他的首地址要能被n整除
 *  （3）对待每个成员，类似于对待单个n字节元素一样，依次为每个元素找一个合适的首地址，使其能
 *   符合第2条对齐原则。
 *  （4）整个结构体的长度必须是各成员所使用的对齐参数N中最大的那个值得整数倍
 *
 * 主要是2和4
 */

struct data1{
    char a;
};
struct data2{
    char a;
    int b;
};

struct data3{
    char a;
    char b;
    int c;
};
struct data3_1{
    char a;
    int c;
    char b;
};

struct data4{
    char a;
    char b;
    int c;
};

struct data5{
    char a;
    char b;
    char c;
    char d;
    int e;
};

struct data6{
    char a;
    char b;
    char c;
    char d;
    char e;
    int f;
};

struct data7{
    char a;
    int b;
    char c;
    double d;       // max  N = 8;
};

void test_19_1()
{
    printf("data1   sizeof = %d\n", (unsigned int)sizeof (struct data1));
    printf("data2   sizeof = %d\n", (unsigned int)sizeof (struct data2));
    printf("data3   sizeof = %d\n", (unsigned int)sizeof (struct data3));
    printf("data3_1 sizeof = %d\n", (unsigned int)sizeof (struct data3_1));
    printf("data4   sizeof = %d\n", (unsigned int)sizeof (struct data4));
    printf("data5   sizeof = %d\n", (unsigned int)sizeof (struct data5));
    printf("data6   sizeof = %d\n", (unsigned int)sizeof (struct data6));

    struct data7 t7;
    printf("sizeof      = %d\n", sizeof (t7));
    printf("t7          = 0x%p\n", &t7);
    printf("char a      = 0x%p\n", &t7.a);
    printf("int b       = 0x%p\n", &t7.b);
    printf("char c      = 0x%p\n", &t7.c);
    printf("double d    = 0x%p\n", &t7.d);

    /*
     * 好好体会data3和data3_1字节数的区别，为什么排列不一样会导致sizeof不一样
     */
}

void test_study_2(void) {
    printf("\n########       程序开始        #########\n");
    //test_17_14();
    //test_18_8();
    //fun_2_to_10("1010 1011");// 171
    //fun_10_to_2(171);
    //fun_8_to_10("4567");    // 2423
    //fun_10_to_8(2423);

    /*fun_16_to_10("ABCDEF");     // 11259375
    fun_16_to_10("abcdef");
    fun_10_to_16(11259375);
    */
    //test_18_16();
    test_19_1();
    printf("\n########       程序结束        #########\n");

}
