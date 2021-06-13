#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
struct node* add(struct node*);
struct node* find(struct node*);
struct node* reverse(struct node*);

void main()
{
    system("color 5f");
    struct node* head=NULL;
    int choice;
    do
    {
        printf("\n1. INSERT");
        printf("\n2. DISPLAY");
        printf("\n3. DECIMAL VALUE OF LIST");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: head=find(head);
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

struct node* find(struct node* head)
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        int val=0;
        head=reverse(head);
        struct node* temp=head;
        while(temp!=NULL)
        {
            val=(val<<1)+temp->data;
            temp=temp->next;
        }
        if(val==0)
            printf("\nThe decimal value of list is: 0");
        else
            printf("\nThe decimal value of list is: %d",val);
        head=reverse(head);
    }
    return head;
}

struct node* reverse(struct node* head)
{
    struct node* prev=NULL;
    struct node* curr=head;
    struct node* last;
    while(curr!=NULL)
    {
        last=curr->next;
        curr->next=prev;
        prev=curr;
        curr=last;
    }
    head=prev;
    return head;
}
