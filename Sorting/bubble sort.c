#include<stdio.h>

int main()
{
    int i,arr[50],n,temp,j;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        printf("\nEach iteration\n");
        for(int k=0;k<n;k++)
            printf("%d\t",arr[k]);
    }

    printf("\nThe sorted array is\n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);


    return 0;
}
