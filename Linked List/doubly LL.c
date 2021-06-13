#include<stdio.h>
#include<stdlib.h>

///Structure Creation

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
struct node *newnode;
struct node *temp;
struct node *temp1;

///Function Declaration
void insertfirst();
void insertlast();
void insertmid();
void display();
int length();
void deletefirst();
void deletelast();
void deletemid();
void reverselist();

int main()
{
    int choice;
    printf("\t\t\t\t***Doubly Linked List***");
    while(1)
    {
        printf("\n1.Insert First");
        printf("\n2.Insert Last");
        printf("\n3.Insert Middle");
        printf("\n4.Display");
        printf("\n5.Delete First");
        printf("\n6.Delete Last");
        printf("\n7.Delete Middle");
        printf("\n8.Reverse List");
        printf("\n9.Exit");
        printf("\nEnter your choice:");
        scanf("\t%d",&choice);
        switch(choice)
        {
            case 1: insertfirst();
                    break;
            case 2: insertlast();
                    break;
            case 3: insertmid();
                    break;
            case 4: display();
                    break;
            case 5: deletefirst();
                    break;
            case 6: deletelast();
                    break;
            case 7: deletemid();
                    break;
            case 8: reverselist();
                    break;
            case 9: exit(1);

            default: printf("\nEnter valid choice!!!");

        }

    }
}

int item,pos;       ///Global Declaration because these variables are will we use mostly

///This code is inserting node at fisrt position

void insertfirst()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the element to insert:");
    scanf("\t%d",&item);
    newnode->data=item;
    newnode->prev=NULL;
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
        printf("\nData inserted successfully");
    }
    else
    {
        newnode->next=head;
        head=newnode;
        printf("\nData inserted successfully");
    }
}


///This code is inserting node at last position

void insertlast()
{
    if(head!=NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the element to insert:");
        scanf("\t%d",&item);
        newnode->data=item;
        temp=head;

        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
        printf("\nData inserted successfully");
    }
    else
        printf("\nThe List is Empty");
}

///This code is inserting node at last position

void insertmid()
{
    if(head==NULL)
        printf("\nThe List is Empty");
    else if(head->next==NULL)
        printf("\nThere is one element in the List");
    else
    {
        int count=length();
        printf("\nEnter the position to insert:");
        scanf("%d",&pos);
        if(pos<=count)
        {
            int i=1;
            temp=temp1=head;
            printf("\nEnter the element to insert:");
            scanf("\t%d",&item);
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=item;
            while(i<pos)
            {
                temp1=temp;
                temp=temp->next;
                i++;
            }
            newnode->next=temp;
            newnode->prev=temp1;
            temp1->next=newnode;
            temp->prev=newnode;
            printf("\nData inserted successfully");
        }
        else
            printf("\nEnter Valid Position");
    }

}

int length()
{
    int count=0;
    if(head!=NULL)
    {
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
    }
    else
        printf("\nList is Empty!!!");
    return count;
}

///This code is inserting node at last position

void display()
{
    if(head!=NULL)
    {
        temp=head;
        printf("\nThe list elements are:");
        do
        {
            printf("\t%d",temp->data);
            temp=temp->next;        //End of the loop the temp gets NULL
        }while(temp!=NULL);
    }
    else
        printf("\nThe list is empty");
}


///This code is inserting node at last position

void deletefirst()
{
    if(head==NULL)
        printf("\nThe List is Empty");
    else
    {
        temp=head;
        head=head->next;
        printf("\nThe deleted element is %d",temp->data);
        free(temp);
        temp=NULL;
        printf("\nThe element is deleted successfully");
    }
}

///This code is inserting node at last position

void deletelast()
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        temp1=temp=head;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        printf("\nThe deleted element is %d",temp->data);
        temp1->next=NULL;
        free(temp);
        temp=NULL;
    }

}

///This code is inserting node at last position

void deletemid()
{
    if(head==NULL)
        printf("\nList is Empty");
    else if(head->next==NULL)
        printf("\nThere is one element in the List");
    else
    {
        int count=length();
        printf("\nEnter the position to delete:");
        scanf("\t%d",&pos);
        if(pos<=count)
        {
            int i=1;
            temp=temp1=head;
            while(i<pos)
            {
                temp1=temp;
                temp=temp->next;
                i++;
            }
            printf("\nThe deleted element is %d",temp->data);
            temp1->next=temp->next;
            temp->next->prev=temp1;
            free(temp);
            temp=NULL;
            printf("\nDeleted successfully");
        }
        else
            printf("\nEnter Valid Position");
    }

}

void reverselist()
{
    if(head==NULL)
        printf("\nList is Empty");
    else if(head->next==NULL)
        printf("\nThe reverse order is\t%d",head->data);
    else
    {
        struct node *last;
        temp=head;
        while(temp->next!=NULL)
        {
            last=temp;
            temp=temp->next;
        }
        printf("\nThe reverse order of list is ");
        while(last->prev!=NULL)
        {
            printf("\t%d",last->data);
            last=last->prev;
        }
        }

}
