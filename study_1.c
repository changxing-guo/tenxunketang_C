#include "study_1.h"
#include <stdio.h>

void a()
{
    printf("---����������ϵͳ---\n");
    printf("1����½--\n");
    printf("2�������˺�\n");
    printf("3��--\n");
    printf("4���˳�--\n");
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
    name = getc(stdin); //����һ���ַ���stdin��ʾ����׼�����豸����Ĭ���Ǽ���
    putc(name, stdout);  //stdout��׼����豸����������������ļ�
}


void studyTest1()
{
    test2();
}


//�鿴����Ľ���״̬��������������룩
// echo %errorlevel%

//����.Ĭ��Ϊa.exe,����������Ļ���������ʾ
//gcc main.c -o testmain

//��ϰ
//����һ��Բ�İ뾶������ܳ������
void test1()
{
    float r, s, c;
    printf("please input the radius of the circle : ");
    scanf("%f", &r);
    s = 3.14 * r * r;
    c = 2 * 3.14 * r;
    printf(" the area is %f , the perimeter is %f .", s, c);
}

//����һ��Сд��ĸ�������Ӧ�Ĵ�д��ĸ
void test2()
{
    char num1, num2;
    printf("������һ��Сд��ĸ : ");
    scanf("%c", &num1);
    //num2 = num1 - 32;
    num2 = num1 - ('a' - 'A');
    printf("%c �Ĵ�д��ĸ�� %c.", num1, num2);

}
