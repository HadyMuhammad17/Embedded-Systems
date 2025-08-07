#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    printf("enter x : ");
    scanf("%d",&x);
     printf("enter y : ");
    scanf("%d",&y);
    char ch ='%';
    printf("x %c y = %d",ch,x%y);

    return 0;
}
