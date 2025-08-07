#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[7]="joseph";
    str[0]='x';
    printf("%s\n",str);
    //str = 'abcd' ; //error

    char* ptr = "AMIT";
    printf("%s\n",ptr);
    //ptr[0]='x';//error
    //*(ptr+0) ='x';//error

    ptr="ahmed";
    printf("%s",ptr);




    return 0;
}
