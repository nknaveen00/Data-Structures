#include<stdio.h>

void main()
{
    int n,arr[30],i,arr2[30],j,k=0,count;
    printf("\t\t\t\t***\tStock span Problem\t***");
    printf("\nEnter the size of array: ");
    scanf("%d",&n);
    printf("\nEnter the stock price\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    i=j=0;
    for(i=0;i<n;i++)
    {
        count=0;
        for(j=i;j>=0;j--)
        {
            if(arr[i]>=arr[j])
                count++;
            else
                break;
        }
        arr2[i]=count;
    }
    printf("\nThe output is: ");
    for(i=0;i<n;i++)
        printf("%d\t",arr2[i]);
}
