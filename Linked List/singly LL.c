#include<stdio.h>
#include<stdlib.h>



struct node
{
    int data;
    struct node *link;
}*head,*newnode,*temp,*temp1;
struct node *head=NULL;

void insertAtfirst();
void insertAtmiddle();
void insertAtend();
void display();
int length();
void deleteAtFirst();
void deleteAtMid();
void deleteAtEnd();


int item,pos,choice;
int main()
{
    printf("\t\t\t\t\t\tSingly Linked List\n");
    while(1)
    {
    printf("\n1.Insert At First\n2.Insert At Middle\n3.Insert At Last\n4.Display\n5.Delete At First\n6.Delete At Middle\n7.Delete At End\n8.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insertAtfirst();
               break;
        case 2:insertAtmiddle();
                break;
        case 3:insertAtend();
                break;
        case 4:display();
                break;
        case 5:deleteAtFirst();
                break;
        case 6:deleteAtMid();
                break;
        case 7:deleteAtEnd();
                break;
        case 8:exit(1);

        default:printf("\nEnter valid choice!!!\n");
                break;
    }
}

}

void insertAtfirst()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to insert: ");
    scanf("%d",&item);
    if(head!=NULL)
    {
        newnode->data=item;
        newnode->link=head;
        head=newnode;
        printf("\nData inserted successfully!\n");
    }
    else
    {
        newnode->data=item;
        newnode->link=NULL;
        head=newnode;
        printf("\nData inserted successfully!\n");
    }
}
void insertAtmiddle()
{
    int i=1;
    if(head==NULL)
    {
        printf("\nList is Empty!!!\n");
    }
    else //if(head->next!=NULL)
    {
        int count=length();
        printf("\nEnter the position to insert: ");
        scanf("%d",&pos);
        if(pos<=count)
        {
            int i=1;
            temp=head;
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter the element to insert: ");
            scanf("%d",&item);
            newnode->data=item;
            newnode->link=NULL;
            while(i<pos-1)
            {
                temp=temp->link;
                i++;
            }
            newnode->link=temp->link;
            temp->link=newnode;
            printf("\nData inserted Successfully!");
        }
        else
            printf("\nEnter Valid Position");
    }
}
void insertAtend()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
        printf("\nList is Empty!!!\n");
    else
    {
        printf("\nEnter the element to insert: ");
        scanf("%d",&item);
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
    return count;
}

void deleteAtFirst()
{
    if(head!=NULL)
    {
        temp=head;
        printf("\nThe deleted element is %d",temp->data);
        head=temp->link;
        free(temp);
        printf("\nThe element is deleted successfully!!!");
    }
    else if(head->link==NULL)
   {
       printf("\nThe deleted element is %d",head->data);
       free(head);
       head=NULL;
   }
   else
        printf("\nThe List is Empty");
}
void deleteAtMid()
{

    if(head!=NULL)
    {
        int count=length();
        printf("\nEnter the position to delete\t");
        scanf("%d",&pos);
        if(pos<=count)
        {
        int i=1;
        struct node *temp1;
        temp=temp1=head;
        while(i<pos)
        {
            temp1=temp;
            temp=temp->link;
            i++;
        }
        printf("\nThe deleted element is %d",temp->data);
        temp1->link=temp->link;
        free(temp);
        temp=NULL;
        printf("\nThe element is deleted successfully!!!");
        }
        else
            printf("\nEnter Valid Position");
    }
    else if(head->link==NULL)
        printf("\nThere is one element in the list");
    else
        printf("\nThe List is Empty");


}
void deleteAtEnd()
{
   if(head!=NULL)
   {
        temp=head;
        temp1=head;

        while(temp->link!=NULL)
        {
            temp1=temp;
            temp=temp->link;
        }
        printf("\nThe Deleted element is %d",temp->data);
        temp1->link=NULL;
        free(temp);
        printf("\nThe Last element is deleted successfully");
   }
   else if(head->link==NULL)
   {
       printf("\nThe deleted element is %d",head->data);
       free(head);
       head=NULL;
   }
   else
    printf("\nThe List is Empty");
}





