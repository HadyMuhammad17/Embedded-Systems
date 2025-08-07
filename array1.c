#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int fun(char* PtrArr)
{
   int i,count=0 ;
   for(i=0;PtrArr[i]!='\0';i++)
   {
       count = count + 1 ;

   }
   return count;
}

int main()
{
     char arr[7]="joseph";
     printf("%s\n",arr);
     strlen();
    int res = fun(arr);

    return 0;
}
