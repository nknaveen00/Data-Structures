#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*newnode;

struct node* insert(struct node*,int);
void display(struct node*);
struct node* deletealt(struct node*);

void main()
{
    struct node* head=NULL;
    int item,choice;
    printf("\t\t\t\t***\tDeleting Alternate Nodes in Linked List\t***");
    while(1)
    {
        printf("\n1. INSERT");
        printf("\n2. DISPLAY");
        printf("\n3. DELETE ALTERNATE NODES");
        printf("\n4. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the data to insert: ");
                    scanf("%d",&item);
                    head=insert(head,item);
                    break;
            case 2: display(head);
                    break;
            case 3: head=deletealt(head);
                    break;
            case 4: exit(1);
            default: printf("\nEnter valid option!!!");
        }
    }

}

struct node* insert(struct node* head,int item)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        printf("\nData inserted successfully");
        return head;
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        printf("\nData inserted successfully");
        return head;
    }
};

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

struct node* deletealt(struct node* head)
{
    if(head==NULL||head->next==NULL)
        printf("\nCan't delete alternate nodes\n");
        return head;
    }
    else
    {
        struct node* prev=head;
        struct node* curr=NULL;
        //struct node* frwd=NULL;
        do
        {
            curr=prev->next;
            prev->next=curr->next;
            free(curr);
            prev=prev->next;
        }while(prev!=NULL&&prev->next!=NULL);
        return head;
    }
}
