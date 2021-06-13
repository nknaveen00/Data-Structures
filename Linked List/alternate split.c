#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*head;
struct node* list1=NULL;
struct node* list2=NULL;

void insert();
void display(struct node*);
void altsplit();
void viewnewlist();
struct node* newlist(struct node*,struct node*);

void main()
{
    int choice;
    printf("\t\t\t\t***\tSplitting alternate Data\t***");
    printf("\nYour choice is must between 1-4");
    do
    {
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Alternate split");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: display(head);
                    break;
            case 3: altsplit();
                    break;
            case 4: exit(1);
        }
    }while(choice>=1&&choice<=4);
}

void insert()
{
    int item;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter your data: ");
    scanf("%d",&item);
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
}

void display(struct node* print)
{
    if(print==NULL)
        printf("\nList is Empty");
    else
    {
        struct node* temp=print;
        printf("\nThe list elements are:  ");
        do
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }while(temp!=NULL);
    }
}

void altsplit()
{
    if(head==NULL&&head->next==NULL)
        printf("\nCan't perform split operation");
    else
    {
        struct node* temp=head;
        int select=1;
        do
        {
            if(select==1)
            {
                list1=newlist(temp,list1);
                select++;
            }
            else
            {
                list2=newlist(temp,list2);
                select--;
            }
            temp=temp->next;
        }while(temp!=NULL);
        display(head);
        display(list1);
        display(list2);
    }
}

struct node* newlist(struct node* temp,struct node* list)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=temp->data;
    newnode->next=NULL;
    if(list==NULL)
    {
        list=newnode;
    }
    else
    {
        struct node* last=list;
        while(last->next!=NULL)
            last=last->next;
        last->next=newnode;
    }
    return list;
    printf("\nworking new list1");
}
