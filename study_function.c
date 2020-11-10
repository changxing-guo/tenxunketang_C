/* ########     function    ######## */

#include <stdio.h>
#include <study_function.h>

/*
 * 1��ΪʲôҪʹ�ú���
 *  �Ѿ���main������Ϊʲô��Ҫ�Զ��庯��
 *  1���������ظ��������ӡ�����߿���Ч��
 *  2������ά��
 */

/*
 * 2�������������������ʹ��
 *  ��������ƹ���
 *  1����ȷ�������Ĺ���
 *  2��ȷ������������
 *      ����Ҫ����˼��
 *  3��ȷ�������Ĳ���
 *      �Ƿ���Ҫ�����������ĸ���������������
 *  4��ȷ�������ķ���ֵ
 *      �Ƿ���Ҫ����ֵ������ֵ������,����ֵֻ����һ��
 *  5��ʵ�ֺ�����
 */

/*
 * �����Ķ���Ҫ����ǰ�棬ʹ�÷��ں���
 */

// gcc test.c -Wall ��ӡ���о���

// ��ǰn���������ĺ�
int sum(int n)
{
    int sum = 0;;
    for (int i=1; i<n+1; i++) {
        sum += i;
    }
    return sum;
}

/*
 * 3��������ֵ����
 */
// ���������ĺ�
int add(int a, int b)   // a = x, b = y, ֵ����
{
    return a + b;
}

/*
 * 5���ݹ麯��
 *  ���壺�ں����ڲ���ֱ�ӻ��߼�ӵĵ����Լ�
 *  Ҫ�㣺�ڶ���ݹ麯��ʱ��һ��Ҫȷ��һ����������
 *  ʹ�ó��ϣ�����һЩ�ر��ӵ����⣬����ֱ�ӽ��
 *      1���Թ�����
 *      2��
 * �ݹ麯����ȱ�㣬Ч�ʺܵͣ��ܲ��þͲ��ã����ؾ���
 *
 */
void recursive()
{
    printf("����recursive����\n");
    sleep(1);
    recursive();

    printf("�˳�recursive����\n");
}

// �ӵ��οռ䵽�ݹ麯��
int sum1(int n) {
    if (n == 1) {
        return 1;
    }
    return sum1(n-1) + n;
}

// ��ϰ�������Զ�������
void show_pyramid(char c, int n)
{
    if (n < 1) {
        printf("�������Ĳ����������0\n");
        return;
    }
    if (c == ' ' || c == '\n' || c == '\t') {
        printf("�Ƿ��Ľ������ַ�\n");
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

// �õݹ麯��ʵ��1+2+3+ .... + n;
int recursive_sum(int n) {
    if (n == 1) {
        return 1;
    }
    return sum(n-1) + n;
}

// �õݹ麯��ʵ�ֺ�ķ��
/*
 * A����n�����ӣ��ƶ���c��
 *  ��� n>1 ʱ
 *      1����n-1���̴�A���ƶ���B��
 *      2����n�̴�A���ƶ���c��
 *      3���� n-1�����Ӵ�B���ƶ���C��
 *  ���n=1ʱ��
 *      ������ֱ���ƶ���C��
 */
// �벻���׾;�֤��û����츳��ϴϴ˯��
// c �����ŵ�����
int hannuota(int n, char name_A[], char name_B[], char name_C[])
{
    if (n == 1) {
        printf("11111   %s �ƶ��� %s \n", name_A, name_C);
        return 0;
    }
    // �� A �ƶ� B, C����ת
    hannuota(n-1, name_A, name_C, name_B);
    printf("22222  %s �ƶ��� %s \n", name_A, name_C);
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
    z = add(x, y);  // ��������
    printf("add = %d\n", z);
    */
    //recursive();
    //printf("sum1 = %d\n", sum1(3));
    //show_pyramid('%', 20);
    //printf("recursive_sum = %d\n", recursive_sum(10));
    hannuota(2, "A��", "B��", "C��");
}
