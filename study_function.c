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
    recursive();

}
