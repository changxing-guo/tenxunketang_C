#include <stdio.h>

#ifndef STUDY_1_H
#include "study_1.h"
#endif

int main_project()
{
    char name[32];      //������û���
    char passwd[32];    //���������
    FILE *userNamePasswdFile;         //�����û��˺�������ļ�
    char line[128];
    char nameCompare[32];   //���ڱȽϵ��û���
    char passwdCompare[32]; //���ڱȽϵ�����
    char *getsUsersTxtLineResult;   //users.txt�ļ�fgets��ȡһ�еķ���ֵ

    while (1) {

        printf("�������û�����");
        scanf("%s", name);
        printf(("���������룺"));
        scanf("%s", passwd);

        // ���ض����˺ź�������бȽ�
        /*if(strcmp(name, "admin") == 0 && strcmp(passwd, "123456") ==0) {
            break;
        } else {
            printf("�û��������������\n");
            system("pause");
            system("cls");
        }*/

        //���ļ�
        userNamePasswdFile = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
        if(!userNamePasswdFile) {     // ��Ч�� file = NULL
            printf("�ļ���ʧ��\n");
            return 1;
        }

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

            //fseek(userNamePasswdFile, 0, SEEK_SET); // ���ļ��ڲ���λ��ָ�����õ��ļ�ͷ
        }

    }
    a();
    //return 0;
}


int main()
{
    main_project();
    //studyTest1();
}
