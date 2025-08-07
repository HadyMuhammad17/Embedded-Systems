#include <stdio.h>
#include <stdlib.h>
int fun(int x , int y)
{
    int i;
    int sum = 0 ;
    for(i=x;i<=y;i++)
    {
       sum = sum + i ;
    }
    return sum ;
}
int main()
{
    int n , m;
    scanf("%d %d",&n,&m);
    int res =  fun(n,m);
printf("value = %d",res);
    return 0;
}
