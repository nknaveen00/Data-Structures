#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
void check(
           struct node*);


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
        printf("\n3. CHECK LENGTH IS ODD OR EVEN");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: check(head);
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
        printf("\nData inserted successfully\n");
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        printf("\nData inserted successfully\n");
    }
    return head;
}

void display(struct node* head)
{
    if(head==NULL)
        printf("\nList is Empty\n");
    else
    {
        struct node* temp=head;
        printf("\nThe list elements are:  ");
        do
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }while(temp!=NULL);
        printf("\n");
    }
}

void check(struct node* head)
{
    if(head==NULL)
        printf("\nLIst is Empty\n");
    else
    {
        (count%2==0)? printf("\nList length is even\n") :printf("\nList length is odd\n");
    }
}
