#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int flag;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
struct node* arrange(struct node*);
void detect(struct node*);
void main()
{
    struct node* head=NULL;
    int ch;
    printf("\t\t\t***\tDelete node which have greater element on it's right side\t***");
    do
    {
        printf("\n1. INSERT");
        printf("\n2. DISPLAY");
        printf("\n3. DETECT LOOP");
        printf("\n4. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: detect(head);
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
    newnode->flag=0;
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

void detect(struct node* start)
{
    int set=0;
    if(start==NULL)
        printf("\nList is Empty\n\n");
    else
    {
        struct node* temp=start;
        //This comment section for create loop
        /**
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=start;
        temp=start;
        */
        while(temp!=NULL)
        {
            if(temp->flag==1)
            {
                set=1;
                break;
            }

            temp->flag=1;
            temp=temp->next;
        }
        if(set==1)
            printf("\nThe list have loop");
        else
            printf("\nThe list not have loop");
    }
}
