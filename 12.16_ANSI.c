#include <stdio.h>
#include <string.h>

int main(void)
{
    unsigned char name[] = "my name is 张德帅，oyeah!";
    int len = strlen(name);
    printf("%d\n",len);
    char tmp[len+1];
    unsigned char *p1 = name;
    unsigned char *p2 = tmp + len;    // 必须要设置为unsigned类型，不然会有问题（比如负数
    *p2-- = 0;
    while(*p1) {
        if (*p1 < 0xA0) {
            *p2-- = *p1++;
        } else {
            *(p2-1) = *p1++;
            *p2 = *p1++;
            p2-=2;
        }
       
    }
    printf("%s\n", tmp);
    return 0;
}
