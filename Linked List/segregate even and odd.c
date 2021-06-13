#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head,*newnode,*temp,*temp1;
struct node *head=NULL;
struct node *head2=NULL;

void insert();
void display();
void deletele();
void segregate();
void createnode(int*);
void displayseg();
void segwithoutextraspace();



int item,pos,choice,min;
void main()
{
    printf("\t\t\t***\tSegregate even and odd nodes\t***\n");
    printf("\nNote: You want to remove duplicates you must enter data in sorted order");
    while(1)
    {
    printf("\n1.Insert");
    printf("\n2.Display");
    printf("\n3.Delete");
    printf("\n4.Segregate Data");
    printf("\n5.Display segregated data");
    printf("\n6.Segregate without extra space");
    printf("\n7.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insert();
               break;
        case 2:display();
                break;
        case 3:deletele();
                break;
        case 4:segregate();
                break;
        case 5:displayseg();
                break;
        case 6:segwithoutextraspace();
                break;
        case 7: exit(1);

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


void deletele()
{
    if(head==NULL)
        printf("\nList is Empty");
    else if(head->next==NULL)
    {
        printf("\nThe deleted element is %d",head->data);
        head=NULL;
    }
    else
   {
       temp=temp1=head;
       while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
       printf("\nThe Deleted element is %d",temp->data);
       temp1->next=NULL;
       free(temp);
       printf("\nData is deleted successfully");
   }
}

void segregate()
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            if(temp->data%2==0)
            {
                createnode(&temp->data);
            }
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            if(temp->data%2!=0)
            {
                createnode(&temp->data);
            }
            temp=temp->next;
        }
        printf("\nData's segregated successfully\nIf you want to see please select option 5\n");
    }
}

void createnode(int *x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(head2==NULL)
    {
        newnode->data=*x;
        newnode->next=NULL;
        head2=newnode;
    }
    else
    {
        temp1=head2;
        newnode->data=*x;
        newnode->next=NULL;
        while(temp1->next!=NULL)
            temp1=temp1->next;
        temp1->next=newnode;
    }
}

void displayseg()
{
    if(head2==NULL)
        printf("\nList is Empty\n");
    else
    {
        temp=head2;
        printf("The elements are:  ");
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp!=NULL);
    }
}
void segwithoutextraspace()
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        struct node* last;
        struct node* end=head;
        struct node* prev=NULL;
        temp=head;
        temp1=NULL;

        while(end->next!=NULL)
            end=end->next;
        last=end;
        while(temp->data%2!=0&&temp!=end)
        {
            last->next=temp;
            temp=temp->next;
            last->next->next=NULL;
            last=last->next;
        }
        if(temp->data%2==0)
        {
            head=temp;
            while(temp!=end)
            {
                if(temp->data%2==0)
                {
                    temp1=temp;
                    temp=temp->next;
                }
                else
                {
                    temp1->next=temp->next;
                    temp->next=NULL;
                    last->next=temp;
                    last=temp;
                    temp=temp1->next;
                }
            }
        }
        else
            temp1=temp;
        if(last!=end&&end->data%2!=0)
        {
            temp1->next=end->next;
            end->next=NULL;
            last->next=end;
        }
    }
    printf("\nData segregated successfully\nIf you want to see press 2");
}

