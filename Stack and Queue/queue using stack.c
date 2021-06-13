#include<stdio.h>
#include<stdlib.h>

void enqueue();
void dequeue();
void display();
int n;
void main()
{
    int choice;
    printf("\t\t\t***QUEUE OPERATIONS USING STACK***");
    printf("\nEnter the size of queue: ");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:enqueue();
                    break;
            case 2:dequeue();
                    break;
            case 3:display();
                    break;
            case 4:exit(1);

            default:printf("\nEnter valid choice!!!");
        }
    }
}

int stack1[50],stack2[50],i,temp,top1=-1,top2=-1,item;

void enqueue()
{
    if(top1==n-1)
        printf("\nQueue is full");
    else
    {
        printf("\Enter the element to insert: ");
        scanf("%d",&item);
        top1++;
        stack1[top1]=item;
    }
}

void dequeue()
{
    if(top1==-1)
        printf("\nQueue is empty");
    else
    {
        while(top1>=0)
        {
            top2++;
            stack2[top2]=stack1[top1];
            top1--;
        }
        printf("\nThe deleted element is: %d",stack2[top2]);
        top2--;
        while(top2>=0)
        {
            top1++;
            stack1[top1]=stack2[top2];
            top2--;
        }
    }
}


void display()
{
    if(top1==-1)
        printf("\nQueue is empty");
    else
    {
        printf("\nThe queue elements are: ");
        for(i=top1;i>=0;i--)
        {
            printf("%d\t",stack1[i]);
        }
    }

}
