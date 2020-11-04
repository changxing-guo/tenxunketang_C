#include <stdio.h>

#ifndef STUDY_1_H
#include "study_1.h"
#endif

int main_project()
{
    char name[32];      //输入的用户名
    char passwd[32];    //输入的密码
    FILE *userNamePasswdFile;         //保存用户账号密码的文件
    char line[128];
    char nameCompare[32];   //用于比较的用户名
    char passwdCompare[32]; //用于比较的密码
    char *getsUsersTxtLineResult;   //users.txt文件fgets读取一行的返回值

    while (1) {

        printf("请输入用户名：");
        scanf("%s", name);
        printf(("请输入密码："));
        scanf("%s", passwd);

        // 与特定的账号和密码进行比较
        /*if(strcmp(name, "admin") == 0 && strcmp(passwd, "123456") ==0) {
            break;
        } else {
            printf("用户名或者密码错误\n");
            system("pause");
            system("cls");
        }*/

        //打开文件
        userNamePasswdFile = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
        if(!userNamePasswdFile) {     // 等效于 file = NULL
            printf("文件打开失败\n");
            return 1;
        }

        // 从文件中读取账号，并进行判断
        while (1) {
            // 读一行
            getsUsersTxtLineResult = fgets(line, sizeof (line), userNamePasswdFile);       // line :   "admin   12345\n"
            sscanf(line, "%s %s", nameCompare, passwdCompare);
            if(!getsUsersTxtLineResult) {
                break;
            }
            if(!strcmp(name, nameCompare) && !strcmp(passwd, passwdCompare)) {
                break;
            }
        }
        if (getsUsersTxtLineResult) {   //用户名密码匹配成功
            break;
        } else {    //匹配失败
            printf("用户名或者密码错误\n");
            system("pause");
            system("cls");

            //fseek(userNamePasswdFile, 0, SEEK_SET); // 将文件内部的位置指针设置到文件头
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
