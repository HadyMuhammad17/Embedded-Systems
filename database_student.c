#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[20];
    int age ;
    int degree ;
    int section ;

};
int main()
{
  struct student s[5] = {{"Ahmed",22,90,2},{"Hady",23,70,1},{"Ayman",21,80,3},{"Youssef",23,50,4},{"Muhammad",22,75,5}};
  int exp ;
  printf("Student ");
  scanf("%d",&exp);
   printf("\n");
  switch(exp)
{
case 1: printf("Name : %s\n",s[0].name);
        printf("Age : %d\n",s[0].age);
        printf("Degree : %d\n",s[0].degree);
        printf("Section : %d\n",s[0].section);
             break;
case 2: printf("Name : %s\n",s[1].name);
        printf("Age : %d\n",s[1].age);
        printf("Degree : %d\n",s[1].degree);
        printf("Section : %d\n",s[1].section);
             break;
case 3:printf("Name : %s\n",s[2].name);
        printf("Age : %d\n",s[2].age);
        printf("Degree : %d\n",s[2].degree);
        printf("Section : %d\n",s[2].section);
              break;
case 4: printf("Name : %s\n",s[3].name);
        printf("Age : %d\n",s[3].age);
        printf("Degree : %d\n",s[3].degree);
        printf("Section : %d\n",s[3].section);
              break;
case 5: printf("Name : %s\n",s[4].name);
        printf("Age : %d\n",s[4].age);
        printf("Degree : %d\n",s[4].degree);
        printf("Section : %d\n",s[4].section);
              break;

default: printf("There is no student with this id .");
break;
}










    return 0;
}
