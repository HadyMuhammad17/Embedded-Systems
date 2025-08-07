#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x;
    printf("Enter the number \n");
    scanf("%d",&x);
    int y,z;

    if(x%2==0)
    {
        y=0;
        z=1;
      printf("The number is odd  = %d \n",y);
      printf("The number is even = %d ",z);
    }
    else{

        y=1;
        z=0;
      printf("The number is odd = %d \n",y);
      printf("The number is even = %d ",z);
    }



    return 0;
}
