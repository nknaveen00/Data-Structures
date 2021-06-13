#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

struct node* insert(struct node*);
void display(struct node*);
void palindrome(struct node*);


int choice,count=0;
int main()
{
    struct node *head=NULL;
    struct node* prev=NULL;
    system("color 5f");
   do
    {
    printf("\n1.Insert");
    printf("\n2.Display");
    printf("\n3.Palindrome or not");
    printf("\n4.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: head=insert(head);
               break;
        case 2:display(head);
                break;
        case 3:palindrome(head);
                break;
    }
    } while(choice<=3);
}

struct node* insert(struct node* head)
{
    int item;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the element to insert: ");
    scanf("%d",&item);
    if(head==NULL)
    {
        count++;
        newnode->data=item;
        newnode->next=NULL;
        head=newnode;
        printf("\nData inserted successfully");
    }
    else
    {
        count++;
        newnode->data=item;
        newnode->next=NULL;
        struct node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
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
        struct node *temp=head;
        printf("The elements are:  ");
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp!=NULL);
    }
}

void palindrome(struct node* head)
{
    int stack[30];
    int top=-1,len=0;
    struct node* temp=head;
    while(temp!=NULL)
    {
        stack[++top]=temp->data;
        temp=temp->next;
    }
    temp=head;
    while(top!=-1)
    {
        printf("\n %d\t%d",temp->data,stack[top]);
        if(stack[top]!=temp->data)
        {
            printf("\nList is not a Palindrome");
            break;
        }
        else
        {
            top--;
            temp=temp->next;
            len++;
        }
    }
    if(len==count)
        printf("\nList is Palindrome");
}
