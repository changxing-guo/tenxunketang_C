#include <stdio.h>

#ifndef STUDY_1_H
#include "study_1.h"
#endif

int main_project()
{
    while (1) {
        char name[32];
        char passwd[16];

        printf("请输入用户名：");
        scanf("%s", name);
        printf(("请输入密码："));
        scanf("%s", passwd);

        if(strcmp(name, "admin") == 0 && strcmp(passwd, "123456") ==0) {
            break;
        } else {
            printf("用户名或者密码错误\n");
            system("pause");
            system("cls");
        }
    }
    a();
    //return 0;
}


int main()
{
    //main_project();
studyTest1();
}
