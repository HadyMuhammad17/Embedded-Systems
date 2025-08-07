#include <stdio.h>
#include <stdlib.h>

int main()
{
     int arr[4]={10,20,30,40};
     int i;
     for(i=0;i<4;i++)
     {
         if(arr[i]==5)
         {
             printf("YES");
         }
         else
         {
             printf("NO");
         }
     }
    return 0;
}
