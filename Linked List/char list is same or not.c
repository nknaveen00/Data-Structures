#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    char data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
void same_or_not(struct node*,struct node*);

void main()
{
    struct node* head1=NULL;
    struct node* head2=NULL;
    int choice;
    system("color 5f");
    printf("\t\t\t\t***\tSplitting alternate Data\t***");
    do
    {
        printf("\n1. Insert List 1");
        printf("\n2. Insert List 2");
        printf("\n3. Display List 1");
        printf("\n4. Display List 2");
        printf("\n5. Same or not");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head1=insert(head1);
                    break;
            case 2: head2=insert(head1);
                    break;
            case 3: display(head1);
                    break;
            case 4: display(head2);
                    break;
            case 5: same_or_not(head1,head2);
                    break;
        }
    }while(choice>=1&&choice<=5);
}

struct node* insert(struct node* head)
{
    char item;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter your data: ");
    scanf("%c%*c",&item);
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

void display(struct node* print)
{
    if(print==NULL)
        printf("\nList is Empty");
    else
    {
        struct node* temp=print;
        printf("\nThe list elements are:  ");
        do
        {
            printf("%s  ",temp->data);
            temp=temp->next;
        }while(temp!=NULL);
    }
}

void same_or_not(struct node* list1,struct node* list2)
{

}
