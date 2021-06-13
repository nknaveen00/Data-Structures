#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();

int n;

void main()
{
    int choice;
    printf("\t\t\t*****STACK using QUEUE*****");
    printf("\nEnter the size of the queue: ");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(1);

            default: printf("\nEnter valid option!!!");
        }
    }
}

int queue1[20],front=-1,rear=-1,arr[20],i,item,temp;

void push()
{
    if(rear==n-1)
        printf("\nThe stack is Full");
    else
    {
        printf("\nEnter the element to insert: ");
        scanf("%d",&item);
        rear++;
        queue1[rear]=item;
        printf("\nData inserted successfully");
    }
}


void pop()
{
    if(front==rear)
        printf("\nStack is Empty");
    else
    {
        temp=rear;
        for(i=rear;i>=0;i--)
        {
            front++;
            arr[i]=queue1[front];
        }
        if(front==rear)
            front=rear=-1;
        for(i=0;i<=temp;i++)
        {
            rear++;
            queue1[rear]=arr[i];
        }
        printf("The deleted element is: %d",queue1[++front]);
    }
        if(front==rear)
            front=rear=-1;
        else
        {
            for(i=rear-1;i>=0;i--)
                arr[i]=queue1[++front];
        if(front==rear)
            front=rear=-1;

        for(i=0;i<=temp-1;i++)
            queue1[++rear]=arr[i];

        }
         printf("\nOne element is deleted successfully");
}


void display()
{
    if(front==rear)
        printf("\nThe stack is Empty");
    else
    {
        printf("\nThe stack elements are: ");
        for(i=rear;i>=front+1;i--)
            printf("%d\t",queue1[i]);
    }
}
