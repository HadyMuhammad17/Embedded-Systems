#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[])
{
    int i,max=arr[0];
    for(i=1;i<6;i++)
    {
     if(arr[i]>max)
        {
            max=arr[i];
        }
    }
   return max ;

}
int reptition(int arr[],int num)
{
    int i , flag = num,counter=0;
    for(i=0;i<6;i++)
    {
        if(flag==arr[i])
           {
               counter=counter+1;
           }
    }

    return counter;

}
int getIndexMax(int arr[])
{
    int i,max=arr[0],maxIndex=0;
    for(i=1;i<100;i++)
    {
     if(arr[i]>max)
        {
            max=arr[i];
            maxIndex=i;
        }
    }
   return maxIndex ;

}
int maxRepetition(int arr[])
{
    int i;
    int arr2[100];
    for(i=0;i<=100;i++)
    {
           arr2[i]=reptition(arr,i);

    }

   return getIndexMax(arr2);



}


int main()
{
    int arr[6]={1,1,2,1,2,2};
    int result = maxRepetition(arr);
    printf("%d",result);

    return 0;
}
