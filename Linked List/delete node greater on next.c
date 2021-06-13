/**

Delete node which node have a greater element on it's right side

input: 1->5->3->2->0->7->4->8->12->2
output: 12->2

*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*head;

void insert();
void display();
struct node* deletegreater();
struct node*reverse(struct node*);

void main()
{
    int ch;
    printf("\t\t\t***\tDelete node which have greater element on it's right side\t***");
    do
    {
        printf("\n1. INSERT");
        printf("\n2. DISPLAY");
        printf("\n3. DELETE");
        printf("\n4. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
                    break;
            case 2: display();
                    break;
            case 3: head=deletegreater();
                    break;
            case 4: exit(1);

            default: printf("\nEnter valid option");
        }
    }while(ch<=4);
}

void insert()
{
    int item;
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
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
}

void display()
{
    if(head==NULL)
        printf("\nList is Empty\n");
    else
    {
        struct node* temp=head;
        printf("\nThe list elements are:  ");
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
}

struct node* deletegreater()
{
    if(head==NULL)
        printf("\nList is Empty\n");
    else
    {
        head=reverse(head);
        struct node* curr=head;
        struct node* temp;
        struct node* max=head;
        while(curr!=NULL&&curr->next!=NULL)
        {
            if(curr->next->data<max->data)
            {
                temp=curr->next;
                curr->next=temp->next;
                free(temp);
            }
            else
            {
                curr=curr->next;
                max=curr;
            }
        }
        head=reverse(head);

    }
}

struct node* reverse(struct node* start)
{
    if(start!=NULL)
    {
        struct node* curr=start;
        struct node* temp=NULL;
        while(curr->next!=NULL)
        {
            temp=curr->next;
            curr->next=temp->next;
            temp->next=start;
            start=temp;
        }
    }
    return start;
}

