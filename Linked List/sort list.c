#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*newnode;

struct node* insert(struct node*);
void display(struct node*);
struct node* sort(struct node*);

void main()
{
    printf("\n4. TO EXIT PRESS GREATER THAN 3");
    struct node* head=NULL;
    int choice;
    do
    {
        printf("\n1. INSERT");
        printf("\n2. DISPLAY");
        printf("\n3. SORT");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: head=sort(head);
                    break;
        }
    }while(choice<=3);

}

struct node* insert(struct node* head)
{
    int item;
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        printf("\nData inserted successfully");
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        printf("\nData inserted successfully");
    }
    return head;
}

void display(struct node* head)
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        struct node* temp=head;
        printf("\nThe list elements are:  ");
        do
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }while(temp!=NULL);
    }
}

struct node* sort(struct node* head)
{
    int temp;
    struct node* prev=head;
    struct node* curr=NULL;
    while(prev->next!=NULL)
    {
        curr=prev->next;
        while(curr!=NULL)
        {
            if(prev->data>curr->data)
            {
                temp=curr->data;
                curr->data=prev->data;
                prev->data=temp;
            }
            curr=curr->next;
        }
        prev=prev->next;
    }
    printf("\nAfter sorting");
    display(head);
    return head;
}
