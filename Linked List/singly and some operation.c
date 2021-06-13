#include<stdio.h>
#include<stdlib.h>



struct node
{
    int data;
    struct node *link;
}*head,*newnode,*temp,*temp1;
struct node *head=NULL;

void insert();
void display();
int length();
void deletele();
void getmin();
void removeduplicatesort();
void removeduplicatesunsort();
void deleteall();
void swap(int,int);
void swappair();
void pairs(int*,int*);
void lastnodetofirst();


int item,pos,choice,min;
int main()
{
    int x,y;
    printf("\t\t\t***\tSingly Linked List and Some operations\t***\n");
    printf("\nNote: You want to remove duplicates you must enter data in sorted order");
    while(1)
    {
    printf("\n1.Insert");
    printf("\n2.Display");
    printf("\n3.Delete");
    printf("\n4.Get Minimum");
    printf("\n5.Remove Duplicates from Sorted");
    printf("\n6.Remove Duplicates from unsorted");
    printf("\n7.Delete all");
    printf("\n8.Swap two Data");
    printf("\n9.Swap pair wise");
    printf("\n10.Move last node to First");
    printf("\n11.exit");
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
        case 4:getmin();
                break;
        case 5:removeduplicatesort();
                break;
        case 6:removeduplicatesunsort();
                break;
        case 7:deleteall();
                break;
        case 8: printf("\nEnter the value of x: ");
                scanf("%d",&x);
                printf("\nEnter the value of y: ");
                scanf("%d",&y);
                swap(x,y);
                break;
        case 9:swappair();
                break;
        case 10:lastnodetofirst();
                break;
        case 11:exit(1);

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
        newnode->link=NULL;
        head=newnode;
        printf("\nData inserted successfully");
    }
    else
    {
        newnode->data=item;
        newnode->link=NULL;
        temp=head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=newnode;
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
            temp=temp->link;
        }while(temp!=NULL);
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
            temp=temp->link;
        }
    }
    else
        printf("\nList is Empty");
    return count;
}

void deletele()
{
    if(head==NULL)
        printf("\nList is Empty");
    else if(head->link==NULL)
    {
        printf("\nThe deleted element is %d",head->data);
        head=NULL;
    }
    else
   {
       temp=temp1=head;
       while(temp->link!=NULL)
        {
            temp1=temp;
            temp=temp->link;
        }
       printf("\nThe Deleted element is %d",temp->data);
       temp1->link=NULL;
       free(temp);
       printf("\nData is deleted successfully");
   }
}

void getmin()
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        min=head->data;
        temp=head->link;
        do
        {
            if(temp->data<min)
                min=temp->data;
            temp=temp->link;
        }while(temp!=NULL);
        printf("\nThe minimum element is: %d",min);
    }

}

void removeduplicatesort()
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        temp1=head;
        temp=head->link;
        do
        {
            if(temp->data==temp1->data)
            {
                temp1->link=temp->link;
                free(temp);
                temp=temp1->link;
            }
            else
            {
                temp1=temp;
                temp=temp->link;
            }

        }while(temp!=NULL);
        printf("\nDuplicate data's removed successfully from sorted array");

    }
}

void deleteall()
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        do
        {
            temp=head;
            head=head->link;
            free(temp);
        }while(head!=NULL);
        printf("\nAll List elements are deleted successfully");
        free(head);
    }
}

void removeduplicatesunsort()
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        struct node *temp2;
        temp=head;
        do
        {
            temp1=temp;
            temp2=temp->link;
            do
            {
                if(temp2->data==temp->data)
                {
                    temp1->link=temp2->link;
                    free(temp2);
                    temp2=temp1->link;
                }
                else
                {
                    temp1=temp2;
                    temp2=temp2->link;
                }

            }while(temp2!=NULL);
            temp=temp->link;
        }while(temp->link!=NULL);
        printf("\nDuplicate data's removed successfully from unsorted array");
    }
}

void swap(int x,int y)
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        if(x==y)
            printf("\nx and y value is same. So couldn't swap");
        else
        {
            temp=temp1=head;
            while(temp->data!=x&&temp!=NULL)
                temp=temp->link;
            while(temp1->data!=y&&temp!=NULL)
                temp1=temp1->link;
            if(temp->data==x&&temp1->data==y)
            {
                /*struct node* temp2;
                temp2=temp->data;
                temp->data=temp1->data;
                temp1->data=temp2;*/
                pairs(&temp->data,&temp1->data);
                printf("\nData swapped successfully");
            }
            else
                printf("\nEnter correct data");
        }
    }
}

void swappair()
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        temp=head;
        while (temp != NULL && temp->link != NULL)
        {
            pairs(&temp->data,&temp->link->data);
            temp=temp->link->link;
        }
        printf("\nAll pair of data swapped successfully");
    }
}

void pairs(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

void lastnodetofirst()
{
    if(head==NULL)
        printf("\nList is Empty");
    else if(head->link==NULL)
        printf("\nThere is one node. Can't move node");
    else
    {
        temp=temp1=head;
        while(temp->link!=NULL)
        {
            temp1=temp;
            temp=temp->link;
        }
        temp1->link=NULL;
        temp->link=head;
        head=temp;
        printf("\nNode moved successfully");
    }
}
