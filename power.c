#include <stdio.h>
#include <stdlib.h>

int power(int x,int y)
{
    int i ;
    int result =1;
    for(i=0;i<y;i++)
    {
         result =result*x;

    }

return result;

}


int main()
{
    int num,p;
    printf("Enter your number \n");
    scanf("%d",&num);
    printf("Enter your power \n");
    scanf("%d",&p);
    int res = power(num,p);
    printf("%d",res);
    return 0;
}
