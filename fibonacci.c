#include <stdio.h>
#include <stdlib.h>

void fibonacci(int x)
{
    static int a=0,b=1,c;
   if(x>0)
   {
       c = a + b ;
       a = b;
       b = c;
       printf("%d, ",c);
       fibonacci(x-1);
   }

}
int main()
{
    int n ;
    printf("enter the number of terms :\n");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Error \n");
    }
    else if(n==1)
    {
        printf("Fibonacci Series : 0 \n");
    }
    else if(n==2)
    {
        printf("Fibonacci Series : 0,1, \n");
    }

    else
    {
        printf("Fibonacci Series : 0, 1, ");
        fibonacci(n-2);

    }
    return 0;
}
