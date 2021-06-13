#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* arbit;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
void arbitdata(struct node*);
struct node* pointnexthigher(struct node*);
struct node* getmax(struct node*,int);

void main()
{
    struct node* head=NULL;
    struct node* arbithead=NULL;
    int ch;
    printf("\t\t\t***\tDelete node which have greater element on it's right side\t***");
    do
    {
        printf("\n1. INSERT");
        printf("\n2. DISPLAY");
        printf("\n3. POINT NEXT HIGHER");
        printf("\n4. DISPLAY ARBIT");
        printf("\n5. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: arbithead=pointnexthigher(head);
                    break;
            case 4: arbitdata(arbithead);

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
    newnode->arbit=NULL;
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

void arbitdata(struct node* start)
{
    if(start==NULL)
        printf("\nList is Empty\n");
    else
    {
        printf("\n");
        while(start!=NULL)
        {
            printf("%d  ",start->data);
            start=start->arbit;
        }
    }
}

struct node* pointnexthigher(struct node* start)
{
    if(start==NULL&&start->next==NULL)
        printf("\nCan't point next higher");
    else
    {
        struct node* curr=NULL;
        struct node* temp=start;
        struct node* max_node=NULL;
        while(temp!=NULL)
        {
            curr=start;
            max_node=getmax(start,0);
            while(curr!=NULL)
            {
                if(curr==temp)
                    curr=curr->next;
                else if(temp->data<curr->data&&curr->data<max_node->data)
                {
                    max_node=curr;
                }
                else
                    curr=curr->next;
            }
                temp->arbit=max_node;
                temp=temp->next;
        }
        max_node=getmax(start,0);
        max_node->arbit=NULL;
    }
    struct node* arbithead=getmax(start,1);
    printf("\nThe arbit data is:  ");
    arbitdata(arbithead);
    return arbithead;
}

struct node* getmax(struct node* start, int flag)
{
    struct node* temp=start->next;
    struct node* max=start;
    if(flag==0)
    {
        while(temp!=NULL)
        {
            if(temp->data>max->data)
                max=temp;
            temp=temp->next;
        }
        return max;
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->data<max->data)
                max=temp;
            temp=temp->next;
        }
        printf("%d",max->data);
        return max;
    }
}
