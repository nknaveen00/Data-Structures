#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
struct node* delnode(struct node*,int);
struct node* removeeach(struct node*, int);
void main()
{
    struct node* head=NULL;
    int ch,k;
    printf("\t\t\t***\tDelete node which have greater element on it's right side\t***");
    do
    {
        printf("\n1. INSERT");
        printf("\n2. DISPLAY");
        printf("\n3. DELETE");
        printf("\n4. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=insert(head);
                    break;
            case 2: display(head);
                    break;
            case 3: printf("\nEnter the data to delete: ");
                    scanf("%d",&k);
                    head=delnode(head,k);
                    break;

            default: printf("\nEnter valid option");
        }
    }while(ch<=3);
}

struct node* insert(struct node* start)
{
    int item;
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
        printf("\nData inserted successfully\n");
    }
    else
    {
        struct node* temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        printf("\nData inserted successfully\n");
    }
    return start;
}

void display(struct node* start)
{
    if(start==NULL)
        printf("\nList is Empty\n");
    else
    {
        struct node* temp=start;
        printf("\nThe elements are:  ");
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
}
struct node* delnode(struct node* start, int k)
{
    if(start==NULL)
        printf("\nList is Empty\n");
    else
    {
        int sum=0;
        start=removeeach(start,k);
        struct node* prev=start;
        struct node* curr=start;
        struct node* temp=start;
        while(temp!=NULL)
        {
            if(temp->data<k)
            {
                sum=temp->data;
                prev=temp;
                curr=temp->next;
                while(sum!=k&&sum<k&&curr!=NULL)
                {
                    sum=sum+curr->data;
                    curr=curr->next;
                }
                while(temp!=curr&&sum==k)
                {
                    if(temp==start)
                    {
                        temp=temp->next;
                        start=temp;
                        free(prev);
                        prev=temp;
                    }
                    else
                    {
                        struct node* temp1=start;
                        while(temp1->next!=temp)
                            temp1=temp1->next;
                        temp1->next=temp->next;
                        free(temp);
                        temp=temp1->next;
                    }
                }
                if(curr==NULL&&sum!=k)
                    temp=temp->next;
            }
            else
                temp=temp->next;
        }
    }
    return start;
}

struct node* removeeach(struct node* start, int k)
{
    struct node* prev=start;
    struct node* curr=start;
    while(curr!=NULL)
    {
        if(curr->data==k)
        {
            if(curr==start)
            {
                start=curr->next;
                free(curr);
                curr=start;
                prev=curr;
            }
            else
            {
                prev->next=curr->next;
                free(curr);
                curr=prev->next;
            }
        }
        else if(curr->data>k||curr->data<k)
        {
            prev=curr;
            curr=curr->next;
        }
    }
    return start;
}

/*struct node* delnode(struct node* start, int k)
{
    if(start==NULL)
        printf("\nList is Empty");
    else
    {
        int sum=0;
        struct node* temp=start;
        struct node* prev=NULL;
        struct node* del=NULL;
        while(temp!=NULL)
        {
            if(temp->data==k)
            {
                if(start==temp)
                {
                    start=temp->next;
                    free(temp);
                    temp=start;
                    printf("*1*");
                }
                else
                {
                    prev->next=temp->next;
                    free(temp);
                    temp=prev->next;
                    printf("*2*");
                }
            }
            else if(temp->data>k||temp->data<=0)
                prev=temp;
            else
            {
                del=temp;
                do
                {
                    sum=sum+del->data;
                    del=del->next;
                    printf("*3*");
                }while(sum!=k&&sum<k&&del!=NULL);
            }
                sum=0;
            }
            display(start);
            printf("*6*");
            prev=temp;
            temp=temp->next;
        }
    return start;
}

*/



/*

                del=temp;
                do
                {
                    sum=sum+del->data;
                    del=del->next;
                    printf("*3*");
                }while(sum!=k&&sum<k&&del!=NULL);
                    if(temp==start)
                        start=del;
                    else
                        prev->next=del->next;
                if(sum==k)
                {
                    printf("*4*");
                    struct node* temp1=temp;
                    while(temp!=del)
                    {
                        printf("*5*");
                        temp1=temp;
                        temp=temp->next;
                        printf("\\*%d\\*",temp1->data);
                        free(temp1);
                    }
                }

                */
