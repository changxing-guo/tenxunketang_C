#include "study_1.h"
#include <stdio.h>
#include <string.h>

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


//查看程序的结束状态（编译结束后输入）
// echo %errorlevel%

//编译.默认为a.exe,如果重命名的话，如下所示
//gcc main.c -o testmain

//练习
//输入一个圆的半径，输出周长和面积
void test1()
{
    float r, s, c;
    printf("please input the radius of the circle : ");
    scanf("%f", &r);
    s = 3.14 * r * r;
    c = 2 * 3.14 * r;
    printf(" the area is %f , the perimeter is %f .", s, c);
}

//输入一个小写字母，输出对应的大写字母
void test2()
{
    char num1, num2;
    printf("请输入一个小写字母 : ");
    scanf("%c", &num1);
    //num2 = num1 - 32;
    num2 = num1 - ('a' - 'A');
    printf("%c 的大写字母是 %c.", num1, num2);

}


/**
  * 字符串的一些常识
  * scanf()
  * gets()
  * fgets()
  * strlen()
  * strcpy()
  */
void test3()
{
    //scanf,缺点，不能读取空格，制表符等。容易越界
    //gets, 读取一行，遇到回车符结束，不保存回车符，容易越界
    //fgets，读取指定长度，读取指定长度后结束，
    /**
     * string.h
     * strlen() 字符串长度
     * strcpy(char *s1, char *s2) 将s2 拷贝给s1,结束符也拷贝过去，可能导致字符串越界
     */
    char s1[32];
    char s2[32];

    int len = 0;
    fgets(s1, 5, stdin);
    printf("s1  = %s \n", s1);
    len = strlen(s1);
    printf("the length of s1 is %d\n", len);
    strcpy(s2, s1);
    printf("s2  = %s \n", s2);

    //eg
    char s3[32] = "1234567890";
    char s4[32] = "gcx";
    strcpy(s3, s4);
    printf("s3  = %s \n", s3);
    for (int i = 0; i<sizeof(s3)/sizeof (s3[0]);i++) {
        printf("%c",s3[i]);
    }   //输出 “gcx 567890”
    printf("\n");


    /**
     * strncpy(char *a, char *b, int n); 字符串拷贝
     */
    char s5[32] = "1234567890"; //{1,2,3,4,5,6,7,8,9,0,\0}
    printf("the length of s5 is %d\n", strlen(s5));     //10
    printf("s5 is %s\n", s5);
    char s6[32] = "gcx";
    strncpy(s5, s6, 3);
    printf("s5-3 is %s\n", s5); // 输出gcx4567890
    strncpy(s5, s6, 5);         //此时拷贝5位，会默认拷贝gcx00,没有的默认设为0，
    printf("s5-5 is %s\n", s5); // 此时输出为gcx,因为0为结束符，其实字符串保存的是{g,c,x,\0,\0,6,7,8,9,0}


    /**
     *  strcat(char *s1, char *s2) 字符串拼接 s1 = s1 + s2;
     *  s1 = {1, 2, 3, 4, \0};
     *  s2 =              {a, b, c, \0};
     *  使用strcat(s1, s2)后
     *  s1 = {1, 2, 3, 4, a, b, c, \0}
     *  s2 =             {a, b, c, \0};
     */
    //eg
    char s7[32] = "甘肃省";
    char s8[32] = "平凉市";
    strcat(s7, s8);
    printf("s7 is %s\n", s7);   //甘肃省平凉市
    printf("s8 is %s\n", s8);   //平凉市
}

void studyTest1()
{
    test3();
}
