
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head,*newnode,*temp;
struct node *head=NULL;

void insert();
void display();
void oddeven();


int item,pos,choice,min;
void main()
{
    printf("\t\t\t***\tSegregate even and odd nodes\t***\n");
    printf("\nNote: You want to remove duplicates you must enter data in sorted order");
    while(1)
    {
    printf("\n1.Insert");
    printf("\n2.Display");
    printf("\n3.Alternate odd and even");
    printf("\n4.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insert();
               break;
        case 2:display();
                break;
        case 3:oddeven();
                break;
        case 4: exit(1);

        default:printf("\nEnter valid choice!!!\n");
                break;
    }
}

}

void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the element to insert: ");
    scanf("%d",&item);
    if(head==NULL)
    {
        min=item;
        newnode->data=item;
        newnode->next=NULL;
        head=newnode;
        printf("\nData inserted successfully");
    }
    else
    {
        newnode->data=item;
        newnode->next=NULL;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        printf("\nData inserted successfully\n");

    }
}

void display()
{
    if(head==NULL)
        printf("\nList is Empty\n");
    else
    {
        temp=head;
        printf("The elements are:  ");
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp!=NULL);
    }
}


void oddeven()
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        struct node* even;
        struct node *prev_temp;
        struct node *i,*j,*k,*l,*ptr;

        ///Segregate odd and even nodes

        temp=head->next;
        prev_temp=head;
        while(temp!=NULL)
        {
            struct node* x=temp->next;
            if(temp->data%2!=0)
            {
                prev_temp->next=x;
                temp->next=head;
                head=temp;
            }
            else
            {
                prev_temp=temp;
            }
            temp=x;
        }

        ///Split data odd and even
        temp=head->next;
        prev_temp=head;
        while(temp!=NULL&&temp->data%2!=0)
        {
            prev_temp=temp;
            temp=temp->next;
        }
        even=temp;
        prev_temp->next=NULL;

        ///Merge even list into odd
        i=head;
        j=even;
        while(i!=NULL&&j!=NULL)
        {
            k=i->next;
            l=j->next;

            i->next=j;
            j->next=k;

            ptr=j;

            i=k;
            j=l;
        }
        if(i==NULL)
            ptr->next=j;

    }
}
