#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
    struct node *prev;
}*newnode,*temp1,*temp2;
struct node *head=NULL;

int isEmpty();
void insertele(int,int);
void deletele();
void display();
void getcount();

void main()
{
    int choice,d,p;
    printf("\t\t\t\t***\tPriority Queue Using Doubly Linked List\t***");
    while(1)
    {
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Delete");
        printf("\n4.Counts of element");
        printf("\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the data to insert: ");
                    scanf("%d",&d);
                    printf("\nEnter priority: ");
                    scanf("%d",&p);
                    insertele(d,p);
                    break;
            case 2: display();
                    break;
            case 3: deletele();
                    break;
            case 4: getcount();
                    break;
            case 5: exit(1);
            default: printf("\nEnter valid choice!!!");
        }
    }
}
int count=0;

int isEmpty()
{
    if(head==NULL)
        return 1;
    else
        return 0;
}

void insertele(int item,int prty)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->priority=prty;
    if(isEmpty())
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
        count++;
        printf("\nData inserted successfully");
    }
    else
    {
        temp1=temp2=head;
        while((temp1->priority<newnode->priority)&&(temp1->next!=NULL))
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        if((temp1->priority<newnode->priority)&&temp1->next==NULL)
        {
            newnode->next=NULL;
            newnode->prev=temp1;
            temp1->next=newnode;
            count++;
            printf("\nData inserted successfully");
        }
        else if((temp1->priority<newnode->priority))
        {
            newnode->next=temp1;
            newnode->prev=temp2;
            temp1->prev=newnode;
            count++;
            printf("\nData inserted successfully");
        }
    }
}

void display()
{
    if(isEmpty())
        printf("\nQueue is Empty");
    else
    {
        temp1=head;
        printf("\nQueue elements and its priority\n");
        int i=1;
        while(i<=count)
        {
            printf("\nThe %d element and its priority is: %d , %d",i,temp1->data,temp1->priority);
            temp1=temp1->next;
            i++;
        }
    }
}

void deletele()
{

}

void getcount()
{
    if(isEmpty())
        printf("\nQueue is Empty");
    else
        printf("\n%d elements present in the queue",count);
}
