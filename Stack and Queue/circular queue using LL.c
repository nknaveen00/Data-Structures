#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*newnode,*temp;

struct node *front=NULL;
struct node *rear=NULL;

void enqueue();
void dequeue();
void display();

void main()
{
    int choice;
    printf("\t\t\t\t***\tCircular queue using Linked List\t***");
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
            default: printf("\nEnter valid choice!!!");
        }
    }

}

int item,count=0;

void enqueue()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the element to insert: ");
    scanf("%d",&item);
    if(front==NULL)
    {
        newnode->data=item;
        front=newnode;
        rear=newnode;
        newnode->next=front;
        count++;
        printf("\nData inserted successfully");
    }
    else
    {
        temp=front;
        newnode->data=item;
        newnode->next=front;
        rear=newnode;
        while(temp->next!=front)
            temp=temp->next;
        temp->next=newnode;
        count++;
        printf("\nData inserted successfully");
    }
}
void dequeue()
{
    if(front==NULL||count==0)
        printf("\nQueue is Empty");
    else
    {
        temp=front;
        front=temp->next;
        printf("The deleted element is: %d",temp->data);
        rear->next=front;
        free(temp);
        count--;
        if(count==0)
        {
            free(front);
            free(rear);
            front=rear=NULL;
        }
        printf("\nData deleted successfully");
    }
}

void display()
{
    if(front==NULL||count==0)
        printf("\nQueue is Empty");
    else
    {
        printf("\nThe queue elements are: ");
        temp=front;
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp!=front);
    }
}
