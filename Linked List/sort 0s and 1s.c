#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
struct node* sort(struct node*);
int getcount(struct node*, int);

void main()
{
    struct node* head=NULL;
    int ch;
    printf("\t\t\t***\tDelete node which have greater element on it's right side\t***");
    do
    {
        printf("\n1. INSERT");
        printf("\n2. DISPLAY");
        printf("\n3. SORT");
        printf("\n4. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: head=sort(head);
                    break;

        }
    }while(ch<=3);
}

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
        start=newnode;
        printf("\nData inserted successfully\n");
    }
    else
    {
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

struct node* sort(struct node* start)
{
    if(start==NULL)
        printf("\nList is Empty\n\n");
    else
    {
        int n1,n2,n3,i=1;
        struct node* temp=start;
        n1=getcount(start, 0);
        n2=getcount(start, 1);
        n3=getcount(start, 2);
        printf("\n%d",n1);
        printf("\n%d",n2);
        printf("\n%d",n3);
        printf("\nBefore sorting list is:  ");
        display(start);
        while(i<=n1)
        {
            temp->data=0;
            temp=temp->next;
            i++;
        }
        //printf("\nAfter sorting list is:  ");
        //display(start);
        i=1;
        while(i<=n2)
        {
            temp->data=1;
            temp=temp->next;
            i++;
        }
        //printf("\nAfter sorting list is:  ");
        //display(start);
        i=1;
        while(i<=n3)
        {
            temp->data=2;
            temp=temp->next;
            i++;
        }
        printf("\nAfter sorting list is:  ");
        display(start);
    }
    return start;
}

int getcount(struct node* start, int item)
{
    int count=0;
    struct node* temp=start;
    while(temp!=NULL)
    {
        if(temp->data==item)
            count++;
        temp=temp->next;
    }
    return count;
}
