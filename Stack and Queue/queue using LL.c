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
    printf("\t\t\t\t***\tQueue Using Linked List\t***");
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
int item;

void enqueue()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    if(front==NULL)
    {
        newnode->data=item;
        newnode->next=NULL;
        front=newnode;
        rear=newnode;
        printf("\nData inserted successfully");
    }
    else
    {
        newnode->data=item;
        newnode->next=NULL;
        rear=newnode;
        temp=front;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        printf("\nData inserted successfully");

    }
}

void dequeue()
{
    if(front==NULL)
        printf("\nQueue is Empty");
    else
    {
        temp=front;
        printf("\nThe deleted element is: %d",temp->data);
        front=temp->next;
        free(temp);
        printf("\nData is deleted successfully");
    }
}

void display()
{
    if(front==NULL)
        printf("\nQueue is Empty");
    else
    {
        printf("\nThe queue elements are: ");
        temp=front;
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp!=NULL);
    }
}
