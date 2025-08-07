#include <stdio.h>
#include <stdlib.h>

int checkprime(int num)
{

   int i,flag=0 ;
   for(i=2;i<num;i++)
   {

   if(num%i==0)
       {

           printf("No");
           flag=1;
           break;
       }
       else
       {
           flag=1;
       }

   }
     if(flag==0)
   {
     printf("Yes");
   }
}

int main()
{
    int x;
    scanf("%d",&x);
    checkprime(x);

    return 0;
}
