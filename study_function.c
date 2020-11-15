/* ########     function    ######## */

#include <stdio.h>
#include <study_function.h>
#include <string.h>

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
    show_score();
}
