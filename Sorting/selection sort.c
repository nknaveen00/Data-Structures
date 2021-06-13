#include<stdio.h>

int main()
{
    int i,j,n,temp,arr[50],min;
    printf("Enter the array size\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
               {
                   min=j;
               }
        }
        if(arr[min]<arr[i])
        {
            temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
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
