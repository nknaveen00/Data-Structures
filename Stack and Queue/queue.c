#include<stdio.h>

void insert();
void traverse();
void deleete();

int front=0;
int rear=0,element,size;
int queue[5],choice;
int main()
{
    printf("\t\t\t\tQueue Operation");
    while(1)
    {
    printf("\n1.Insert\n2.Traverse\n3.Delete\n4.Exit\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insert();
                break;

        case 2:traverse();
                break;

        case 3:deleete();
                break;

        case 4:return 0;
                break;

        default:printf("Enter correct choice!!!\n");

    }
    }
    return 0;
}

void insert()
{
    if(rear==5)
        printf("Queue is full");
    else
    {
        printf("Enter the element to insert: ");
        scanf("%d",&element);
        queue[rear]=element;
        rear++;
        printf("\nInserted successfully!!!");
    }
}

void traverse()
{
    if(rear==front)
        printf("\nQueue is Empty");
    else
    {
        int i;
        printf("The queue elements are\n");
        for(i=front;i<rear;i++)
            printf("%d\t",queue[i]);
    }
}

void deleete()
{
    if(front==rear)
    {
        printf("\nQueue is Empty");
        front=0;
        rear=0;
    }
    else
    {
        printf("The deleted element is: %d",queue[front]);
        front++;
    }
}
