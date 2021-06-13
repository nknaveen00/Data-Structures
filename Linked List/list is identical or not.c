#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert_list(struct node*);
void display(struct node*);
void identical(struct node*, struct node*);
int getcount(struct node*);

void main()
{
    int ch;
    struct node* head1=NULL;
    struct node* head2=NULL;
    printf("\t\t\t\t*\tCheck whether the list is identical or not\t***");
    do
    {
        printf("\n1. Insert List 1");
        printf("\n2. Insert List 2");
        printf("\n3. Display List 1");
        printf("\n4. Display List 2");
        printf("\n5. Identical");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head1=insert_list(head1);
                    break;
            case 2: head2=insert_list(head2);
                    break;
            case 3: display(head1);
                    break;
            case 4: display(head2);
                    break;
            case 5: identical(head1, head2);
                    break;
            case 6: exit(1);

            default: printf("\nEnter valid option");
        }
    }while(ch<=6);
}

struct node* insert_list(struct node* head)
{
    int item;
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        printf("\nData inserted successfully");
        return head;
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        printf("\nData inserted successfully");
        return head;
    }
}

void display(struct node* head)
{
    if(head==NULL)
        printf("\nList is Empty");
    else
    {
        struct node* temp=head;
        printf("\nThe list elements are:  ");
        do
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }while(temp!=NULL);
    }
}

int getcount(struct node* head)
{
    int count=0;
    do
    {
        count++;
        head=head->next;
    }while(head!=NULL);
    printf("\nList count is = %d",count);
    return count;
}

void identical(struct node* start1, struct node* start2)
{
    int count=0;
    if((start1==NULL)&&(start2==NULL))
        printf("\nList is Empty");
    else
    {
        int list1_count,list2_count;
        list1_count=getcount(start1);
        list2_count=getcount(start2);

        if(list1_count==list2_count)
        {
            struct node* temp1=start1;
            struct node* temp2=start2;
            while(temp1!=NULL&&temp2!=NULL)
            {
                if(temp1->data==temp2->data)
                {
                    count++;
                }
                else
                    break;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            if(count==list1_count)
                printf("\nThe two lists are identical");
            else
                printf("\nThe two lists are not identical");
        }
        else
            printf("\nThe two lists are not identical");
    }
}
