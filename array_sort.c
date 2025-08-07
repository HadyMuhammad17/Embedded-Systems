#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[100];
    int size, i, j, temp;


    printf("Enter size of array :: ");
    scanf("%d", &size);

    printf("\nEnter elements in array :: \n ");
    for(i=0; i<size; i++)
    {
        printf("\nEnter %d element in an array :: ",i+1);
        scanf("%d", &arr[i]);
    }

    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\nElements of array in sorted ascending order :: ");
    for(i=0; i<size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    printf("The maximum Number is %d in position %d \n",arr[size-1],size-1);
    printf("The minimum Number is %d in position 0 \n",arr[0]);

    return 0;
}
