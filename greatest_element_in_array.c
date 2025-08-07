#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[],int n)
{
    int i,max=arr[0];
    for(i=0;i<n;i++)
    {
     if(arr[i]>max)
        {
            max=arr[i];
        }
    }
   return max ;

}

int main()
{
    int arr[6]={0,1,2,3,4,5};
    int result = getMax(arr,6);
    printf("%d",result);

    return 0;
}
