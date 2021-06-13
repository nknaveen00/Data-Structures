/**

        Rearranging the node int form of zig zag i.e a < b > c < d > e < f
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
struct node* rearrange(struct node*);

void main()
{
    struct node* head=NULL;
    int choice;
    system("color 5f");
    printf("\t\t\t\t***\tDeleting Alternate Nodes in Linked List\t***");
    do
    {
        printf("\n1. INSERT");
        printf("\n2. DISPLAY");
        printf("\n3. REARRANGE");
        printf("\n4. EXIT");
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

struct node* rearrange(struct node* list)
{
    if(list==NULL&&list->next!=NULL)
        printf("\nCan't rearrange");
    else
    {
        int temp;
        struct node* curr=list->next;
        struct node* prev=list;
        while(curr!=NULL)
        {
            if(prev->data>curr->data)
            {
                temp=curr->data;
                curr->data=prev->data;
                prev->data=temp;
                prev=curr;
                curr=curr->next;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
            if(prev->data<curr->data)
            {
                temp=curr->data;
                curr->data=prev->data;
                prev->data=temp;
                prev=curr;
                curr=curr->next;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
            display(list);
        }
    }
    printf("\nAfter rearrangement the list elements are:  ");
    display(list);
    return list;
}
