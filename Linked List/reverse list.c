#include<stdio.h>
#include<stdlib.h>



struct node
{
    int data;
    struct node *next;
}*head,*newnode,*temp,*temp1;
struct node *head=NULL;

void insert();
void display();
void reverselist();
void reverse();
void reversekelements();
void reversekgroup();
struct node* reversealtkgroup(struct node*,int);


int item,choice;
int main()
{
    int k;
    printf("\t\t\t***\tSingly Linked List and Some operations\t***\n");
    printf("\nNote: You want to remove duplicates you must enter data in sorted order");
    while(1)
    {
    printf("\n1.Insert");
    printf("\n2.Display");
    printf("\n3.Reverse List using 3 Pointer");
    printf("\n4.Reverse List using 2 Pointer");
    printf("\n5.Reverse k elements in List");
    printf("\n6.Reverse k group in List");
    printf("\n7.Reverse alternate k group in List");
    printf("\n8.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insert();
               break;
        case 2:display();
                break;
        case 3:reverselist();
                break;
        case 4:reverse();
                break;
        case 5: reversekelements();
                break;
        case 6:reversekgroup();
                break;
        case 7:printf("\nEnter the k value: ");
                scanf("%d",&k);
                reversealtkgroup(head,k);
                break;
        case 8: exit(1);

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

void reverselist()
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        struct node* prev=NULL;
        temp=head;
        while(temp!=NULL)
        {
            temp1=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp1;
        }
        head=prev;
        printf("\nData reversed successfully\nIf you want to see reversed list press 2");
    }
}

void reverse()
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        struct node* curr=head;
        while(curr->next!=NULL)
        {
            temp=curr->next;
            curr->next=temp->next;
            temp->next=head;
            head=temp;
        }
        printf("\nData reversed successfully\nIf you want to see reversed list press 2");
    }
}

void reversekelements()
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        int k,i;
        printf("\nEnter the value of k: ");
        scanf("%d",&k);
        struct node *prev=NULL;
        struct node *kth=head;
        i=1;
        while(i<k)
        {
            kth=kth->next;
            i++;
        }
        temp=head;
        prev=kth->next;
        i=1;
        while(i<=k)
        {
            temp1=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp1;
            i++;
        }
        head=prev;
        printf("\nData reversed successfully\nIf you want to see reversed list press 2");
    }
}

void reversekgroup()
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        int k,count,top=-1,stack[20];
        printf("\nEnter the k value: ");
        scanf("%d",&k);
        struct node *prev=NULL;
        temp=head;
        while(temp!=NULL)
        {
            count=1;
            while(temp!=NULL&&count<=k)
            {
                stack[++top]=temp;
                temp=temp->next;
                count++;
            }
            while(top>=0)
            {
                if(prev==NULL)
                {
                    prev=stack[top];
                    head=prev;
                    top--;
                }
                else
                {
                    prev->next=stack[top];
                    prev=prev->next;
                    top--;
                }
            }
        }
        prev->next=NULL;
        printf("\nk Group of List is reversed successfully");
    }
}

struct node* reversealtkgroup(struct node* head,int k)
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        struct node* current = head;
        struct node* prev = NULL;
        int count = 0;
        while (current != NULL && count < k)
        {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
            count++;
        }

        if(head != NULL)
            head->next = current;


        count = 0;
        while(count < k-1 && current != NULL )
        {
            current = current->next;
            count++;
        }


        if(current != NULL)
            current->next = reversealtkgroup(current->next, k);


    return prev;
    }
}
