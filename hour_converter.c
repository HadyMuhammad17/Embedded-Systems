#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x ;
    printf("Enter your time : ");
    scanf("%d",&x);
    if(x<12)
    {
        printf("%d AM \n",x);
    }
    else if(x==12)
    {
        printf("%d PM",x);
    }
    else if(x==0)
    {
        printf("%d AM",x+12);
    }
    else if(x>23)
    {
        printf("Error");
    }
    else
    {
        x=x-12;
        printf("%d PM",x);

    }

    return 0;
}
