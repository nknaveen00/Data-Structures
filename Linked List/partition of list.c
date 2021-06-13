#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
struct node* partition(struct node*);


int count=0;

void main()
{
    system("color 5f");
    struct node* head=NULL;
    int choice;
    do
    {
        printf("\n1. INSERT");
        printf("\n2. DISPLAY");
        printf("\n3. PARTITION");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: head=partition(head);
                    break;
        }
    }while(choice<=3);

}

struct node* insert(struct node* head)
{
    int item;
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    count++;
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

struct node* partition(struct node* head)
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        int x;
        printf("\nEnter the value of x: ");
        scanf("%d",&x);
        struct node* smallhead=NULL;
        struct node* smalllast=NULL;
        struct node* equalhead=NULL;
        struct node* equallast=NULL;
        struct node* greaterhead=NULL;
        struct node* greaterlast=NULL;
        while(head!=NULL)
        {
            if(head->data<x)
            {
                if(smallhead==NULL)
                    smallhead=smalllast=head;
                else
                {
                    smalllast->next=head;
                    smalllast=smalllast->next;
                }
            }
            else if(head->data==x)
            {
                if(equalhead==NULL)
                    equalhead=equallast=head;
                else
                {
                    equallast->next=head;
                    equallast=equallast->next;
                }
            }
            else if(head->data>x)
            {
                if(greaterhead==NULL)
                    greaterhead=greaterlast=head;
                else
                {
                    greaterlast->next=head;
                    greaterlast=greaterlast->next;
                }
            }
            head=head->next;
        }
        printf("\nList is partitioned successfully");
         if(greaterlast!=NULL)
            greaterlast->next = NULL;

        if (smallhead==NULL)
        {
        if (equalhead==NULL)
            return head=greaterhead;
        equallast->next =greaterhead;
        return head=equalhead;
    }
    if (equalhead==NULL)
    {
        smalllast->next = greaterhead;
        return head=smallhead;
    }
    smalllast->next = equalhead;
    equallast->next = greaterhead;
    return  head=smallhead;
    }
    return head;
}
