#include "study_1.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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


/**
  * �ַ�����һЩ��ʶ
  * scanf()
  * gets()
  * fgets()
  * strlen()
  * strcpy()
  */
void test3()
{
    //scanf,ȱ�㣬���ܶ�ȡ�ո��Ʊ���ȡ�����Խ��
    //gets, ��ȡһ�У������س���������������س���������Խ��
    //fgets����ȡָ�����ȣ���ȡָ�����Ⱥ������
    /**
     * string.h
     * strlen() �ַ�������
     * strcpy(char *s1, char *s2) ��s2 ������s1,������Ҳ������ȥ�����ܵ����ַ���Խ��
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
    }   //��� ��gcx 567890��
    printf("\n");


    /**
     * strncpy(char *a, char *b, int n); �ַ�������
     */
    char s5[32] = "1234567890"; //{1,2,3,4,5,6,7,8,9,0,\0}
    printf("the length of s5 is %d\n", strlen(s5));     //10
    printf("s5 is %s\n", s5);
    char s6[32] = "gcx";
    strncpy(s5, s6, 3);
    printf("s5-3 is %s\n", s5); // ���gcx4567890
    strncpy(s5, s6, 5);         //��ʱ����5λ����Ĭ�Ͽ���gcx00,û�е�Ĭ����Ϊ0��
    printf("s5-5 is %s\n", s5); // ��ʱ���Ϊgcx,��Ϊ0Ϊ����������ʵ�ַ����������{g,c,x,\0,\0,6,7,8,9,0}


    /**
     *  strcat(char *s1, char *s2) �ַ���ƴ�� s1 = s1 + s2;
     *  s1 = {1, 2, 3, 4, \0};
     *  s2 =              {a, b, c, \0};
     *  ʹ��strcat(s1, s2)��
     *  s1 = {1, 2, 3, 4, a, b, c, \0}
     *  s2 =             {a, b, c, \0};
     */
    //eg
    char s7[32] = "����ʡ";
    char s8[32] = "ƽ����";
    strcat(s7, s8);
    printf("s7 is %s\n", s7);   //����ʡƽ����
    printf("s8 is %s\n", s8);   //ƽ����
}

void  testBool() {
    //c89��int��ʾbool���ͣ����鴿c��Ŀ������int���ͱ�ʾ��٣����������ԱȽϺá� 0=�٣� ��0= ��
    if(-1) {
        printf("-1 is true\n");
    }
    if(0){
        printf("0 is false\n");
    }
    if(1){
        printf("1 is true\n");
    }
   //c99��׼
    bool ret;
    ret = 3>5;
    printf("ret = %d\n", ret);
    ret = 3<5;
    printf("ret = %d\n", ret);

    if (true) {
        printf("true is ��\n");
    }

    if(false) {
        printf("false is ��\n");
    }
}

/**
 * �����Լ�,ֻ�ܶԱ��������������������
 * x = i++; x = i; i = i+1;
 * x = ++i; i = i+1, x = i;
 *
 */

void testComma()
{
    // ���ű��ʽ
    int ret1,ret2;
    ret1 = (2+2, 3+3, 4+4); //8
    ret2 = 2+2, 3+3, 4+4;   //4
    printf("ret1 = %d, ret2 = %d\n", ret1, ret2);
}

//��Ŀ�����
void testSanMu()
{
    int age,day;
    printf("�������������:");
    scanf("%d", &age);
    day = age>24 ? 0:1;
    printf("day is %d\n", day);
}

//����ת��
/**
 * 1����ʽ����ת��
 *      ��������ת�� float ret1; ret1 = 10 *3.14; => 10.0 *.3.14;
 *      ��ֵת�� int x; x=3.14; => x=3;
 *      ���ת�� printf("%c\n", 255+50); => 305 -> 49 ('1')
 *          100110001 -> 00110001 -> 43 -> '1'
 * 2��ǿ������ת��
 *      printf("%d\n", (char)256+100);
 */

//��������ȼ�
// ! > ��������� > ��ϵ����� > && > || > ��ֵ�����
// ������ȼ��� ���������
void studyTest1()
{
    testSanMu();
}
