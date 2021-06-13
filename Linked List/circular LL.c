#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*newnode,*temp,*head=NULL;

void insertfirst();
void insertmid();
void insertlast();
void display();
int length();
void deletefirst();
void deletemid();
void deletelast();


int main()
{
    printf("\t\t\t\t\t\tCircular Linked List\n");
    int choice;
    while(1)
    {
        printf("\n1.Insert First");
        printf("\n2.Insert Middle");
        printf("\n3.Insert Last");
        printf("\n4.Display");
        printf("\n5.Delete First");
        printf("\n6.Delete Middle");
        printf("\n7.Delete End");
        printf("\n8.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertfirst();
                    break;
            case 2: insertmid();
                    break;
            case 3: insertlast();
                    break;
            case 4: display();
                    break;
            case 5: deletefirst();
                    break;
            case 6: deletemid();
                    break;
            case 7: deletelast();
                    break;
            case 8: exit(1);

            default: printf("\n!!!Enter Valid Choice!!!\n");
        }
    }
}

int item,pos;

void insertfirst()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    temp=head;
    newnode->data=item;
    if(head==NULL)
    {
        newnode->next=newnode;
        head=newnode;
        printf("\nData inserted successfully\n");
    }
    else
    {
        newnode->next=head;
        while(temp->next!=head)
            temp=temp->next;
        head=newnode;
        temp->next=newnode;
        printf("\nData inserted successfully\n");
    }
}


void insertmid()
{
    if(head==NULL)
        printf("\nList is Empty\n");
    else if(head->next==head)
        printf("\nThere is one element in list\n");
    else
    {
        int i=1;
        int count=length();
        printf("\nEnter the position to insert: ");
        scanf("%d",&pos);
        if(pos<=count)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter the element to insert: ");
            scanf("%d",&item);
            temp=head;
            newnode->data=item;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            printf("\nData inserted successfully\n");
        }
        else
            printf("\nEnter valid position to insert!!!\n");
    }
}

int length()
{
    int count=0;
    temp=head;
    do
    {
        count++;
        temp=temp->next;
    }while(temp!=head);
    return count;
}

void insertlast()
{
    if(head==NULL)
        printf("\nlist is Empty\n");
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the element to insert: ");
        scanf("%d",&item);
        temp=head;
        while(temp->next!=head)
            temp=temp->next;
        newnode->data=item;
        newnode->next=head;
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
        printf("\nThe List elements are:");
        do
        {
            printf("\t%d",temp->data);
            temp=temp->next;
        }while(temp!=head);
    }
    printf("\n");
}

void deletefirst()
{
    if(head==NULL)
        printf("\nList is Empty!!!\n");
    else
    {
        if(head->next==head)
        {
            printf("\nThe deleted element is %d",head->data);
            free(head);
            head=NULL;
            printf("\nThe element is deleted successfully\n");
        }
        else
        {
            struct node *temp1=temp=head;
            printf("\nThe deleted element is %d",temp->data);
            while(temp1->next!=head)
                temp1=temp1->next;
            head=temp->next;
            free(temp);
            temp=NULL;
            temp1->next=head;
            printf("\nThe element is deleted successfully\n");
        }

    }
}

void deletemid()
{
    if(head==NULL)
        printf("\nList is Empty\n");
    else if(head->next==head)
        printf("\nThere is one element in the list");
    else
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
            temp=temp->next;
            i++;
        }
        printf("\nThe deleted element is %d",temp->data);
        temp1->next=temp->next;
        free(temp);
        temp=NULL;
        printf("\nThe element is deleted successfully!!!");
        }
        else
            printf("\nEnter Valid Position");
    }

}
void deletelast()
{
    if(head==NULL)
        printf("\nList is Empty\n");
    else
    {
        struct node *temp1=temp=head;
        while(temp->next!=head)
        {
            temp1=temp;
            temp=temp->next;
        }
        printf("\nThe deleted element is %d",temp->data);
        temp1->next=head;
        free(temp);
        temp=NULL;
        printf("\nThe element is deleted successfully\n");
    }

}
