#include <stdio.h>

static void printf_static()
{
    printf("printf_static is called\n");
}

void test_13()
{
    printf("this is study_2.c.test\n");
    printf_static();
}
