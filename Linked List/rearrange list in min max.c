#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
struct node* rearrange(struct node*);
struct node* sort(struct node*);

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
        printf("\n3. REARRANGE");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: head=rearrange(head);
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

struct node* rearrange(struct node* head)
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        head=sort(head);
        struct node* last=NULL;
        struct node* last_prev=NULL;
        struct node* temp=head;
        struct node* temp1=head->next;
        int n=(count%2!=0)? count/2: count/2-1;
        int i=1;
        while(i<=n)
        {
            last=head;
            while(last->next!=NULL)
            {
                last_prev=last;
                last=last->next;
            }
            last_prev->next=last->next;
            last->next=temp->next;
            temp->next=last;
            temp=temp->next->next;
            i++;
        }
    }
    printf("\nAfter rearrangement");
    display(head);
    return head;
}

struct node* sort(struct node* head)
{
    int temp;
    struct node* prev=head;
    struct node* curr=NULL;
    while(prev->next!=NULL)
    {
        curr=prev->next;
        while(curr!=NULL)
        {
            if(prev->data>curr->data)
            {
                temp=curr->data;
                curr->data=prev->data;
                prev->data=temp;
            }
            curr=curr->next;
        }
        prev=prev->next;
    }
    return head;
}

