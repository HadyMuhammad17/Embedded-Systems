#include <stdio.h>
#include <stdlib.h>

void power(int x,int y,int* result)
{
    int i ;
    for(i=0;i<y;i++)
    {
         *result =*result*x;

    }


}


int main()
{
    int num,p,res;
    printf("Enter your number \n");
    scanf("%d",&num);
    printf("Enter your power \n");
    scanf("%d",&p);
    power(num,p,&res);

    return 0;
}
