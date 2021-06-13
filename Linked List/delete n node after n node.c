#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
struct node* deletemaftern(struct node*);

void main()
{
    struct node* head=NULL;
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
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: head=deletemaftern(head);
                    break;

        }
    }while(ch<=3);
}

struct node* insert(struct node* start)
{
    int item;
    printf("Enter the data to insert: ");
    scanf("%d",&item);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
        printf("\n");
    }
    else
    {
        struct node* temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        printf("\n");
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

struct node* deletemaftern(struct node* start)
{
    if(start==NULL)
        printf("\nList is Empty\n\n");
    else
    {
        int n,m,i=1;
        printf("Enter the value of m:  ");
        scanf("%d",&m);
        printf("Enter the value of n:  ");
        scanf("%d",&n);
        printf("Before delete list is:  ");
        display(start);
        struct node* prev=start;
        struct node* curr=start;
        while(i<=m)
        {
            prev=curr;
            curr=curr->next;
            i++;
        }

        while(n!=0)
        {
            prev->next=curr->next;
            free(curr);
            curr=prev->next;
            n--;
        }
    }
    printf("After delete list is:  ");
    display(start);

    return start;
}
