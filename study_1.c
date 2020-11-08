#include "study_1.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

void a()
{
    system("cls");
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

// while test.���ַ�ʽ�����Լ���ϰ�߾����������Ե�
void test_while1()
{
    int i = 1;
    while(1) {
        printf("1�����%dֻ��\n", i);
        if (10 == i) break;
        i++;
        //sleep(1); //�����linux�ӿڣ���λ��
        Sleep(1000); // �����windows�ӿڡ���λ���롣ͷ�ļ�windows.h
    }
    printf("��˯����\n");
}

void test_while2()
{
    int i = 1;
    while(i <= 10) {
        printf("2�����%dֻ��\n", i);
        //if (10 == i) break;
        i++;
        //sleep(1); //�����linux�ӿڣ���λ��
        Sleep(1000); // �����windows�ӿڡ���λ���롣ͷ�ļ�windows.h
    }
    printf("��˯����\n");
}

//ѭ����ϰ
//1��������
void pyramid()
{
    int n;
    printf("������������Ĳ�����");
    scanf("%d", &n);
    for(int i=1; i<n+1;i++) {
        //printf("%d %d\n", i, n);
        for(int j=0; j<n-i; j++) {
            printf(" ");
        }
        for(int k=0; k<2*i-1; k++) {
            printf("*");
        }
        printf("\n");
    }
}

//��ӡ�˷��ھ���
void multiplicationTable()
{
    for(int i=1; i<=9; i++) {
        for(int j=1; j<i+1;j++) {
            printf("%dX%d=%d\t", i, j, i*j);
        }
        printf("\n");

    }
}

//��ת�ַ���
void flipStr()
{
    char buff[64];
    printf("������һ���ַ�����");
    gets(buff);
    int len = strlen(buff);
    printf("the str strlen is %d\n", len);
    for(int i=0; i<len/2; i++) {
        char tmp = buff[i];
        buff[i] = buff[len-i-1];
        buff[len-i-1] = tmp;
    }
    printf("�����%s", buff);

}

//��ӡ쳲��������С�
void printFibonacciSequence()
{
    int n;
    printf("������쳲��������еĳ��ȣ�");
    scanf("%d", &n);
    if(n<1) {
        printf("��С����Ϊ1\n");
        return ;
    } else if (n == 1) {
        printf("1\n");
        return ;
    } else if(n == 2) {
        printf("1,1\n");
        return ;
    }
    // n > 2
    printf("1,1");
    int num1=1,num2=1;
    int tmp;
    for(int i=2; i<n; i++){
        tmp = num1+num2;
        printf(",%d", tmp);
        num1 = num2;
        num2 = tmp;
    }

}

/**
 * FILE *fopen(const char *fname, const *char mode);
 * ����1 �� fname �ļ���������·�������·��
 * ����2 �� mode �򿪷�ʽ
 * ����ֵ�� FILE * �ļ�ָ�롣��ʧ�ܷ���NULL(����0)
 *  mode
 *      "r"     �ԡ������ķ�ʽ��һ���ı��ļ���ֻ�ܡ�����
 *      "r+"    �롰r�����������ڣ������ˡ�д��
 *      "rb"    �ԡ������ķ�ʽ��һ���������ļ�
 *      "rb+"   �롰rb�����������ڣ������ˡ�д��
 *
 *      "w"     �ԡ�д���ķ�ʽ����һ���ı��ļ����������ļ��Ѵ��ڣ��ͻḲ��ԭ�����ļ�
 *      "w+"    �롰w�����������ڣ������ˡ�����
 *      "wb"    �ԡ������ķ�ʽ����һ���������ļ�
 *      "wb+"   �롰w+�����������ڣ������ˡ�����
 *
 *      "a"     �ԡ�β��׷�ӡ��ķ�ʽ��һ���ı��ļ���ֻ��д��
 *      "a+"    �롰a�����������ڣ������ˡ�����
 *      "ab"    �ԡ�β��׷�ӡ��ķ�ʽ��һ���������ļ���ֻ��д��
 *      "ab+"   �롰ab�����������ڣ������ˡ�����
 */

// ��ȡusers.txt�ļ�����ӡ����
void test_fgetc()
{
    FILE *file ;
    char buff;

    file = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
    /*while(1) {
        buff = fgetc(file);
        if (buff == EOF) break; // EOF = -1 ���ļ���β�������־
        printf("%c", buff);
    }*/

    while((buff = fgetc(file)) != EOF) {    //�˴� Ҫע������������ȼ�
        printf("%c", buff);
    }

    fclose(file);
}

/**
 * fgetc, fputc
 * ���󣬰�����ļ����ݸ��Ƶ�study_copyTest.c
 */
void testCopy()
{
    FILE *sourceFile;
    FILE *copyFile;
    char buff;

    sourceFile = fopen("E:\\qtcode\\tenxunketang_C\\study_1.c", "r");
    copyFile = fopen("E:\\qtcode\\tenxunketang_C\\study_copyTest.c", "w");
    if (!sourceFile || !copyFile) {
        printf("sourceFile�ļ�����copyFile�ļ���ʧ��\n");
    }

    while ((buff = fgetc(sourceFile)) != EOF) {
        fputc(buff, copyFile);
    }

    fclose(sourceFile);
    fclose(copyFile);
}

// fgets
/**
 * @brief test_fgets
 * #include <stdio.h>
 * char *fgets( char *str, int num, FILE *stream );
 * ����������num-1���ַ������������ļ�������EOFΪֹ(���ļ�������)
 * ����ֵ����ȡʧ��ʱ������NULL
 *         ��ȡ�ɹ�ʱ������str
 */
//���󣺴�ӡ���ļ�����Ļ
void test_fgets()
{
    FILE *file;
    char *buff;
    file = fopen("E:\\qtcode\\tenxunketang_C\\study_1.c", "r");
    if(!file) {
        printf("�ļ���ʧ��\n");
    }

    while(fgets(buff, 128, file)) {
        printf("%s", buff);
    }
    /*char * ret;
    ret = fgets(buff, 128, file);
    printf("%s", ret);
    printf("\n\n%d", NULL);
    */

    fclose(file);
}

/**
 * #include <stdio.h>
 * int fputs( const char *str, FILE *stream );
 */
// ���󣬽�study_1.cд��filewritetest.txt
void test_fputs()
{
    FILE *file_out;
    FILE *file_in;
    char buff[128];
    file_out = fopen("E:\\qtcode\\tenxunketang_C\\study_1.c", "r");
    file_in = fopen("E:\\qtcode\\tenxunketang_C\\filewritetest.txt", "w");
    if (!file_in || !file_out) {
        printf("�ļ���ʧ��\n");
        return;
    }
    while (fgets(buff, sizeof (buff), file_out)) {
        fputs(buff, file_in);
    }
    fclose(file_out);
    fclose(file_in);
    printf("�ļ�������ɣ����Ͱ�������\n");

}

/**
 * #include <stdio.h>
 * int fprintf( FILE *stream, const char *format, ... );
 * ���ļ����ո�ʽ�洢
 */
// ���󣬽���ȡ�������������䰴�ո�ʽ�洢
void test_fprintf_1()
{
    FILE *file;
    //char *ret;
    char name[32];
    int age;
    int age2;
    char c;

    file = fopen("E:\\qtcode\\tenxunketang_C\\filewritetest.txt", "a");
    if (!file) {
        printf("�ļ���ʧ��\n");
    }

    while(1) {
        printf("���������������");
        // ��������gcx
        scanf("%s", name);  //��ʱ������Ϊ g c x \n , scanf ���»س���ȡ�󣬻���������"\n"
        printf("������������䣺");
        // �������� 22
        scanf("%d", &age);  //��ʱ������Ϊ \n 22 \n, ���»س�����%d ����ȡ\n�������������Զ���22������������"\n"
        //��ʱӦ�����������������һ��scanf��ȡ�ַ������ַ�����ʱ����ȡ�����"\n"
        //���������
        //fflush(stdin); //��򵥵ķ�ʽ�����Ҫ�����ԺõĻ��������������
        while ((c=getchar()) != '\n') {} //ѭ����ջ�����������ȡ��\n��ʱ������ѭ��

        fprintf(file, "name:%s\t\tage:%d\n", name, age);
        printf("��Ҫ����������(Y/N)\n");
        scanf("%c", &c);
        if (c == 'Y' || c == 'y') {
            continue;
        } else {
            break;
        }
    }
    fclose(file);
}

//��users.txt�ж�ȡ�����ı����ո�ʽ�洢
void test_fprintf_2()
{
    FILE * file_user;
    FILE * file_test;
    char line[128];
    char * ret_line;
    char name[32];
    char passwd[32];

    file_user = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
    file_test = fopen("E:\\qtcode\\tenxunketang_C\\filewritetest.txt", "a");
    if (!file_test || !file_user) {
        printf("�ļ���ʧ��\n");
        return;
    } else {
        printf("�ļ��򿪳ɹ�\n");
    }
    printf("�ļ���ʼд��\n");
    while(1) {
        ret_line = fgets(line, sizeof (line), file_user);
        if (!ret_line) {
            break;
        }
        sscanf(line, "%s %s", name, passwd);
        fprintf(file_test, "name:%s\t\tage:%s\n", name, passwd);
    }
    printf("�ļ�д�����\n");
    fclose(file_user);
    fclose(file_test);

}

// scanf ��ʽ����ȡ����
/**
 * ����:���룺name=gcx age=22
 *      ���name = gcx, age = 22
 */
void test_scanf() {
    char name[32];
    int age;
    //scanf("name=%s age=%d", name, &age); //�������һ����Ч��
    fscanf(stdin, "name=%s age=%d", name, &age);
    printf("name = %s, age = %d \n", name, age);
}

/*
 * ��test_fscanf.txt�и�ʽ����ȡ�ı�
 * Ŀǰ���Կ����ļ���ʽ����ͳһ����Ȼ�Ļ��ᵼ�³������
 */
void test_fscanf()
{
    char name[32];
    int age;
    FILE * file;
    int ret;

    file = fopen("E:\\qtcode\\tenxunketang_C\\test_fscanf.txt", "r");
    if (!file) {
        printf("�ļ���ʧ��\n");
        return;
    }
    /*while (1) {
        ret = fscanf(file, "name=%s age=%d\n", name, &age);
        printf("ret = %d\n", ret);
        if(ret == EOF) {break;}
        printf("name = %s, age = %d\n", name ,age);
    }*/

    while (fscanf(file, "name=%s age=%d\n", name, &age) != EOF) {
        printf("name = %s, age = %d\n", name ,age);
    }
    fclose(file);
}

/*
    #include <stdio.h>
    int fwrite( const void *buffer, // Ҫд�����ݵ���ʼ��ַ��Ҳ���Ǳ����ĵ�ַ
                size_t size,        // ÿ�����ݵĴ�С
                size_t count,       // д������ݿ�ĸ���
                FILE *stream );     // д����ļ�ָ��
    // ���󣬰Ѷ������ļ��Զ����Ʊ��浽test_fwrite.txt
*/
void test_fwrite()
{
    char name[32];
    int age;
    FILE * file;

    printf("���������������");
    scanf("%s", name);
    printf("������������䣺");
    scanf("%d", &age);
    file = fopen("E:\\qtcode\\tenxunketang_C\\test_fwrite.txt", "wb"); // �Զ�����д�ķ�ʽ��
    if (!file) {
        printf("�ļ�д��ʧ��\n");
        return;
    }
    fwrite(name, sizeof(char), sizeof (name), file);
    fwrite(&age, sizeof (int), 1, file);
    printf("�ļ�д����ɣ����������ļ�\n");
    fclose(file);
}

/*
 * windowsƽ̨��w��wb��С��
 *
 *  �������ļ�д�벹�䣬fwrite
    ��windowsƽ̨�£���ʹ��w��ʽ���ļ�ʱ��
    ���ʹ��fwriteд������ʱ�����'\n'д��Ϊ'\r''\n'
    ����'\n'����Ϊ13 10
    ��Ϊ��windowsƽ̨��   ���ı��ļ��Ļس���'\n',�ᱣ��Ϊ'\r\n'
    ('\n'��ASCII ��Ϊ10��'\r'��ASCII ��Ϊ13)

    ����wb��ʽ���ļ�ʱ��
    ���ʹ��fwrite��ʽд�������ǣ�����'\n'��ֻд��Ϊ'\n'
*/

// fread �Զ����Ƶ���ʽ��ȡ����
void test_fread()
{
    FILE * file;
    char name[32];
    int age;

    file = fopen("E:\\qtcode\\tenxunketang_C\\test_fwrite.txt", "rb");
    if (!file) {
        printf("�ļ���ʧ��\n");
        return;
    }
    fread(name, sizeof (char), sizeof (name), file);
    fread(&age, sizeof (int), 1, file);
    printf("name = %s, age = %d\n", name, age);
    fclose(file);
}

// putw �Զ�������ʽ�洢һ������
/*
 * �Դ����ļ�дһ���֣�������
 * int putw(int w, FILE *fp);������wд��fpָ����ļ�
 * �����������������������򷵻�EOF
 */
void test_putw()
{
    FILE * file;
    int a[] = {1,2,-1,4,5};
    int a_len;

    file = fopen("E:\\qtcode\\tenxunketang_C\\test_putw.txt", "wb");
    if (!file) {
        printf("�ļ���ʧ��\n");
        return;
    }
    //�鿴����ĳ��ȡ�ע��ʹ�� sizeof (a) / sizeof (int);����ʹ��strlen������ǿ��ַ�����
    a_len = sizeof (a) / sizeof (int);
    printf("a_len = %d\n", a_len);
    for (int i = 0; i < a_len; i++) {
        putw(a[i], file);
    }
    fclose(file);
}

// getw��������ʽ��ȡ����
/*
 * int getw(FILE *fp)
 * ��fp��ָ���ļ���ȡ��һ���֣�������
 * �������������������ļ��������߳�����-1��
 */
void test_getw()
{
    printf("the function is test_getw\n");
    FILE * file;
    int i;
    file = fopen("E:\\qtcode\\tenxunketang_C\\test_putw.txt", "rb");

    if(!file) {
        printf("�ļ���ʧ��\n");
        return;
    }

    // ���ֶ�ȡ��ʽ�и����⣬ӦΪEOF ��ֵ����-1���������Ƕ�ȡ�ϸ���������������ǣ�ֻ�ܶ�ȡ����
    // �����ȡint a[] = {1,2,-1,4,5}; ��ʱֻ�ܶ��� 1,2
    /*
    while((i = getw(file)) != EOF) {
        printf("%d ", i);
    }
    */

    // ���ǽ�����������ļ�״̬�жϺ�����������
    // �����ȡint a[] = {1,2,-1,4,5}; ��ʱȴ����1,2,-1,4,5,-1
    // ��Ϊ�ļ�����������-1������Ҳ������������ַ�ʽ������覴�
    /*
    while (!feof(file)) {   // ���ļ���ȡδ������ʱ��
        i = getw(file);
        printf("%d ", i);
    }
    */

    // �� ��������ô��ֻ��ȡ�����õ�����
    while (1) {
        i = getw(file);
        if (i == -1 && feof(file)) {
            break;
        }
        printf("%d ", i);
    }
    fclose(file);
}


// feof
/**
 * ������ϵ��ļ�������������ļ��������򷵻ط�0ֵ�����򷵻�0���ļ�������ֻ�ܱ�clearerr()�����
 * int feof(FILE *stream);
 * feof�ж��ļ�������ͨ����ȡ����fread/fscanf�ȷ��ش�����ʶ��ģ��ʶ��ж��ļ��Ƿ����Ӧ�����ڶ�ȡ����֮������ж�
 * ���磬��whileѭ����ȡһ���ļ�ʱ��������ڶ�ȡ����֮ǰ�����жϣ�������ļ����һ���ǿհ��У����ܻ�����ڴ����
 */

// ferror
/**
 * int ferror(FILE *stream);
 * ferror�����������ڵ��ø������������������ putc.getc.fread.fwrite�ȣ�ʱ��
 * ������ִ��󣬳��˺�������ֵ������ӳ�⣬��������ferror������顣
 * ����һ�������ʽΪ ferror(fp)�����ferror����ֵΪ0���٣�����ʾδ����
 * �������һ������ֵ����ʾ����
 * Ӧ��ע�⣬��ͬһ���ļ� ÿһ�ε����������������������һ���µ�ferror�� ��ֵ��
 * ��ˣ�Ӧ���ڵ���һ��������������������� ��ferror������ֵ��������Ϣ�ᶪʧ��
 * ��ִ��fopen����ʱ��ferror�����ĳ�ʼֵ�Զ���Ϊ0��
 */
void test_ferror() {
    FILE * file;
    file = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
    if(!file){
        printf("�ļ���ʧ��\n");
        return;
    }
    fputc("Y" ,file);
    if (ferror(file)) {
        perror("fputc:");   // ������ӡ�ļ�������Ϣ��
        //eg : fputc:: Bad file descriptor
    }
    fclose(file);
}

// clearerr
/**
 * #include <stdio.h>
 * �� ��:void clearerr(FILE *stream);
 * clearerr��������ʹ�ļ������־���ļ�������־��Ϊ0.
 * �����ڵ���һ�������������ʱ�����˴���ferror����ֵΪһ������ֵ���ڵ���clearerr��fp����ferror��fp����ֵ��Ϊ0��
 * ע�⣺
 *      clearerr�����������������streamָ����ļ������ļ�β��ʶ�ʹ����ʶ��
 *      ��û�з���ֵ��Ҳδ�����κδ��������ͨ��ʹ�������ļ����Ĵ���״̬�лָ���
 */
void test_clearerr()
{
    FILE * file;
    char c;

    file = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
    if(!file){
        printf("�ļ���ʧ��\n");
        return;
    }
    fputc('Y' ,file);   // ע�⣬�ַ��ǵ����� ''
    // ��ʱ���������־���粻�������һֱ���ڣ���������С����
    /*
    if (ferror(file)) {
        perror("fputc:");   // ������ӡ�ļ�������Ϣ��
        //eg : fputc:: Bad file descriptor
    }
    c = fgetc(file);
    printf("c = %c\n", c);

    if(ferror(file)) {
        perror("fgetc");
    }
    */
    /*
     * ��ʱ���
     * fputc:: Bad file descriptor
     * c = a
     * fgetc: Bad file descriptor
     */

    // �������Ǽ���clearerr����������
    if (ferror(file)) {
        perror("fputc:");   // ������ӡ�ļ�������Ϣ��
        clearerr(file);
        //eg : fputc:: Bad file descriptor
    }
    c = fgetc(file);
    printf("c = %c\n", c);

    if(ferror(file)) {
        perror("fgetc");
    }
    /*
     * ��ʱ���.
     * fputc:: Bad file descriptor
     * c = a
     */
    fclose(file);
}

// ���ȸ�ϰ
/*
 * char     1
 * int      4
 * long     32λϵͳ  long = int  4
 *          64λϵͳ              8
 * long long ����ʲôϵͳ         8
 */

// ftell
/*
 * #include <stdio.h>
 * long ftell(FILE *stream);
 * ʹ��fseek�������ٵ��ú���ftell()���ܷǳ����׵�ȷ���ļ��ĵ�ǰλ�á�
 * ��Ϊftell����long�ͣ�����long�͵�ȡֵ��Χ-231~231-1��-2147483648��2147483647�����ʶԴ���2.1G���ļ����в���ʱ����
 * ���� ftell ���ڵõ��ļ�λ��ָ�뵱ǰλ��������ļ��׵�ƫ���ֽ�����
 * �������ʽ��ȡ�ļ�ʱ�������ļ�λ��Ƶ����ǰ���ƶ�����������ȷ���ļ��ĵ�ǰλ�á�
 */
void test_ftell()
{
    FILE * file;
    long offset;
    char buff[32];

    file = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
    if(!file){
        printf("�ļ���ʧ��\n");
        return;
    }
    offset = ftell(file);
    printf("offset1 = %ld\n", offset);


    fgets(buff, 32, file);  // �˺���buff�������飬�������
    offset = ftell(file);
    printf("offset1 = %ld\n", offset);
    fclose(file);
}

// fseek
/*
 * #include <stdio.h>
 * int fseek(FILE *stream, long offset, int fromwhere)
 * ������
 *     1����һ������streamΪ�ļ�ָ��
 *     2��offset�� �ڶ�������offsetΪƫ������������ʾ����ƫ�ƣ�������ʾ����ƫ��
 *     3��fromwhere���ļ�ָ���λ�ã�
 *          1��SEEK_SET  ,�ļ���ʼλ�ã�����offset�������0
 *          2��SEEK_CUR  ,�ļ���ǰλ�ã�����offset�����ɸ�
 *          3��SEEK_END  ,�ļ���β������offset����Ϊ��
 *          ����SEEK_SET,SEEK_CUR��SEEK_END����Ϊ0��1��2.
 * ����ֵ���ɹ�������0��ʧ�ܷ��ط�0ֵ��������error��ֵ��������perror()�����������
 * fseek�������ļ�ָ�룬Ӧ��Ϊ�Ѿ��򿪵��ļ������û�д򿪵��ļ�����ô������ִ���
 * fseek����Ҳ����������⣬�൱�����ļ����ж�λ�������ڶ�ȡ�����Դ洢�ļ�ʱ����������OFFSETƫ������ȡ�ļ�����������ݡ�
 * fseek����һ�����ڶ������ļ���Ҳ���������ı��ļ���
 * �����ı��ļ�����ʱ�����ر�ע��ֻ��fseek(fp, 0, SEEK_SET) �� fseek(fp, ftell(fp), SEEK_SET)��ȷ���������Ԥ��
 */
// rewind
/*
 * #include <stio.h>
 * void rewind(FILE *stream);
 * ���ļ��ڲ���λ��ָ������ָ��һ������������/�ļ����Ŀ�ͷ
 * rewind�������õ�ͬ�� (void)fseek(stream, 0L, SEEK_SET);
 */
void test_fseek()
{
    FILE * file;
    char line[128];
    char c;

    file = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
    if (!file) {
        printf("�ļ���ʧ��\n");
        return;
    }
    // ��ȡ�ļ������10���ַ�
    fseek(file, -10, SEEK_END);
    while((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }

    // ��ȡ�ļ��ĵ�һ��
    fseek(file, 0, SEEK_SET);
    // rewind(file);    //�˺����൱��fseek(file, 0, SEEK_SET);
    fgets(line, sizeof (line), file);
    printf("line = %s\n", line);

    //��ȡ�ļ��ĵ�ǰλ�õ�ǰ5���ַ�
    fseek(file, -5, SEEK_CUR);
    for (int i=0; i<5; i++) {
        c= fgetc(file);
        printf("%c",c);
    }

fclose(file);
}


void studyTest1()
{
    test_fseek();
}
