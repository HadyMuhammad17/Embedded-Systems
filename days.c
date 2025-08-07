#include <stdio.h>
#include <stdlib.h>

int main()
{
    int D;
printf("please enter numbers of days : ");
scanf("%d",&D);
int years = D/365;
int weeks=(D-(years*365))/7;
int days=D-((years*365)+(weeks*7));
printf("numbers of days equivalent to  %d Years %d Weeks %d Days ",years , weeks , days);
    return 0;
}
