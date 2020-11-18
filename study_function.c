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
    pointer_init();
}
