#include <stdio.h>
#include <stdlib.h>

int main()
{

    int angle1,angle2;
    printf("please enter angle_1 : ");
    scanf("%d",&angle1);
     printf("please enter angle_2 : ");
    scanf("%d",&angle2);
   int angle3=180-(angle1+angle2);
    printf("angle_3 = %d",angle3);



    return 0;
}
