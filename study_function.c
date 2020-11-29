/* ########     function    ######## */

#include <stdio.h>
#include <study_function.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/*
 * 1、为什么要使用函数
 *  已经有main函数，为什么还要自定义函数
 *  1）“避免重复制造轮子”。提高开发效率
 *  2）便于维护
 */

/*
 * 2、函数的声明、定义和使用
 *  函数的设计功能
 *  1）先确定函数的功能
 *  2）确定函数的名称
 *      名称要顾名思义
 *  3）确定函数的参数
 *      是否需要参数，参数的个数，参数的类型
 *  4）确定函数的返回值
 *      是否需要返回值，返回值的类型,返回值只能有一个
 *  5）实现函数体
 */

/*
 * 函数的定义要放在前面，使用放在后面
 */

// gcc test.c -Wall 打印所有警告

// 求前n个正整数的和
int sum(int n)
{
    int sum = 0;;
    for (int i=1; i<n+1; i++) {
        sum += i;
    }
    return sum;
}

/*
 * 3、函数的值传递
 */
// 求两个数的和
int add(int a, int b)   // a = x, b = y, 值传递
{
    return a + b;
}

/*
 * 5、递归函数
 *  定义：在函数内部，直接或者间接的调用自己
 *  要点：在定义递归函数时，一定要确定一个结束条件
 *  使用场合：处理一些特别复杂的问题，难以直接解决
 *      1）迷宫问题
 *      2）
 * 递归函数的缺点，效率很低，能不用就不用，不必纠结
 *
 */
void recursive()
{
    printf("进入recursive函数\n");
    sleep(1);
    recursive();

    printf("退出recursive函数\n");
}

// 从盗梦空间到递归函数
int sum1(int n) {
    if (n == 1) {
        return 1;
    }
    return sum1(n-1) + n;
}

// 练习金字塔自定义类型
void show_pyramid(char c, int n)
{
    if (n < 1) {
        printf("金字塔的层数必须大于0\n");
        return;
    }
    if (c == ' ' || c == '\n' || c == '\t') {
        printf("非法的金字塔字符\n");
        return;
    }
    for(int i=1; i<n+1; i++) {
        for(int j=0; j<n-i; j++) {
            printf(" ");
        }
        for(int j=1; j<2*i; j++) {
            printf("%c", c);
        }
        printf("\n");
    }
}

// 用递归函数实现1+2+3+ .... + n;
int recursive_sum(int n) {
    if (n == 1) {
        return 1;
    }
    return sum(n-1) + n;
}

// 用递归函数实现汉姆塔
/*
 * A柱有n个盘子，移动到c柱
 *  如果 n>1 时
 *      1）把n-1个盘从A柱移动到B柱
 *      2）把n盘从A柱移动到c柱
 *      3）把 n-1个盘子从B柱移动到C柱
 *  如果n=1时，
 *      把盘子直接移动到C柱
 */
// 想不明白就就证明没这个天赋，洗洗睡吧
// c 从入门到放弃
int hannuota(int n, char name_A[], char name_B[], char name_C[])
{
    if (n == 1) {
        printf("11111   %s 移动到 %s \n", name_A, name_C);
        return 0;
    }
    // 从 A 移动 B, C是中转
    hannuota(n-1, name_A, name_C, name_B);
    printf("22222  %s 移动到 %s \n", name_A, name_C);
    hannuota(n-1, name_B, name_A, name_C);
}

// 1、为什么要使用结构体
/*
 * 表示一些赋值信息时，使用单纯的数据类型很不方便
 * 比如：学生信息（name, age, sex,tel,grade)
 */

// 2、什么是结构
/*
 * 程序员自定义的一种“数据类型”
 * 是使用多个基本数据类型、或者其他结构，组合而成的一种新的“数据类型”
 */

// 3、结构的定义
/*
 * struct 结构名 {
 *      成员类型 成员名；
 *      ...
 * }
 */

// 4、结构体的初始化
struct student {
    char name[16];
    int age;
};
void init_struct()
{
    // 一般就这两种初始化方式
    // 成员比较少的时候可以这样，但是不建议
    struct student s1 = {
        "gcx", 22
    };
    // 这样表示比较清楚明了，也可以不按顺序初始化成员变量
    struct student s2 = {
        .name = "gcx1",
                .age = 22
    };

    struct student s3;
    strcpy(s3.name, "杨过");
    s3.age = 44;

    printf("name = %s , age = %d \n", s1.name, s1.age);
    printf("name = %s , age = %d \n", s2.name, s2.age);
    printf("name = %s , age = %d \n", s3.name, s3.age);
}

// 结构体作为函数参数
/*
 * 注意：
 *      一般不建议把结构体作为函数参数，因为结构体的size比较大，直接传递，消耗性能；
 *      解决方案，使用指针
 */

// 11、全局变量和 局部变量

void east_travel(void); // 东游记
char master[16] = "女娲"; // 定义了一个全局变量，表示老大
void west_travel(void)  // 西游记
{
    // 局部变量master的作用域，覆盖了全局master的作用域
    char master[16] = "唐僧";
    printf("[西游] 的老大是： %s\n", master);
}

void north_travel(void)
{
    char master[16] = "牛魔王";
    printf("[北方] 的老大是： %s\n", master);
    char c;
    printf("是否进入女儿国？（Y/N) \n");
    fflush(stdin);
    scanf("%c", &c);
    if (c == 'Y' || c == 'y') { // 一个大括号就是一个作用域
        // 女儿国的国境
        char master[16] = "女王";
        printf("[女儿国] 的老大是： %s\n", master);

        {
            // 这个又是一个作用域，如果重新定义master，又是一个新的
        }
    }
    printf("[北方] 的老大是： %s\n", master);
    east_travel();
}


// 结构体练习
/* 1、独立完成项目交换机---端口管理
 *   main.c实现
 * 2、定义一个结构体，输入内容，然后输出
 * 3、
 */
struct hero {
    char name[16];
    char sex;
    int power;
};

void create_hero() {
    struct hero h1;
    printf("请输入角色的名称：");
    scanf("%s", h1.name);
    fflush(stdin);
    printf("请输入角色的性比：");
    scanf("%c", &h1.sex);
    printf("请输入角色的武力值：");
    scanf("%d", &h1.power);

    printf("\n\n====角色信息====\n");
    printf("[角色姓名]：%s\n", h1.name);
    printf("[角色性别]：%c\n", h1.sex);
    printf("[角色武力值]：%d\n", h1.power);
}

/*
 * 1、为什么要使用数组
 *  使用场合：需要保存很多同类型的数据，而且这些数据有严格的顺序
 *  数组的存储方式：按地址递增的方向，依次存储
 */

/*
 * 2、数组的定义
 */
struct position{
    int x;
    int y;
};
void show_position()
{
    struct position ps[10] = {
    {.x = 10, .y = 20},
    {.x = 30, .y = 40},
};
    for (int i=0; i<10; i++) {
        printf("x = %d, y = %d\n", ps[i].x, ps[i].y);
    }
}

/*
 * 3、变长数组
 *  在全局变量中不能使用变长数组
 */

/*
 * 5、二维数组的使用场景
 */

/*
 * 6、二维数组的定义
 */

/*
 * 7、二维数组的存储方式
 *  一行一行的存储，先存储完第一行，再存储第二行，依次存储
 */

/*
 * 8、二维数组的初始化
 */
void show_score()
{
    /*
     * 一个班有三门课，五个同学
     */
    // 方式1
    int score[5][3] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        10, 11, 12,
        13, 14, 15
    };

    // 方式2
    int score1[5][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        // {13, 14, 15}  // 如果不赋值，会默认为0；
    };

    // 方式3。当行数比较多的时候，指定行数进行赋值
    int score2[5][3] = {
        [1] = {1, 2, 3},
        [2] = {4, 5, 6},
    };

    for (int i=0; i<5; i++) {
        for (int j=0; j<3; j++) {
            //printf("score[%d][%d] = %d\n", i, j, score[i][j]);
            //printf("score[%d][%d] = %d\n", i, j, score1[i][j]);
            printf("score[%d][%d] = %d\n", i, j, score2[i][j]);
        }

    }

}

/*
 * 9、二维数组的使用
 *  数组不能直接赋值
 * 总结：
 *      1、不能对二维数组的数组名，直接设置值
 *          int data1[2][3] = {1, 2, 3};
 *          int data2[2][3];
 *
 *          // 这样是不允许的，错误的(以下三条）。总结1
 *          data2 = data1;
 *          data2[1] = data1[1];
 *          data2[1] = {1, 2};
 *      2、char类型的二维数组，可以存储多个字符串
 *          例子：show_info();
 */
void show_info()
{
    char info[3][16];
    printf("please input your name:");
    scanf("%s", info[0]);
    printf("please input your age:");
    scanf("%s", info[1]);

    printf("name = %s, age = %s \n", info[0], info[1]);

}

/*
 * 10，多维数组
 */
void multidimension_array()
{
    // 格式1
    int data[2][3][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // 格式2
    int data1[2][3][2] = {
        {   // data1[0]
            {1,2},
            {3,4},
            {5,6}
        },
        {   // data1[1]
            {7,8},
            {9,10},
            {11,12}
        }
    };
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<2; k++)
                printf("data[%d][%d][%d] = %d\n", i, j, k, data1[i][j][k]);
        }
    }
}

/*
 * 11、数组作为函数参数
 *  某班有5名学生，每个学生有一个考试成绩
 *  1、定义一个函数、计算平均成绩
 *  2、定义一个函数，如果某个成绩低于60分，就增加5分
 */

float average(int n, int data[])
{
    float sum=0;
    for (int i=0; i<n; i++) {
        sum += data[i];
    }
    return sum / n;
}

void add_score(int n, int data[])
{
    for (int i=0; i<n; i++) {
        if (data[i] < 60) {
            data[i] += 5;
        }
    }
}

/*
 * 11.12 项目练习
 *  1、有四名学员，每个学员有三名课程
 *      要求输入这四名成员的所有成绩，并分别计算每个课程平均成绩，和所有课程的平均成绩
 *      提示：要求用二维数组保存成绩
 *  2、定义一个函数，实现矩阵的逆转
 *  3、打印顺时针螺旋矩阵
 */
// 练习12.12.1
void calculate_score()
{
    int score[4][3] = {0};
    for (int i=0; i<4; i++) {
        printf("请依次输入第%d个学员的成绩，以空格分开\n", i+1);
        scanf("%d%d%d", &score[i][0], &score[i][1], &score[i][2]);
    }
    float sumall = 0;   // 总成绩
    for (int i=0; i<3; i++) {
        float sum = 0;  // 单科总成绩
        for (int j=0; j<4; j++) {
            sum += score[j][i];
            //sumall += score[j][i];
        }
        printf("第%d列的平均成绩为%.2f\n", i,  sum/4);
        sumall += sum;  // 优化
    }
    printf("所有课程的平均成绩为%.2f\n", sumall/12);
}

// 练习12.12.2
/*  例子：将行转成列
 * 1    2   3   4           1   5   9   13
 * 5    6   7   8   =>      2   6   10  14
 * 9    10  11  12  =>      3   7   11  15
 * 13   13  15  16          4   8   12  16
 */
void matrix_reverse()
{
    int s1[3][3] = {1,2,3,4,5,6,7,8,9};
    int s2[3][3] = {0};
    // 第一种赋值法
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            s2[j][i] = s1[i][j];
        }
    }
    // 第二种
    int tmp;
    for (int i=0; i<3-1; i++) { //不要重复赋值，由对角线可知，< n-1行就行。
        for (int j=i+1; j<3; j++) { // 也是不要重复赋值，由对角线知，大于对角线就行
            tmp = s1[i][j];
            s1[i][j] = s1[j][i];
            s1[j][i] = tmp;
        }
    }

    printf("====================\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%d\t", s1[i][j]);
        }
        printf("\n");
    }
    printf("====================\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%d\t", s2[i][j]);
        }
        printf("\n");
    }
}

// 11.12.3
/*
 *      1   2   3   4
 *      12  13  14  5
 *      11  16  15  6
 *      10  9   8   7
 */
void matrix_spiral(int n)
{
    int s[n][n] ;
    int num = 1;
    int m=n;
    if (m%2 != 0) m++;
    //n = m;
    for (int i=0; i<m/2; i++) {
        for (int j=i; j<n-i;j++) {
            s[i][j] = num ++;
        }
        for (int j=i+1; j<n-i;j++) {
            s[j][n-i-1] = num ++;
        }
        for (int j=n-i-2; j>=i;j--) {
            s[n-i-1][j] = num ++;
        }
        for (int j=n-i-2; j>i;j--) {
            s[j][i] = num ++;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }
}
void matrix_spiral2()
{
    int n;
    int i = 0, j = -1;
    printf("请输入你要的行数：");
    scanf("%d", &n);
    int val = 1;
    int max = n * n;
    int data[n][n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            data[i][j] = 0;
        }
    }

    while (1) {
        // 向右走
        j++; // 定义为-1，需要进入
        while (j<n && data[i][j] == 0) {
            printf("向[右]走 data[%d][%d] = %d\n", i, j, val);
            data[i][j++] = val++;
        }
        j--; // 由于多走了一步，所以要退一步
        if (val > max) break;

        i++;
        while (i<n && data[i][j] == 0) {
            printf("向[下]走 data[%d][%d] = %d\n", i, j, val);
            data[i++][j] = val++;
        }
        i--;
        if (val > max) break;

        j--;
        while (j>=0 && data[i][j] == 0) {
            printf("向[左]走 data[%d][%d] = %d\n", i, j, val);
            data[i][j--] = val++;
        }
        j++;
        if (val > max) break;

        i--;
        while (i>=0 && data[i][j] == 0) {
            printf("向[上]走 data[%d][%d] = %d\n", i, j, val);
            data[i--][j] = val++;
        }
        i++;
        if (val > max) break;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d\t", data[i][j]);
        }
        printf("\n\n");
    }
}

// 12、交换机后台管理之端口管理的再次优化（一）

/*
 *  12.1 为什么要使用指针
 *      函数的值传递，无法通过调用函数，来修改函数的实参
 */

/*
 * 12.2 指针的定义
 *      本质是一个地址值
 */
void pointers_definition()
{
    int age;
    /* 定义了一个指针
     * 指针是一个变量
     * 这个变量的名称是p
     * 这个指针，可以用来指向一个整数
     * 就是说，p的值是一个整数的地址
     */
    int * p;
    /*
     * 指针p指向了age
     * p的值，就只age的地址
     */
    p = &age;
    scanf("%d", p);
    printf("age is %d\n", age);
}

// 12.3 指针的初始化
// 12.4 指针的访问
// 12.5 2进制 ，16进制
// 12.6 指针的访问：访问指针所指向的内容
void pointer_init()
{
    int mygirl = 26;
    // 在定义指针的时候，使用*p，表示p是一个指针变量
    int *p1 = &mygirl;
    int *p2 = p1;

    // 1、访问（读，写）指针变量本身的值（和其他普通变量的访问形式一样）
    int *p3;
    p3 = p1; // 读指针p1的值，写入p3的值
    printf("p1 = %d, p2 = %d, p3 = %d\n\n", p1, p2, p3);  // 不建议使用此格式，不准确，例如：补码
    // 使用16进制打印，把地址值当做一个无符号数来处理的
    printf("p1 = %p, p2 = %p, p3 = %p\n", p1, p2, p3);
    printf("p1 = %x, p2 = %x, p3 = %x\n", p1, p2, p3);
    printf("p1 = %X, p2 = %X, p3 = %X\n\n", p1, p2, p3);
    // 优化
    printf("p1 = 0x%p, p2 = 0x%p, p3 = 0x%p\n", p1, p2, p3);
    printf("p1 = 0x%x, p2 = 0x%x, p3 = 0x%x\n", p1, p2, p3);
    printf("p1 = 0x%X, p2 = 0x%X, p3 = 0x%X\n\n", p1, p2, p3);

    // 2、访问指针所指向的内容
    int x;
    // 除了定义指针变量以外，对变量执行*操作，就是读取这个指针所指向的变量
    x = *p1;    // *是一个特殊的运算符，*p表示读取指针p所指向的变量的值
    printf("x = %d\n", x);

    mygirl++;
    printf("*p = %d\n", *p1);
}

// 12.7 空指针
/*
 * 1、什么是空指针
 *      空指针，就是值为0的指针
 * 2、访问空指针的后果
 *      导致程序崩溃
 * 3、空指针的使用
 *      1)指针初始化为空指针 int *p = 0;建议这样使用 int *p = NULL;目的就是避免访问非法数据
 *      2)指针不再使用时，设置为空指针
 *      3)表示这个指针还没有具体的指向
 */
void nullPointer()
{
    int *p;
    p = 0;  // p 就是一个空指针

    printf("%p\n", p);
    // 访问空指针的值，将导致程序奔溃
    printf("*p = %d\n", *p);    // 将读取地址为0的int类型变量

    printf("程序结束\n");
}

// 12.8 指向结构体的指针
struct friend {
    char name[32];
    char sex[4];
    int age;
};
void struct_pointer()
{
    struct friend f1 = {"迪丽热巴", "女", 26};
    struct friend *mygirl = &f1;

    // 直接通过结构体变量来访问该结构体内部的成员
    printf("name = %s , sex = %s, age = %d\n\n", f1.name, f1.sex, f1.age);

    // 通过指针p来访问结构体内部的成员,
    // 方式1， 很少使用此方式
    printf("name = %s , sex = %s, age = %d\n\n", (*mygirl).name, (*mygirl).sex, (*mygirl).age);
    // 方式2, -> 相当于取地址后再加.
    printf("name = %s , sex = %s, age = %d\n\n", mygirl->name, mygirl->sex, mygirl->age);

}

// 12.9 指针的自增运算
void test_0()
{
    int ages[] = {1,2,3,4,5,6,7,8,9,10};
    int len = sizeof (ages) / sizeof (ages[0]);
    // 使用数组的形式来访问
    printf("数组的形式访问\n");
    for (int i=0; i<len; i++) {
        printf("%d\t", ages[i]);
    }

    // 使用指针来访问
    printf("\n使用指针来访问\n");
    int *p = ages;
    for (int i=0; i<len; i++) {
        printf("%d\t", *p);
        p++;
    }

    // 优化
    printf("\n使用指针来访问---优化\n");
    for (int *p=ages;  p<ages+len; p++)
    {
        printf("%d\t", *p);
    }
}

// 12.10 指针的自减运算
/*
 * 让用户输入一个字符串，然后反向输出（不能改变原来的字符串）
 */
void test_1()
{
    // 方法一：改变字符串本身
    char str[] = "12345";
    int len = strlen(str);
    int tmp = 0;
    for(int i=0; i<len/2; i++) {
        tmp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = tmp;
    }
    printf("%s\n\n", str);

    // 方法2：不改变字符串
    char str1[] = "12345";
    int len1 = strlen(str1);
    for (int i=len1-1; i>=0; i--) {
        printf("%c", str1[i]);
    }
    printf("\n\n");
    // 方法三。改用指针的形式
    char str2[] = "12345";
    int len2 = strlen(str1);
    for (char *p = str2+len2-1; p >= str2; p--) {
        printf("%c", *p);
    }
    printf("\n\n");
}

// 12.11 指针与整数之间的加减运算
/*
 * 地址加操作就是在原来的指针地址的基础上加上一定的地址偏移，得到新地址
 * 从而通过*取得地址里面存储的内容
 * 比如指针+1， 并不是在指指针地址的基础之上加 1个地址，而是在这个指针地址的基础上加1个元素所占的字节数
 * 如果指针的类型是char *，那么这个时候1代表1个字节地址
 * 如果指针的类型是int *,那么这个时候1代表4个字节地址
 *
 * 结论：
 * p + n 实际指向的地址：p基地址（p里面存的值） + n*sizeof(数据类型)
 */
void test_2()
{
    char pikaqiu[] = {'1', '2', '3', '4'};
    char *p = pikaqiu;
    printf("%c 内存地址是 %p\n", *p, p);
    printf("%c 内存地址是 %p\n", *(p+1), p+1);
    printf("%c 内存地址是 %p\n", *(p+2), p+2);

    int ages[] = {22, 23, 24, 35, 66, 64, 31, 23};
    int *p1 = ages;
    printf("%d 内存地址是 %p\n", *p1, p1);
    printf("%d 内存地址是 %p\n", *(p1+1), p1+1);
    printf("%d 内存地址是 %p\n", *(p1+2), p1+2);
    printf("%d 内存地址是 %p\n", *(p1+4), p1+4);
}

// 12.12 指针与指针之间的加减运算
/*
 * 1、使用“指针-指针”的方式计算整数数组元素的偏移值
 * 2、使用“指针-指针”的方式计算字符串元素的 偏移值
 * 结论：
 *      1）指针和指针可以做减法操作，但不适合做加法操作
 *      2）指针和指针适合做减法的场合，两个指针都指向同一个数组，相减结果作为两个指针之间的元素数目，
 *         而不是两个指针之间相差的字节数
 */
void test_3()
{
    int ages[] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int *rock = ages + 2;
    int *margin = ages + 4;
    //printf("sizeof(int) = %d", sizeof (int));
    // 指针-指针 指的偏移值 （p1 - p1) / sizeof(int)
    printf("\n 指针-指针测试 : %p, %p, %d\n", margin, rock, margin -rock);
    printf("\n 指针-指针测试 : %p, %p, %d\n", margin, rock, rock - margin);

    // 目前指针的加法没有什么意义。
}

// 12.13 指向一维数组的指针
// 12.14 指向二维数组的指针
void test_4()
{
    int beauty[4][5];
    int k = 1;
    // 数组初始化
    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            beauty[i][j] = k++;
        }
    }
    // 打印数组
    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            printf("%d\t", &beauty[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    // 定义一维数组指针
    int (*p)[5];    // 规定，一定要带上括号（int * p[5],表示指针数组， p[0], p[1] ...)
    p = beauty[2]; // ==> p = &buauty[2];

    for (int i=0; i<5; i++) {
        printf("%d\t", (*p)[i]);
    }
    printf("\n\n");
    p--;
    for (int i=0; i<5; i++) {
        printf("%d\t", (*p)[i]);
    }
    printf("\n\n");

    /*
    // 有个问题没搞明白，这个地址打印出来并不是元素所在的地址
    for (int i=0; i<5; i++) {
        printf("%d\t", (p)[i]);     // 这个表示可能是当做指针数组来显示了，
    }
    printf("\n\n");
    for (int i=0; i<5; i++) {
        printf("%d\t", &beauty[1][i]);
    }
    printf("\n\n");
    // 输出为：
    //  6421844 6421864 6421884 6421904 6421924
    //  6421844 6421848 6421852 6421856 6421860
    */
    int (*p1)[4][5] = beauty;
    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            printf("%d\t", (*p1)[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

// 12.16 项目练习
/*
 * 字符串的逆转: 12345678  -->    87654321
 */
void test_5(unsigned char *ch)
{
    // 英文字符串的逆转很简单
    int len = strlen(ch);
    unsigned char tmp[len+1];
    unsigned char *p1 = ch;
    unsigned char *p2 = tmp + len;
    *p2-- = 0;
    while(*p1 != 0) {
        /*p2 = *p1;
        p2--;
        p1++;*/
        *p2-- = *p1++;
    }
    printf("%s\n", tmp);
}
//中文字符串的逆转(utf-8)
//中英文结合用ANSI编码格式参考12.16_ANSI.c(代码根目录下）
void test_6(unsigned char *name)
{
    int len = strlen(name);
    // 此时在utf-8编码格式时候一个汉字占三个字节，如果是ANSI编码，则占两个字节
    printf("len = %d\n", len);
    unsigned char tmp[len+1];
    unsigned char *p1 = name;
    unsigned char *p2 = tmp + len;
    *p2-- = 0;
    while(*p1) {
        if(*p1 < 0xA0) {
            *p2-- = *p1++;
        } else {
            *p2 = *(p1+2);
            *(p2 - 1) = *(p1 + 1);
            *(p2 - 2) = *p1;
            p2-=3;
            p1+=3;
        }
    }
    printf("%s\n", tmp);

}

// 13、复位指定端口
/*
 * 13.1 项目练习
 * 实现以下函数实现功能：
 * 如果英雄是攻击性英雄，每升一级血量+1000，攻击力+200
 * 如果英雄是防御性英雄，每升一级血量+2000，攻击力+50
 * 其他英雄暂不做处理
 * 类型定义：1：攻击性英雄 2：防御性英雄
 */
struct hero_stat{
    int blood;
    int power;
    int level;
    char name[64];
    char details[128];
};

struct hero_stat upgrade(struct hero_stat hero, int type) {
    switch (type) {
    case 1:
        hero.blood += 1000;
        hero.power += 200;
        hero.level++;
        break;
    case 2:
        hero.blood += 2000;
        hero.power += 50;
        hero.level++;
        break;
    default:
        break;
    }
    return hero;
}

/*
 * 函数参数使用指针的场景
 * 1、函数内部需要修改外部变量的值
 * 2、被调用函数需要提供更多的返回值，给调用函数
 * 3、减少值传递时带来的额外开销，提高代码执行效率
 */
// 需要函数返回值判断有没有修改成功
int upgrade1(struct hero_stat *hero, int type)
{
    int ret = 0;
    switch (type) {
    case 1:
        hero->blood += 1000;
        hero->power += 200;
        hero->level++;
        ret = 1;
        break;
    case 2:
        hero->blood += 2000;
        hero->power += 50;
        hero->level++;
        ret = 1;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

void test_7()
{
    struct hero_stat gcx;
    strcpy(gcx.name, "张德帅");
    gcx.blood = 3000;
    gcx.power = 400;
    gcx.level = 10;
    struct hero_stat *p = &gcx;
    if (upgrade1(p, 3)) {
        printf("gcx blood = %d, power = %d, level = %d\n", gcx.blood, gcx.power, gcx.level);
    } else {
        printf("类型不匹配\n");
    }

}

// 13.2 减少值传递时带来的额外开销，提高代码执行效率。代码测试
void test_8()
{
    struct hero_stat gcx;
    strcpy(gcx.name, "张德帅");
    gcx.blood = 3000;
    gcx.power = 400;
    gcx.level = 10;
    time_t start,end;
    time(&start);
    for (long long i=0; i<300000000; i++) {
        upgrade1(&gcx, 1);
    }
    time(&end);
    printf("gcx blood = %d, power = %d, level = %d, time = %d\n", gcx.blood, gcx.power, gcx.level, end-start);

    time(&start);
    for (long long i=0; i<300000000; i++) {
        upgrade(gcx, 1);
    }
    time(&end);
    printf("gcx blood = %d, power = %d, level = %d, time = %d\n", gcx.blood, gcx.power, gcx.level, end-start);
}

// 项目14
/*
 * 14.1 动态内存分配
 * void *malloc(size_t size);
 * 在内存的动态存储中分配一块长度为size字节的连续区域，返回该区域的首地址
 * 生死由你控制，消失的时候，只需要free他 void *free(void *);
 */

/*
 * 项目15 内存管理
 */
/*
 * 15.1 主要内容
 *  1）作用域 全局/局部变量或函数的作用区域
 *  2）修饰符 auto/register/extern/static等的使用
 *  3）变量初始化，养成对变量进行初始化的好习惯
 *  4）内存布局，代码区/静态区/堆区/栈区
 *  5）内存动态分配， malloc/calloc/realloc/free 四个函数
 */

/*
 * 15.2 作用域
 * 任何一种编程中，作用域是程序中定义的变量或函数所存在的区域。超过该区域变量或者函数就不能被访问。
 * 1）凡是在函数{}或{}以内的变量为局部变量，包括函数()形式参数
 * 2）凡是在函数{}外的变量为全局变量
 *
 * 1）局部变量的作用域，起始于定义处，知道所在的大括号结束
 * 2）全局变量的作用域，起始于定义处，知道本文件结束
 */

/*
 * 15.3 作用域叠加
 * 全局变量同局部变量的作用域叠加，在不同的作用域总，可以有重名的标识符，
 * 局部变量会覆盖全局变量的作用域（同一个作用域的变量名不能重名)
 * 就近原则：当全局变量和局部变量同名时，在局部范围内全局变量会被“屏蔽”，不再起作用。
 * 全局变量命名污染：函数是全局变量，要防止命名污染，全局变量的使用更要避免命名重名，尽量少用全局变量
 */

int test_15_3 = 100;
void testprint_9()
{
    printf("testprint_9_ = %d\n", test_15_3);
}
void test_9()
{
    testprint_9();
    printf("a = %d\n", test_15_3);
    int test_15_3 = 10;
    testprint_9();
    printf("a = %d\n", test_15_3);
    {
        testprint_9();
        printf("a = %d\n", test_15_3);
        int test_15_3 = 1;
        printf("a = %d\n", test_15_3);
        testprint_9();
    }
    printf("a = %d\n", test_15_3);
    testprint_9();
}

/*
 * 15.4 auto，register 修饰符
 *  修饰局部变量的两个：auto ,register
 *  auto：
 *      1)只能用于修饰局部变量，表示该变量存储在栈上stack
 *      2)局部变量默认的修饰符就是auto类型，所以通常将其省略
 *  register：
 *      1)只能修饰局部变量，将内存中的变量升级到cpu寄存器中去存储，这样访问速度会很快。
 *        存储cpu的变量，速度快但数量有限，通常用来优化，
 *      2）使用register修饰的变量不能去取地址
 *
 * 15.5 extern 修饰符
 *  extern 修饰变量
 *      1）用来修饰变量或者函数，extren可置于变量前或者函数前，已表示变量或者函数定义在别的文件中，提示编译器遇到此变量
 *         和函数时在其他模块中寻找其定义
 *      2）extern 修饰变量的声明
 *      3）需要注意的点：
 *          变量前有extern不一定就是声明，如果变量有被初始化就是定义
 *          而变量前无extern就是定义；
 *          注意：定义要为变量分配内存空间，而声名不需要为变量分配内存空间
 *      4）正确用法
 *          int a = 0；定义的时候赋予初始值，并在.c文件定义全局变量，不要在.h文件定义
 *          extern int a; 声明即可
 *
 *  extern 修饰函数
 *      1）函数声明和定义的区别：
 *          定义函数要有函数体，声明函数没有函数体并以封号结尾；
 *          函数同样可以多次声明，但是只能在一个地方定义
 *      2）当前模块使用外部模块的函数时，建议使用extren进行声明
 *      3) 注意：
 *         因为声明函数没有函数体，所以声明函数的时候可以将extern省略掉，但一般在头文件（.h）声明的时候才省略掉extern,
 *         如果在其他c文件中声明建议加上extern。为了增强程序可读性
 *
 *  extern和头文件的联系
 *      1）使用原则：
 *          不要在头文件（.h）中定义全局变量，全局变量定义在.c文件中，在.h文件中只是声明即可
 *          具体原因：多个c文件引用头文件会造成变量重复定义；
 *      2）在.h文件声明函数时，可以不适用extern进行修饰，且也不要在头文件中定义函数，函数定义放在c文件
 *
 *  这些要记住， c++编译器编译比较严谨，声明变量不加extern会默认识别为定义。
 */



extern int g_a;
void test_10()
{
    printf("g_a = %d\n", g_a);
}

extern void test_11(void);

/*
 *  15.6 static 修饰符
 *      1）限定作用域
 *          修饰全局变量-全局静态变量
 *          修饰函数，静态函数
 *      2）保持变量内容持久化
 *          修饰局部变量-局部静态变量
 *  修饰全局变量-全局静态变量：
 *      在全局变量前加上关键字static，全局变量就变成了一个全局静态变量（限定作用域）
 *      全局静态变量作用域被限定，只能在定义他的文件内可见，准确的说就是从定义处开始，到文件结尾
 *
 */
// 由于g_b定义时使用了static，所以不能再此文件进行声明，从而进行引用
extern int get_g_b(void);
void test_12()
{
    printf("g_b = %d\n", get_g_b());
}

/*
 * 15.7 static 修饰函数-静态函数
 *    在函数返回类型前加上关键字static，函数就定义为静态函数，静态函数只是在定义它的文件中可见，不能被其他文件所用。
 *    准确的说，是从定义处开始，文件结尾时结束
 * 使用原则：
 *  1）某一个函数不想被其他模块所引用，则使用static进行修饰
 *  2）不用的文件可能函数命名有相同，此时使用static修饰可以解决重命名的问题
 */

extern void test_13();

/*
 * 15.8 static 修饰局部变量
 * 在局部变量之前加上关键字static，局部变量就变成了局部静态变量
 * 作用域：作用域仍为局部作用域，当定义他的函数或者语句块结束的时候，作用域结束。
 *        但是当局部静态变量离开作用域后，并没有销毁，而是仍然驻留在内存之中，该函数再次被调用，并且其值和前次退出时一样
 * 生命周期：
 *        局部变量定义在栈上，函数退出后变量就被销毁
 *        局部静态变量定义在静态区，其在程序开始运行时就已经在内存里面
 *
 * 注意：
 * 相同点：局部静态变量和局部变量的作用域是一样的
 * 不同点：局部变量会被销毁，局部静态变量不会
 */

void test_14()
{
    //int s_call_count = 0;
    // 值被初始化了一次。他的生命周期和函数退出没有关系
    static int s_call_count = 0;
    printf("s_call_count = %d , mem = %p\n", s_call_count, &s_call_count);
    ++s_call_count;
    printf("++s_call_count = %d , mem = %p\n", s_call_count, &s_call_count);

    // 作用域测试:局部静态变量和局部变量的作用域是一样的
    {
        static int s_call_count = 10;
        printf("s_call_count 111 = %d , mem = %p\n", s_call_count, &s_call_count);
        ++s_call_count;
        printf("++s_call_count 111 = %d , mem = %p\n", s_call_count, &s_call_count);
    }
}
void test_15()
{
    test_14();
    test_14();
    test_14();
}

/*
 * 15.9 变量初始化的意义
 *  1）全局变量/静态全局变量/静态局部变量默认初始化为0；
 *  2）局部变量没有默认值
 */

/*
 * 15.10 内存布局-代码区
 *  通常是指用来存放程序执行代码的一块内存区域，这部分的大小在程序运行前就已经确定，并且内存区域通常属于只读
 *  在代码段中，也有包含一些只读的常数变量，例如字符串常量
 *
 *  代码区只读
 */
/**
 * @brief test_16 测试字符串常量属于哪个区
 */
void test_16()
{
    char name[] = "zhangsan";
    char *p_name = "zhangsan";
    printf("%p\t%p\t%p\n", name, p_name, test_16);

    name[0] = "1";
    printf("updata name = %s\n", name);

    //*p_name = "1";    // 这句代码导致程序崩溃
    printf("p_name = %s\n", p_name);
}

/*
 * 15.11 内存布局-静态区
 * 静态区存储的内容就是程序加载到内存的时候就确定，程序退出的时候从内存消失
 * 所有的全局变量/全局静态变量/局部静态变量都存储到静态区，在程序运行期间都占用内存。
 * 生命周期：静态区存储的变量生命周期从程序运行时开始，知道程序结束
 *
 * 静态区可读可写
 */
int g_17_1 = 10;
static int g_17_2 = 100;
void test_17()
{
    int g_3 = 1000;
    static int g_4 = 5000;

    printf("%p\t%p\t%p\t%p\n", &g_17_1, &g_17_2, &g_3, &g_4);
    //获取到的结果
    //0000000000408044        0000000000408048        000000000062FDBC        0000000000408050
}

/*
 * 15.11 内存布局-栈区
 *
 * 1）函数调用先进后出
 * 2）函数入栈是从高地址到低地址变化
 * 3）函数调用入栈占用的空间和出栈时释放的空间是一致的
 * 4）函数调用栈的深度由什么决定？由函数栈上分配的空间决定。如果分配较大的数组，则栈比较深
 * 5）栈上不能分配太大的数组（比如2M），否则栈会溢出，导致程序崩溃
 * 6）栈变量的生命周期，他是在执行的时候开始，直到函数调用结束时栈退出。注意：生命周期是和作用域没关系的
 */

/*
 * 15.12 内存布局-堆区
 *  也叫动态内存分配区域，由程序员自己分配和释放内存的区域
 *  和栈区的区别
 *  （1）栈区分配的空间不能太大，一般不能超过2M，堆区可以分配较大的内存空间，只要内存足够大（100M/1000M都没有问题）
 *  （2）栈区的变量空间由系统自动分配和释放，堆区要自己申请和释放，不主动释放会引起内存泄漏。会引起内存奔溃
 */

void test_heap()
{
    char *p1 = malloc(1024*1024*100);
    char *p2 = malloc(1024*1024*10);
    printf("test_heap p1 = %p, p2 = %p\n", p1, p2);
    free(p1);
    free(p2);
}
void test_stack()
{
    char p1[1024*1024*1];
    //char p2[1024*1024*1]; // 栈分配的内存不能超过2M
    char p2[1024*1];
    printf("test_heap p1 = %p, p2 = %p\n", p1, p2);
}

void test_18()
{
    test_heap();
    test_stack();
}
//#################内存动态分配################
/*
 * 15.13 malloc
 *  #include <stdlib.h>
 *  void *malloc( size_t size );
 *  函数malloc()返回一个指针，指向一个大小为size的内存块，如果有错误，则返回NULL。
 *  指向的内存将位于堆上，而不是堆栈上，因此请确保在使用完毕后释放它。
 */
void test_malloc()
{
    //1、malloc返回的是void类型，gcc编译器要求我们需要类型转换，比如这里转换为int *
    int *p_a = (int *)malloc(10*sizeof (int));
    // 在工程上，我们一定要做判断看指针是否为空
    if (!p_a) {
        printf("malloc失败, p_a = %p\n", p_a);
        exit(1);
    }
    // 2、malloc分配的内存他的值是随机
    for (int i=0; i<10; i++) {
        printf("%d  ", *(p_a+i));
    }

    //赋值
    for (int i=0; i<10; i++) {
        *(p_a+i) = i;
    }

    printf("\n\n打印出初始化后的值\n");
    for (int i=0; i<10; i++) {
        printf("%d  ", *(p_a+i));
    }
    printf("\n free前p指向的内存 = %p\n", p_a);
    // 3、 free掉后就不要再去操作这片内存区域了（不管读和写).建议free掉后，将指针赋值为NULL；，我们这儿只是测试
    free(p_a);
    //p_a = NULL;

    printf("\n free后p指向的内存 = %p\n", p_a);
    printf("\n\n测试free后指向的内存区域值\n");
    for (int i=0; i<10; i++) {
        printf("%d  ", *(p_a+i));
    }

    // 4、free掉后还往指向的内存空间写数据是不允许的，会导致程序崩溃
    printf("\n\n 测试free后还往指向的内存空间写数据\n");
    for (int i=0; i<10; i++) {
        *(p_a+i) = i+10;
    }
    printf("\n\n测试打印free后还往指向的内存空间写数据\n");
    for (int i=0; i<10; i++) {
        printf("%d  ", *(p_a+i));
    }
}

void mainStudyFunction()
{
    /*  sum
    int s = sum(10);
    printf("sum = %d\n", s);
    */

    /*
    int x, y, z;
    x = 100;
    y = 200;
    z = add(x, y);  // 函数调用
    printf("add = %d\n", z);
    */
    //recursive();
    //printf("sum1 = %d\n", sum1(3));
    //show_pyramid('%', 20);
    //printf("recursive_sum = %d\n", recursive_sum(10));
    //hannuota(2, "A柱", "B柱", "C柱");

    //init_struct();

    //north_travel();
    //create_hero();
    //show_position();
    //show_score();
    //show_info();
    //multidimension_array(); // 11.10
    /*
    int data[5] = {65, 60, 55, 50, 77};
    printf("average = %.2f\n", average(5, data));
    add_score(5, data);
    for (int i=0; i<5; i++) {
        printf("%d\t", data[i]);
    }
    */
    //matrix_reverse();
    //matrix_spiral(9);
    //matrix_spiral2();
    //pointers_definition();
    //pointer_init();
    //nullPointer();
    //struct_pointer();
    //test_5("12345678");
    //test_6("my name is 张德帅，oyeah!");
    test_malloc();
}
