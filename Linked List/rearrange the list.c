#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
struct node* arrange(struct node*);
struct node* reverse(struct node*);
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
            case 3: head=arrange(head);
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

struct node* arrange(struct node* start)
{
    if(start->next==NULL||start->next->next==NULL||start==NULL)
        printf("\nCan't rearrange\n\n");
    else
    {
        struct node* even=start->next;
        struct node* prev=start;
        struct node* curr=start->next;
        while((prev!=NULL&&curr!=NULL))//||(prev->next!=NULL||curr->next!=NULL))
        {
            prev->next=curr->next;
            prev=curr->next;
            if(curr!=NULL&&curr->next==NULL&&prev==NULL)
                break;
            curr->next=prev->next;
            curr=prev->next;
        }
        struct node* temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=even;
    }
    display(start);
    return start;
}
