#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
struct node* rotate(struct node*,int);

void main()
{
    struct node* head=NULL;
    int ch,pos;
    printf("\t\t\t***\tDelete node which have greater element on it's right side\t***");
    do
    {
        printf("\n1. INSERT");
        printf("\n2. DISPLAY");
        printf("\n3. ROTATE LIST");
        printf("\n4. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: printf("\nEnter the position to rotate: ");
                    scanf("%d",&pos);
                    head=rotate(head,pos);
                    break;

            default: printf("\nEnter valid option");
        }
    }while(ch<=3);
}

struct node* insert(struct node* start)
{
    int item;
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
        printf("\nData inserted successfully\n");
    }
    else
    {
        struct node* temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        printf("\nData inserted successfully\n");
    }
    return start;
}

void display(struct node* start)
{
    if(start==NULL)
        printf("\nList is Empty\n");
    else
    {
        struct node* temp=start;
        printf("\nThe elements are:  ");
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
}

struct node* rotate(struct node* start ,int k)
{
    if(start==NULL)
        printf("\nList is Empty\n");
    else
    {
        int count=1;
        struct node* temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=start;
        temp=start;
        while(count!=k)
        {
            temp=temp->next;
            count++;
        }
        start=temp->next;
        temp->next=NULL;
    }
    return start;

}
