#include <stdio.h>
#include <string.h>

int main(void)
{
    unsigned char name[] = "my name is �ŵ�˧��oyeah!";
    int len = strlen(name);
    printf("%d\n",len);
    char tmp[len+1];
    unsigned char *p1 = name;
    unsigned char *p2 = tmp + len;    // ����Ҫ����Ϊunsigned���ͣ���Ȼ�������⣨���縺��
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
