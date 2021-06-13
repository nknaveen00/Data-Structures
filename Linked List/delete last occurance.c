#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
struct node* add(struct node*);
struct node* lastoccurance(struct node*);

void main()
{
    system("color 5f");
    struct node* head=NULL;
    int choice;
    do
    {
        printf("\n1. INSERT");
        printf("\n2. DISPLAY");
        printf("\n3. DELETE LAST OCCURANCE");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: head=lastoccurance(head);
                    break;
        }
    }while(choice<=3);

}

int count;
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

struct node* lastoccurance(struct node* head)
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        int i=1,key;
        printf("\nEnter a number between 1-%d:  ",count);
        scanf("%d",&key);
        struct node* temp=head;
        struct node* temp1;
        while(i!=count-key+1)
        {
            temp1=temp;
            temp=temp->next;
            i++;
        }
        temp1->next=temp->next;
        free(temp);
        count--;
        printf("\nAfter deleting list");
        display(head);
    }
    return head;
}
