#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*float C,F ;
    printf("enter temperature in celsius : ");
    scanf("%d",&C);

    F = (float)C*(9/5)+32;
printf("%f",F);*/
/*int degree,x=1 ;
  while (x==1)
    {

  printf("enter your degree : ");
  scanf("%d",&degree);
  if(degree >= 90 && degree <= 100)
  {
      printf("A+\n");
  }
  else if (degree>=85 && degree<90)
  {
      printf("A\n");
  }
  else if (degree>=80 && degree<85)
{
    printf("B+\n");
}
else if (degree>=75 && degree<80)
{
    printf("B\n");
}
else if (degree>=70 && degree<75)
{
    printf("C+\n");

}
else if (degree>=65 && degree<70)
{
    printf("C\n");

}
else if (degree>=60 && degree<65)
{
    printf("D+\n");

}
else if (degree>=50 && degree<60)
{
    printf("D\n");

}
else if (degree<50 && degree >=0)
{
    printf("F\n");

}
else {

    printf("Error\n");
}
    }*/
   /*char x ;
   printf("enter your letter : ");
   scanf("%c",&x);

switch (x)
{
    case 'a':
    printf("vowel");
    break;
    case 'A' :
    printf("vowel");
    break;
    case 'E':
    printf("vowel");
    break;
    case 'e':
    printf("vowel");
    break;
    case 'i':
    printf("vowel");
    break;
    case 'I':
    printf("vowel");
    break;
    case 'u':
    printf("vowel");
    break;
    case 'U':
    printf("vowel");
    break;
    case 'o':
    printf("vowel");
    break;
    case 'O':
    printf("vowel");
    break;
    default:
    printf("consonants");
    break;
}

int x ;
scanf("%d",&x);
do
{

       printf("hello world\n");
      x--;

}while(x>0);
*/
 int x;
 scanf("%d",&x) ;
 int i;



 for(i=1;i<=10;i++)
 {
    int res = x*i ;
    if(i==5)
    {
        continue;
    }
     printf("%d * %d = %d\n",x,i,res);
 }










    return 0;
}
