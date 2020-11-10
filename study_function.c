/* ########     function    ######## */

#include <stdio.h>
#include <study_function.h>

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
    hannuota(2, "A柱", "B柱", "C柱");
}
