#include <stdio.h>
#include <stdlib.h>


struct complex
{
    float real;
    float imaginary;
};

int main()
{

    struct complex cnum1, cnum2, sum;
    printf("Enter real and imaginary part of first complex number:\n");
    scanf("%f%f", &cnum1.real, &cnum1.imaginary);
    printf("Enter real and imaginary part of second complex number:\n");
    scanf("%f%f", &cnum2.real, &cnum2.imaginary);

    sum.real = cnum1.real + cnum2.real;
    sum.imaginary = cnum1.imaginary + cnum2.imaginary;

    printf("SUM = %0.2f + %0.2f i ", sum.real, sum.imaginary);

    return 0;
}
