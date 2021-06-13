#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
void find_pair(struct node*);

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
        printf("\n3. FIND PAIR");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: find_pair(head);
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

void find_pair(struct node* head)
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        int x;
        printf("\nEnter the value of x: ");
        scanf("%d",&x);
        struct node* temp=head;
        struct node* temp1=NULL;
        while(temp->next->next!=NULL)
        {
            temp1=temp->next;
            while(temp1!=NULL)
            {
                int sum=temp->data+temp1->data;
                if(sum==x)
                    printf("(%d , %d)",temp->data,temp1->data);
                temp1=temp1->next;
            }
            temp=temp->next;
        }
    }
}
