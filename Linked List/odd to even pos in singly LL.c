#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
struct node* change(struct node*);

void main()
{
    struct node* head=NULL;
    int ch;
    printf("\t\t\t***\tDelete node which have greater element on it's right side\t***");
    do
    {
        printf("\n1. INSERT");
        printf("\n2. DISPLAY");
        printf("\n3. REARRANGE");
        printf("\n4. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: head=change(head);
                    break;

        }
    }while(ch<=3);
}

int count=0;

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
        count++;
        start=newnode;
        printf("\nData inserted successfully\n");
    }
    else
    {
        count++;
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
        printf("\n");
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
}

struct node* change(struct node* start)
{
    if(start==NULL)
        printf("\nList is Empty\n\n");
    else
    {
        struct node* prev=start;
        struct node* curr=NULL;
        struct node* last=NULL;
        while(prev!=NULL)
        {
            printf("1");
            curr=prev->next;
            last=curr->next;
            prev->next=last;
            last->next=curr;
            prev=curr;
        }
        printf("\nAfter arrangement list is\n");
        display(start);
    }
    return start;
}
