#include<stdio.h>
#include<stdlib.h>



struct node
{
    int data;
    struct node *next;
}*newnode,*temp,*temp1,*last;
struct node *head1=NULL;
struct node *head2=NULL;
struct node *start=NULL;

void insertlist1();
void insertlist2();
void displaylist1();
void displaylist2();
void reverse();
void merge();
void displaymergelist();


int item,choice;
int main()
{
    printf("\t\t\t***\tSingly Linked List and Some operations\t***\n");
    printf("\nNote: You want to remove duplicates you must enter data in sorted order");
    while(1)
    {
    printf("\n1.Insert List1");
    printf("\n2.Insert List2");
    printf("\n3.Display List1");
    printf("\n4.Display List2");
    printf("\n5.Merge");
    printf("\n6.Display Merged List");
    printf("\n7.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insertlist1();
               break;
        case 2:insertlist2();
                break;
        case 3:displaylist1();
                break;
        case 4:displaylist2();
                break;
        case 5:merge();
                break;
        case 6:displaymergelist();
                break;
        case 7: exit(1);

        default:printf("\nEnter valid choice!!!\n");
                break;
    }
}

}

void insertlist1()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the element to insert: ");
    scanf("%d",&item);
    if(head1==NULL)
    {
        newnode->data=item;
        newnode->next=NULL;
        head1=newnode;
        printf("\nData inserted successfully");
    }
    else
    {
        newnode->data=item;
        newnode->next=NULL;
        temp=head1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        printf("\nData inserted successfully\n");

    }
}

void insertlist2()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the element to insert: ");
    scanf("%d",&item);
    if(head2==NULL)
    {
        newnode->data=item;
        newnode->next=NULL;
        head2=newnode;
        printf("\nData inserted successfully");
    }
    else
    {
        newnode->data=item;
        newnode->next=NULL;
        temp=head2;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        printf("\nData inserted successfully\n");

    }
}

void displaylist1()
{
    if(head1==NULL)
        printf("\nList is Empty\n");
    else
    {
        temp=head1;
        printf("The elements are:  ");
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp!=NULL);
    }
}

void displaylist2()
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

void merge()
{
    if(head1==NULL&&head2==NULL)
        printf("\nBoth or any one List Empty");
    else
    {
        while(head1!=NULL||head2!=NULL)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            if(head1!=NULL&&head2!=NULL)
            {
                if(head1->data<=head2->data)
                {
                    if(start==NULL)
                    {
                        newnode->data=head1->data;
                        newnode->next=NULL;
                        start=newnode;
                    }
                    else
                    {
                        last=start;
                        while(last->next!=NULL)
                            last=last->next;
                        newnode->data=head1->data;
                        last->next=newnode;
                        newnode->next=NULL;
                    }
                    head1=head1->next;
                }
                else if(head2->data<head1->data)
                {
                    if(start==NULL)
                    {
                        newnode->data=head2->data;
                        newnode->next=NULL;
                        start=newnode;
                    }
                    else
                    {
                        last=start;
                        while(last->next!=NULL)
                            last=last->next;
                        newnode->data=head2->data;
                        last->next=newnode;
                        newnode->next=NULL;
                    }
                    head2=head2->next;
                }
            }
            else if(head1!=NULL&&head2==NULL)
            {
                if(start==NULL)
                {
                    start=head1;
                    break;
                }
                else
                {
                    last=start;
                    while(last->next!=NULL)
                        last=last->next;
                    last->next=head1;
                }
                break;
            }
            else if(head2!=NULL&&head1==NULL)
            {
                if(start==NULL)
                {
                    start=head2;
                    break;
                }
                else
                {
                    last=start;
                    while(last->next!=NULL)
                        last=last->next;
                    last->next=head2;
                }
                break;
            }
        }
        printf("\nMerged successfully\nIf you have to see press 6");
    }
}

void displaymergelist()
{
    if(start==NULL)
        printf("\nList is Empty\n");
    else
    {
        temp=start;
        printf("The elements are:  ");
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp!=NULL);
    }
}

void reverse()
{
    if(head1==NULL)
        printf("\nList is Empty");
    else
    {
        struct node* curr;
        curr=head1;
        while(curr->next!=NULL)
        {
            temp=curr->next;
            curr->next=temp->next;
            temp->next=head1;
            head1=temp;
        }
        curr=head2;
        while(curr->next!=NULL)
        {
            temp=curr->next;
            curr->next=temp->next;
            temp->next=head1;
            head1=temp;
        }
    }
}

