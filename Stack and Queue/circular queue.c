#include<stdio.h>
#include<stdlib.h>

#define n 5

void enqueue();
void dequeue();
void display();

void main()
{
    int choice;
    printf("\t\t\t***\tCircular queue\t***");
    //printf("\nEnter the queue size: ");
    //scanf("%d",&n);
    while(1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
           case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(1);

            default: printf("\nEnter valid option!!!");
        }
    }
}

int queue[n],front=-1,rear=-1,i,item;

void enqueue()
{
    if(((rear+1)%n)==front)
    {
        printf("\nQueue is Full");
        printf("\nIf you want to insert please delete data");
    }
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        printf("Enter the element to insert: ");
        scanf("%d",&item);
        queue[rear]=item;
        printf("\nData inserted successfully");
    }
    else if(rear==n-1)
    {
        rear=0;
        printf("Enter the element to insert: ");
        scanf("%d",&item);
        queue[rear]=item;
        printf("\nData inserted successfully");
    }
    else
    {
        printf("\nEnter the element to insert: ");
        scanf("%d",&item);
        rear=(rear+1)%n;
        queue[rear]=item;
        printf("\nData inserted successfully");
    }
}

void dequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("\nQueue is Empty");
        printf("\nIf you want to delete please insert data");
    }
    else if(front==rear)
    {
        printf("\nThe deleted element is: %d",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("\nThe deleted element is: %d",queue[front]);
        front=(front+1)%n;
        printf("\nData deleted successfully");

    }
}

void display()
{
    if(front==-1&&rear==-1)
    {
        printf("\nQueue is Empty");
        printf("\nIf you want to display please insert data");
    }
    else
    {
        printf("\nThe queue elements are: ");
        i=front;
        while(i!=rear)
        {
            printf("%d\t",queue[i]);
            i=(i+1)%n;
        }
        printf("%d",queue[i]);
    }
}
