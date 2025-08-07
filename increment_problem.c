#include <stdio.h>
#include <stdlib.h>

void edit(int* x)
{
    (*x)++;
}



int main()
{
   int n ;
   printf("Enter the value of x\n");
   scanf("%d",&n);
   printf("Before calling edit x = %d \n",n);
   edit(&n);
   printf("After calling edit x = %d \n",n);




    return 0;
}
