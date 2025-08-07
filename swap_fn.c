#include <stdio.h>
#include <stdlib.h>

void swap(int * num1, int * num2)
{
    int temp;

    temp = *num1;

    *num1= *num2;

    *num2= temp;

    printf("After swapping\n");
    printf("Value of num1 = %d \n", *num1);
    printf("Value of num2 = %d \n\n", *num2);
}
int main()
{

    int num1, num2;

    printf("Enter frist number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Before swapping\n");
    printf("Value of num1 = %d \n", num1);
    printf("Value of num2 = %d \n\n", num2);


    swap(&num1, &num2);




    return 0;
}
