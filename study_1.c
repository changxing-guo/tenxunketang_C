#include "study_1.h"
#include <stdio.h>

void a()
{
    printf("---交换机管理系统---\n");
    printf("1、登陆--\n");
    printf("2、创建账号\n");
    printf("3、--\n");
    printf("4、退出--\n");
}

void b()
{
    char a = 97;
    char b = 'a';
    printf("%d \n", a);
    printf("%d \n", b);
    printf("%c \n", a);
    printf("%c \n", b);

}

void c()
{
    printf("\a");

}

void d()
{
    int a, b, c, ret;
    ret = scanf("%d%d%d", &a, &b, &c);
    printf("ret = %d\n", ret);

}

void e()
{
    float a;
    double b;
    scanf("%f", &a);
    scanf("%lf", &b);

    printf("a = %f , b = %lf \n", a, b);
}

void f()
{
    char name;
    name = getchar();
    putchar(name);

}

void g()
{
    char name;
    name = getc(stdin); //输入一个字符，stdin表示“标准输入设备”，默认是键盘
    putc(name, stdout);  //stdout标准输出设备，可以输出到其他文件
}


void studyTest1()
{
    f();
}

//查看程序的结束状态（编译结束后输入）
// echo %errorlevel%

//编译.默认为a.exe,如果重命名的话，如下所示
//gcc main.c -o testmain

