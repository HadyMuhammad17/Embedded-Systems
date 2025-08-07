#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pass =1234 ;
    int password,i ;



        for(i=3;i>0;i--)
        {
            printf("Enter your password :");

            scanf("%d",&password);

            if(password==pass)
            {

                printf("Welcome\n");

                break ;

            }
    else{
        if(i==1)
        {
         printf("Blocked\n");
        }
        else
        {
        printf("Try again\n");
        }
            }
        }







    return 0;
}
