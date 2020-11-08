#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef STUDY_1_H
#include "study_1.h"
#endif

#ifndef STUDY_FUNCTION_H
#include "study_function.h"
#endif

FILE *userNamePasswdFile;       //�����û��˺�������ļ�

// ��ʼ������
void init()
{
    //���ļ�
    userNamePasswdFile = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
    if(!userNamePasswdFile) {     // ��Ч�� file = NULL
        printf("�ļ���ʧ��\n");
        exit(1);
    }
}

// �û����˺�������֤
void login()
{
    char name[32];      //������û���
    char passwd[32];    //���������

    char line[128];
    char nameCompare[32];   //���ڱȽϵ��û���
    char passwdCompare[32]; //���ڱȽϵ�����
    char *getsUsersTxtLineResult;   //users.txt�ļ�fgets��ȡһ�еķ���ֵ
    while (1) {

        printf("�������û�����");
        scanf("%s", name);
        printf(("���������룺"));
        scanf("%s", passwd);
        // ��ջ�����
        fflush(stdin);

        // ���ض����˺ź�������бȽ�
        /*if(strcmp(name, "admin") == 0 && strcmp(passwd, "123456") ==0) {
            break;
        } else {
            printf("�û��������������\n");
            system("pause");
            system("cls");
        }*/

        // ���ļ��ж�ȡ�˺ţ��������ж�
        while (1) {
            // ��һ��
            getsUsersTxtLineResult = fgets(line, sizeof (line), userNamePasswdFile);       // line :   "admin   12345\n"
            sscanf(line, "%s %s", nameCompare, passwdCompare);
            if(!getsUsersTxtLineResult) {
                break;
            }
            if(!strcmp(name, nameCompare) && !strcmp(passwd, passwdCompare)) {
                break;
            }
        }
        if (getsUsersTxtLineResult) {   //�û�������ƥ��ɹ�
            break;
        } else {    //ƥ��ʧ��
            printf("�û��������������\n");
            system("pause");
            system("cls");
            fseek(userNamePasswdFile, 0, SEEK_SET); // ���ļ��ڲ���λ��ָ�����õ��ļ�ͷ
        }
    }

}

//���˵�ҳ��
void show_menu()
{
    // ���˵�����
    system("cls");
    printf("---����������ϵͳ---\n");
    printf("1�������˺�\n");
    printf("2��ip����\n");
    printf("3���˳�--\n");
    printf("��ѡ��");
}

// �˺Ź���
void create_user()
{
    system("cls");
    printf("1�������˺�\n");
    printf("��������������˵�\n");
    getchar();
}

//ip ����
void ip_manager()
{
    system("cls");
    printf("2��ip����\n");
    printf("��������������˵�\n");
    getchar();
}

// �˳��˺�
void logout()
{
    fclose(userNamePasswdFile);
    system("cls");
    exit(0);
}

void input_error()
{
    system("cls");
    printf("��������Ч�Ĳ˵�ѡ��\n");
    printf("��������������˵�\n");
    getchar();
}

void main_project()
{
    int menuChange = 0; //�˵�ѡ��

    init();
    login();

    // �˺�������ȷ��������˵�
    while (1) {
        show_menu();
        scanf("%d", &menuChange);
        fflush(stdin);
        // �ӹ���
        switch (menuChange) {
        case 1:
            create_user();
            break;
        case 2:
            ip_manager();
            break;
        case 3:
            logout();
            break;
        default:
            input_error();
            break;
        }

    }
}


int main()
{
    //main_project();
    //studyTest1();
    mainStudyFunction();
    return 0;
}
