#include "study_1.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

void a()
{
    system("cls");
    printf("---交换机管理系统---\n");
    printf("1、登陆--\n");
    printf("2、创建账号\n");
    printf("3、--\n");
    printf("4、退出--\n");
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
    name = getc(stdin); //输入一个字符，stdin表示“标准输入设备”，默认是键盘
    putc(name, stdout);  //stdout标准输出设备，可以输出到其他文件
}


//查看程序的结束状态（编译结束后输入）
// echo %errorlevel%

//编译.默认为a.exe,如果重命名的话，如下所示
//gcc main.c -o testmain

//练习
//输入一个圆的半径，输出周长和面积
void test1()
{
    float r, s, c;
    printf("please input the radius of the circle : ");
    scanf("%f", &r);
    s = 3.14 * r * r;
    c = 2 * 3.14 * r;
    printf(" the area is %f , the perimeter is %f .", s, c);
}

//输入一个小写字母，输出对应的大写字母
void test2()
{
    char num1, num2;
    printf("请输入一个小写字母 : ");
    scanf("%c", &num1);
    //num2 = num1 - 32;
    num2 = num1 - ('a' - 'A');
    printf("%c 的大写字母是 %c.", num1, num2);

}


/**
  * 字符串的一些常识
  * scanf()
  * gets()
  * fgets()
  * strlen()
  * strcpy()
  */
void test3()
{
    //scanf,缺点，不能读取空格，制表符等。容易越界
    //gets, 读取一行，遇到回车符结束，不保存回车符，容易越界
    //fgets，读取指定长度，读取指定长度后结束，
    /**
     * string.h
     * strlen() 字符串长度
     * strcpy(char *s1, char *s2) 将s2 拷贝给s1,结束符也拷贝过去，可能导致字符串越界
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
    }   //输出 “gcx 567890”
    printf("\n");


    /**
     * strncpy(char *a, char *b, int n); 字符串拷贝
     */
    char s5[32] = "1234567890"; //{1,2,3,4,5,6,7,8,9,0,\0}
    printf("the length of s5 is %d\n", strlen(s5));     //10
    printf("s5 is %s\n", s5);
    char s6[32] = "gcx";
    strncpy(s5, s6, 3);
    printf("s5-3 is %s\n", s5); // 输出gcx4567890
    strncpy(s5, s6, 5);         //此时拷贝5位，会默认拷贝gcx00,没有的默认设为0，
    printf("s5-5 is %s\n", s5); // 此时输出为gcx,因为0为结束符，其实字符串保存的是{g,c,x,\0,\0,6,7,8,9,0}


    /**
     *  strcat(char *s1, char *s2) 字符串拼接 s1 = s1 + s2;
     *  s1 = {1, 2, 3, 4, \0};
     *  s2 =              {a, b, c, \0};
     *  使用strcat(s1, s2)后
     *  s1 = {1, 2, 3, 4, a, b, c, \0}
     *  s2 =             {a, b, c, \0};
     */
    //eg
    char s7[32] = "甘肃省";
    char s8[32] = "平凉市";
    strcat(s7, s8);
    printf("s7 is %s\n", s7);   //甘肃省平凉市
    printf("s8 is %s\n", s8);   //平凉市
}

void  testBool() {
    //c89用int表示bool类型，建议纯c项目还是用int类型表示真假，这样兼容性比较好。 0=假， ！0= 真
    if(-1) {
        printf("-1 is true\n");
    }
    if(0){
        printf("0 is false\n");
    }
    if(1){
        printf("1 is true\n");
    }
    //c99标准
    bool ret;
    ret = 3>5;
    printf("ret = %d\n", ret);
    ret = 3<5;
    printf("ret = %d\n", ret);

    if (true) {
        printf("true is 真\n");
    }

    if(false) {
        printf("false is 假\n");
    }
}

/**
 * 自增自减,只能对变量做这个，常量不可以
 * x = i++; x = i; i = i+1;
 * x = ++i; i = i+1, x = i;
 *
 */

void testComma()
{
    // 逗号表达式
    int ret1,ret2;
    ret1 = (2+2, 3+3, 4+4); //8
    ret2 = 2+2, 3+3, 4+4;   //4
    printf("ret1 = %d, ret2 = %d\n", ret1, ret2);
}

//三目运算符
void testSanMu()
{
    int age,day;
    printf("请输入你的年龄:");
    scanf("%d", &age);
    day = age>24 ? 0:1;
    printf("day is %d\n", day);
}

//类型转化
/**
 * 1，隐式类型转化
 *      算数类型转换 float ret1; ret1 = 10 *3.14; => 10.0 *.3.14;
 *      赋值转换 int x; x=3.14; => x=3;
 *      输出转换 printf("%c\n", 255+50); => 305 -> 49 ('1')
 *          100110001 -> 00110001 -> 43 -> '1'
 * 2、强制类型转换
 *      printf("%d\n", (char)256+100);
 */

//运算符优先级
// ! > 算数运算符 > 关系运算符 > && > || > 赋值运算符
// 最低优先级： 逗号运算符

// while test.两种方式根据自己的习惯决定，都可以的
void test_while1()
{
    int i = 1;
    while(1) {
        printf("1这儿有%d只羊\n", i);
        if (10 == i) break;
        i++;
        //sleep(1); //这个是linux接口，单位秒
        Sleep(1000); // 这个是windows接口。单位毫秒。头文件windows.h
    }
    printf("我睡着啦\n");
}

void test_while2()
{
    int i = 1;
    while(i <= 10) {
        printf("2这儿有%d只羊\n", i);
        //if (10 == i) break;
        i++;
        //sleep(1); //这个是linux接口，单位秒
        Sleep(1000); // 这个是windows接口。单位毫秒。头文件windows.h
    }
    printf("我睡着啦\n");
}

//循环练习
//1、金字塔
void pyramid()
{
    int n;
    printf("请输入金字塔的层数：");
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

//打印乘法口诀表
void multiplicationTable()
{
    for(int i=1; i<=9; i++) {
        for(int j=1; j<i+1;j++) {
            printf("%dX%d=%d\t", i, j, i*j);
        }
        printf("\n");

    }
}

//翻转字符串
void flipStr()
{
    char buff[64];
    printf("请输入一个字符串：");
    gets(buff);
    int len = strlen(buff);
    printf("the str strlen is %d\n", len);
    for(int i=0; i<len/2; i++) {
        char tmp = buff[i];
        buff[i] = buff[len-i-1];
        buff[len-i-1] = tmp;
    }
    printf("输出：%s", buff);

}

//打印斐波那契数列、
void printFibonacciSequence()
{
    int n;
    printf("请输入斐波那契数列的长度：");
    scanf("%d", &n);
    if(n<1) {
        printf("最小长度为1\n");
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
 * 参数1 ： fname 文件名，绝对路径和相对路径
 * 参数2 ： mode 打开方式
 * 返回值： FILE * 文件指针。打开失败返回NULL(就是0)
 *  mode
 *      "r"     以“读”的方式打开一个文本文件，只能“读”
 *      "r+"    与“r”的区别在于，增加了“写”
 *      "rb"    以“读”的方式打开一个二进制文件
 *      "rb+"   与“rb”的区别在于，增加了“写”
 *
 *      "w"     以“写”的方式创建一个文本文件，如果这个文件已存在，就会覆盖原来的文件
 *      "w+"    与“w”的区别在于，增加了“读”
 *      "wb"    以“读”的方式创建一个二进制文件
 *      "wb+"   与“w+”的区别在于，增加了“读”
 *
 *      "a"     以“尾部追加”的方式打开一个文本文件（只能写）
 *      "a+"    与“a”的区别在于，增加了“读”
 *      "ab"    以“尾部追加”的方式打开一个二进制文件（只能写）
 *      "ab+"   与“ab”的区别在于，增加了“读”
 */

// 读取users.txt文件并打印出来
void test_fgetc()
{
    FILE *file ;
    char buff;

    file = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
    /*while(1) {
        buff = fgetc(file);
        if (buff == EOF) break; // EOF = -1 ，文件结尾有这个标志
        printf("%c", buff);
    }*/

    while((buff = fgetc(file)) != EOF) {    //此处 要注意运算符的优先级
        printf("%c", buff);
    }

    fclose(file);
}

/**
 * fgetc, fputc
 * 需求，把这个文件内容复制到study_copyTest.c
 */
void testCopy()
{
    FILE *sourceFile;
    FILE *copyFile;
    char buff;

    sourceFile = fopen("E:\\qtcode\\tenxunketang_C\\study_1.c", "r");
    copyFile = fopen("E:\\qtcode\\tenxunketang_C\\study_copyTest.c", "w");
    if (!sourceFile || !copyFile) {
        printf("sourceFile文件或者copyFile文件打开失败\n");
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
 * 参数：最多读num-1个字符，或者遇到文件结束符EOF为止(即文件读完了)
 * 返回值：读取失败时，返回NULL
 *         读取成功时，返回str
 */
//需求：打印该文件到屏幕
void test_fgets()
{
    FILE *file;
    char *buff;
    file = fopen("E:\\qtcode\\tenxunketang_C\\study_1.c", "r");
    if(!file) {
        printf("文件打开失败\n");
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
// 需求，将study_1.c写到filewritetest.txt
void test_fputs()
{
    FILE *file_out;
    FILE *file_in;
    char buff[128];
    file_out = fopen("E:\\qtcode\\tenxunketang_C\\study_1.c", "r");
    file_in = fopen("E:\\qtcode\\tenxunketang_C\\filewritetest.txt", "w");
    if (!file_in || !file_out) {
        printf("文件打开失败\n");
        return;
    }
    while (fgets(buff, sizeof (buff), file_out)) {
        fputs(buff, file_in);
    }
    fclose(file_out);
    fclose(file_in);
    printf("文件拷贝完成，加油啊，少年\n");

}

/**
 * #include <stdio.h>
 * int fprintf( FILE *stream, const char *format, ... );
 * 将文件按照格式存储
 */
// 需求，将读取到的姓名和年龄按照格式存储
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
        printf("文件打开失败\n");
    }

    while(1) {
        printf("请输入你的姓名：");
        // 假设输入gcx
        scanf("%s", name);  //此时缓冲区为 g c x \n , scanf 按下回车读取后，缓冲区还有"\n"
        printf("请输入你的年龄：");
        // 假设输入 22
        scanf("%d", &age);  //此时缓冲区为 \n 22 \n, 按下回车键，%d 不读取\n（跳过），所以读到22，缓冲区还有"\n"
        //此时应清除缓冲区，否则下一个scanf读取字符或者字符串的时候会读取到你的"\n"
        //清除缓冲区
        //fflush(stdin); //最简单的方式，如果要兼容性好的话，用下面的试试
        while ((c=getchar()) != '\n') {} //循环清空缓冲区，当读取到\n的时候跳出循环

        fprintf(file, "name:%s\t\tage:%d\n", name, age);
        printf("还要继续输入吗？(Y/N)\n");
        scanf("%c", &c);
        if (c == 'Y' || c == 'y') {
            continue;
        } else {
            break;
        }
    }
    fclose(file);
}

//将users.txt中读取到的文本按照格式存储
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
        printf("文件打开失败\n");
        return;
    } else {
        printf("文件打开成功\n");
    }
    printf("文件开始写入\n");
    while(1) {
        ret_line = fgets(line, sizeof (line), file_user);
        if (!ret_line) {
            break;
        }
        sscanf(line, "%s %s", name, passwd);
        fprintf(file_test, "name:%s\t\tage:%s\n", name, passwd);
    }
    printf("文件写入结束\n");
    fclose(file_user);
    fclose(file_test);

}

// scanf 格式化读取数据
/**
 * 例子:输入：name=gcx age=22
 *      输出name = gcx, age = 22
 */
void test_scanf() {
    char name[32];
    int age;
    //scanf("name=%s age=%d", name, &age); //下面的是一样的效果
    fscanf(stdin, "name=%s age=%d", name, &age);
    printf("name = %s, age = %d \n", name, age);
}

/*
 * 从test_fscanf.txt中格式化读取文本
 * 目前测试看，文件格式必须统一，不然的话会导致程序错乱
 */
void test_fscanf()
{
    char name[32];
    int age;
    FILE * file;
    int ret;

    file = fopen("E:\\qtcode\\tenxunketang_C\\test_fscanf.txt", "r");
    if (!file) {
        printf("文件打开失败\n");
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
    int fwrite( const void *buffer, // 要写入数据的起始地址，也就是变量的地址
                size_t size,        // 每块数据的大小
                size_t count,       // 写入的数据快的个数
                FILE *stream );     // 写入的文件指针
    // 需求，把读到的文件以二进制保存到test_fwrite.txt
*/
void test_fwrite()
{
    char name[32];
    int age;
    FILE * file;

    printf("请输入你的姓名：");
    scanf("%s", name);
    printf("情输入你的年龄：");
    scanf("%d", &age);
    file = fopen("E:\\qtcode\\tenxunketang_C\\test_fwrite.txt", "wb"); // 以二进制写的方式打开
    if (!file) {
        printf("文件写入失败\n");
        return;
    }
    fwrite(name, sizeof(char), sizeof (name), file);
    fwrite(&age, sizeof (int), 1, file);
    printf("文件写入完成，即将保存文件\n");
    fclose(file);
}

/*
 * windows平台下w和wb的小结
 *
 *  二进制文件写入补充，fwrite
    在windows平台下，当使用w方式打开文件时：
    如果使用fwrite写入数据时，会把'\n'写入为'\r''\n'
    即把'\n'保存为13 10
    因为在windows平台下   ，文本文件的回车符'\n',会保存为'\r\n'
    ('\n'的ASCII 码为10，'\r'的ASCII 码为13)

    当用wb方式打开文件时，
    如果使用fwrite方式写入数据是，遇到'\n'仍只写入为'\n'
*/

// fread 以二进制的形式读取数据
void test_fread()
{
    FILE * file;
    char name[32];
    int age;

    file = fopen("E:\\qtcode\\tenxunketang_C\\test_fwrite.txt", "rb");
    if (!file) {
        printf("文件打开失败\n");
        return;
    }
    fread(name, sizeof (char), sizeof (name), file);
    fread(&age, sizeof (int), 1, file);
    printf("name = %s, age = %d\n", name, age);
    fclose(file);
}

// putw 以二进制形式存储一个整数
/*
 * 对磁盘文件写一个字（整数）
 * int putw(int w, FILE *fp);将整型w写进fp指向的文件
 * 返回输出的整数，如果出错，则返回EOF
 */
void test_putw()
{
    FILE * file;
    int a[] = {1,2,-1,4,5};
    int a_len;

    file = fopen("E:\\qtcode\\tenxunketang_C\\test_putw.txt", "wb");
    if (!file) {
        printf("文件打开失败\n");
        return;
    }
    //查看数组的长度。注意使用 sizeof (a) / sizeof (int);不能使用strlen，这个是看字符串的
    a_len = sizeof (a) / sizeof (int);
    printf("a_len = %d\n", a_len);
    for (int i = 0; i < a_len; i++) {
        putw(a[i], file);
    }
    fclose(file);
}

// getw二进制形式读取整数
/*
 * int getw(FILE *fp)
 * 从fp所指向文件读取下一个字（整数）
 * 返回输入的整数。如果文件结束或者出错返回-1。
 */
void test_getw()
{
    printf("the function is test_getw\n");
    FILE * file;
    int i;
    file = fopen("E:\\qtcode\\tenxunketang_C\\test_putw.txt", "rb");

    if(!file) {
        printf("文件打开失败\n");
        return;
    }

    // 这种读取方式有个问题，应为EOF 的值就是-1，所以我们读取上个函数保存的数组是，只能读取两个
    // 假设读取int a[] = {1,2,-1,4,5}; 此时只能读到 1,2
    /*
    while((i = getw(file)) != EOF) {
        printf("%d ", i);
    }
    */

    // 我们接着用下面的文件状态判断函数继续测试
    // 假设读取int a[] = {1,2,-1,4,5}; 此时却读到1,2,-1,4,5,-1
    // 因为文件结束符就是-1，所以也会读出来，此种方式还是有瑕疵
    /*
    while (!feof(file)) {   // 当文件读取未结束的时候
        i = getw(file);
        printf("%d ", i);
    }
    */

    // ？ 那我们怎么能只读取到有用的数据
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
 * 检测流上的文件结束符。如果文件结束，则返回非0值，否则返回0，文件结束符只能被clearerr()清除。
 * int feof(FILE *stream);
 * feof判断文件结束是通过读取函数fread/fscanf等返回错误来识别的，故而判断文件是否结束应该是在读取函数之后进行判断
 * 比如，在while循环读取一个文件时，如果是在读取函数之前进行判断，则如果文件最后一行是空白行，可能会造成内存错误。
 */

// ferror
/**
 * int ferror(FILE *stream);
 * ferror，函数名，在调用各种输入输出函数（如 putc.getc.fread.fwrite等）时，
 * 如果出现错误，除了函数返回值有所反映外，还可以用ferror函数检查。
 * 它的一般调用形式为 ferror(fp)；如果ferror返回值为0（假），表示未出错。
 * 如果返回一个非零值，表示出错。
 * 应该注意，对同一个文件 每一次调用输入输出函数，均产生一个新的ferror函 数值，
 * 因此，应当在调用一个输入输出函数后立即检 查ferror函数的值，否则信息会丢失。
 * 在执行fopen函数时，ferror函数的初始值自动置为0。
 */
void test_ferror() {
    FILE * file;
    file = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
    if(!file){
        printf("文件打开失败\n");
        return;
    }
    fputc("Y" ,file);
    if (ferror(file)) {
        perror("fputc:");   // 用来打印文件错误信息。
        //eg : fputc:: Bad file descriptor
    }
    fclose(file);
}

// clearerr
/**
 * #include <stdio.h>
 * 用 法:void clearerr(FILE *stream);
 * clearerr的作用是使文件错误标志和文件结束标志置为0.
 * 假设在调用一个输入输出函数时出现了错误，ferror函数值为一个非零值。在调用clearerr（fp）后，ferror（fp）的值变为0。
 * 注意：
 *      clearerr函数的作用是清除由stream指向的文件流的文件尾标识和错误标识。
 *      它没有返回值，也未定义任何错误。你可以通过使用它从文件流的错误状态中恢复。
 */
void test_clearerr()
{
    FILE * file;
    char c;

    file = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
    if(!file){
        printf("文件打开失败\n");
        return;
    }
    fputc('Y' ,file);   // 注意，字符是单引号 ''
    // 此时发生错误标志，如不清除，会一直存在，我们做个小测试
    /*
    if (ferror(file)) {
        perror("fputc:");   // 用来打印文件错误信息。
        //eg : fputc:: Bad file descriptor
    }
    c = fgetc(file);
    printf("c = %c\n", c);

    if(ferror(file)) {
        perror("fgetc");
    }
    */
    /*
     * 此时输出
     * fputc:: Bad file descriptor
     * c = a
     * fgetc: Bad file descriptor
     */

    // 下面我们加入clearerr。继续测试
    if (ferror(file)) {
        perror("fputc:");   // 用来打印文件错误信息。
        clearerr(file);
        //eg : fputc:: Bad file descriptor
    }
    c = fgetc(file);
    printf("c = %c\n", c);

    if(ferror(file)) {
        perror("fgetc");
    }
    /*
     * 此时输出.
     * fputc:: Bad file descriptor
     * c = a
     */
    fclose(file);
}

// 长度复习
/*
 * char     1
 * int      4
 * long     32位系统  long = int  4
 *          64位系统              8
 * long long 不管什么系统         8
 */

// ftell
/*
 * #include <stdio.h>
 * long ftell(FILE *stream);
 * 使用fseek函数后再调用函数ftell()就能非常容易地确定文件的当前位置。
 * 因为ftell返回long型，根据long型的取值范围-231~231-1（-2147483648～2147483647），故对大于2.1G的文件进行操作时出错。
 * 函数 ftell 用于得到文件位置指针当前位置相对于文件首的偏移字节数。
 * 在随机方式存取文件时，由于文件位置频繁的前后移动，程序不容易确定文件的当前位置。
 */
void test_ftell()
{
    FILE * file;
    long offset;
    char buff[32];

    file = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
    if(!file){
        printf("文件打开失败\n");
        return;
    }
    offset = ftell(file);
    printf("offset1 = %ld\n", offset);


    fgets(buff, 32, file);  // 此函数buff必须数组，否则出错
    offset = ftell(file);
    printf("offset1 = %ld\n", offset);
    fclose(file);
}

// fseek
/*
 * #include <stdio.h>
 * int fseek(FILE *stream, long offset, int fromwhere)
 * 参数：
 *     1、第一个参数stream为文件指针
 *     2、offset： 第二个参数offset为偏移量，正数表示正向偏移，负数表示负向偏移
 *     3、fromwhere：文件指针的位置，
 *          1）SEEK_SET  ,文件开始位置，参数offset必须大于0
 *          2）SEEK_CUR  ,文件当前位置，参数offset可正可负
 *          3）SEEK_END  ,文件结尾，参数offset必须为负
 *          其中SEEK_SET,SEEK_CUR和SEEK_END依次为0，1和2.
 * 返回值：成功，返回0，失败返回非0值，并设置error的值，可以用perror()函数输出错误。
 * fseek函数的文件指针，应该为已经打开的文件。如果没有打开的文件，那么将会出现错误。
 * fseek函数也可以这样理解，相当于在文件当中定位。这样在读取规律性存储文件时可以利用其OFFSET偏移量读取文件上任意的内容。
 * fseek函数一般用于二进制文件，也可以用于文本文件。
 * 用于文本文件操作时，需特别注意只有fseek(fp, 0, SEEK_SET) 和 fseek(fp, ftell(fp), SEEK_SET)能确保结果符合预期
 */
// rewind
/*
 * #include <stio.h>
 * void rewind(FILE *stream);
 * 将文件内部的位置指针重新指向一个流（数据流/文件）的开头
 * rewind函数作用等同于 (void)fseek(stream, 0L, SEEK_SET);
 */
void test_fseek()
{
    FILE * file;
    char line[128];
    char c;

    file = fopen("E:\\qtcode\\tenxunketang_C\\users.txt", "r");
    if (!file) {
        printf("文件打开失败\n");
        return;
    }
    // 读取文件的最后10个字符
    fseek(file, -10, SEEK_END);
    while((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }

    // 读取文件的第一行
    fseek(file, 0, SEEK_SET);
    // rewind(file);    //此函数相当于fseek(file, 0, SEEK_SET);
    fgets(line, sizeof (line), file);
    printf("line = %s\n", line);

    //读取文件的当前位置的前5个字符
    fseek(file, -5, SEEK_CUR);
    for (int i=0; i<5; i++) {
        c= fgetc(file);
        printf("%c",c);
    }

    fclose(file);
}

// 练习。统计下这个代码本身有多少个字符，有多少行
void testFileLine()
{
    FILE * file;
    // 要记得初始化变量
    int count_char = 0;
    int count_line = 0;
    char c;

    file = fopen("E:\\qtcode\\tenxunketang_C\\study_1.c", "r");
    if (!file) {
        printf("the file is open fail\n");
        return;
    }
    while((c = fgetc(file)) != EOF) {
        count_char++;
        if (c == '\n') {    //文件每行末尾有回车符
            count_line++;
        }
    }
    printf("字符个数是： %d , 行数是: %d", count_char, count_line);
    fclose(file);
}

// 练习：从文本中testFoundTel.txt中查找电话号码
void testFoundTel()
{
    FILE *file;
    char name[32];
    char tel[32];
    char addr[32];

    int found = 0;
    char name_tmp[32];

    file = fopen("E:\\qtcode\\tenxunketang_C\\testFoundTel.txt", "r");
    if (!file) {
        printf("电话薄打开失败\n");
        return;
    }

    printf("请输入要查找的姓名：");
    scanf("%s", name);

    while (!feof(file)) {
        //特别注意，一定要注意换行符，否则一直读第一行
        fscanf(file, "name:%s tel:%s addr:%s\n", name_tmp, tel, addr);
        //printf("test %s %s %s \n", name_tmp, tel, addr);
        if (!strcmp(name, name_tmp)) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("%s的电话号码是 ： %s， 地址是 ： %s", name, tel, addr);
    } else {
        printf("未查找到\n");
    }
    fclose(file);
}

// switch 注意事项
/*
 * 1、只能用于int、char，long， long long类型
 * 2、case内部不能定义变量，要定义的话必须加（），这个是作用域的问题
 */
void test_switch()
{
    int n;
    scanf("%d", &n);
    switch (n) {    //只能用于int,short,char，long， long long类型
    case 1:
    {
        int y = 3; // 定义变量时要加括号
        break;
    }
    case 2:
        break;
    default:
        break;
    }
}

// 输出每个月有多少天
void test_switch2() {
    int month, days;
    char c;
    while (1) {
        printf("请输入要查询的月份:");
        scanf("%d", &month);
        fflush(stdin);
        if (month < 1 || month > 12) {
            printf("输入的月份有误\n");
            continue;
        }
        switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            days = 28;
            break;
        default:
            break;
        }
        printf("%d 月有 %d 天\n", month, days);
        printf("请输入q离开\n");
        c = getchar();
        if (c == 'q' || c == 'Q') {
            return;
        }
        system("cls");

    }
}



void studyTest1()
{
    test_switch2();
}
