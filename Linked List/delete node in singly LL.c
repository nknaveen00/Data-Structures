/***
    Given a Singly Linked List, write a function to delete a given node. Your function must follow following constraints:

1) It must accept a pointer to the start node as the first parameter and node to be deleted as the second parameter
i.e., a pointer to head node is not global.

2) It should not return a pointer to the head node.

3) It should not accept pointer to pointer to the head node.

*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
struct node* delnode(struct node*,int);

void main()
{
    struct node* head=NULL;
    int ch,data;
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
            case 3: printf("\nEnter the data to delete: ");
                    scanf("%d",&data);
                    head=delnode(head,data);
                    break;

            default: printf("\nEnter valid option");
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
        printf("\nThe elements are:  ");
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
}

struct node* delnode(struct node* start, int item)
{
    if(start==NULL)
        printf("\nList is Empty\n");
    else
    {
        struct node* temp=start;
        struct node* temp1;
        if(temp->data==item)
        {
            start=temp->next;
            free(temp);
        }
        else
        {
            while(temp->data!=item)
            {
                temp1=temp;
                temp=temp->next;
            }
            temp1->next=temp->next;
            free(temp);
        }
    }
    return start;
}
