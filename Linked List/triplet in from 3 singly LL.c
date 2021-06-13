#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
void triplet(struct node*,struct node*,struct node*);

void main()
{
    int ch;
    struct node* list1=NULL;
    struct node* list2=NULL;
    struct node* list3=NULL;
    printf("\t\t\t\t***\tTriplet value of three linked list");
    do
    {
        printf("\n1. INSERT LIST 1");
        printf("\n2. INSERT LIST 2");
        printf("\n3. INSERT LIST 3");
        printf("\n4. DISPLAY LIST 1");
        printf("\n5. DISPLAY LIST 2");
        printf("\n6. DISPLAY LIST 3");
        printf("\n7. TRIPLET VALUE");
        printf("\nTO EXIT PRESS EXCEPT 1 - 7");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: list1=insert(list1);
                    break;
            case 2: list2=insert(list2);
                    break;
            case 3: list3=insert(list3);
                    break;
            case 4: display(list1);
                    break;
            case 5: display(list2);
                    break;
            case 6: display(list3);
                    break;
            case 7: triplet(list1, list2, list3);
                    break;
        }
    }while(ch<8);
}

struct node* insert(struct node* head)
{
    int item;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    newnode->data=item;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
    return head;
}

void display(struct node* head)
{
    if(head==NULL)
        printf("\nList is Empty\n\n");
    else
    {
        printf("\nThe list elements are:  ");
        struct node* temp=head;
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
}

void triplet(struct node* head1, struct node* head2, struct node* head3)
{
    if(head1==NULL&&head2==NULL&&head3==NULL)
        printf("\nList is Empty\n\n");
    else
    {
        int sum=0,t,l1,l2,l3;
        l1=getcount(head1);
        l2=getcount(head2);
        l3=getcount(head3);
        if(l1==l2&&l2==l3)
        {
            printf("\nEnter the triplet value:  ");
            scanf("%d",&t);
            struct node* temp1=head1;
            struct node* temp2=head2;
            struct node* temp3=head3;
            while(temp1!=NULL)
            {
                temp2=head2;
                while(temp2!=NULL)
                {
                    temp3=head3;
                    while(temp3!=NULL)
                    {
                        sum=temp1->data + temp2->data + temp3->data;
                        if(sum==t)
                        {
                            sum=0;
                            printf("\nThe triplet elements are:  %d  %d  %d",temp1->data, temp2->data, temp3->data);
                            break;
                        }
                        else
                        temp3=temp3->next;
                    }
                    if(sum==0)
                        break;
                    else
                        temp2=temp2->next;
                }
                if(sum==0)
                    break;
                else
                    temp1=temp1->next;
            }
            if(sum!=0)
                printf("\nThere is no this triplet value");
        }
        else
            printf("\nCan't find triplet value");
    }
}

struct node* getcount(struct node*)
{
    int count=0;
    struct node* temp;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}


/*
2nd loop

 if(sum==0&&temp3==NULL)
                {
                    sum=temp1->data + temp2->data;
                    if(sum==t)
                    {
                        printf("\nThe Triplet value is:  %d  %d",temp1->data, temp2->data);
                        break;
                    }
                    else
                        sum=0;
                }
                else
                {
                    temp2=temp2->next;
                    break;
*/


/*

3rd loop
if(sum==0)
                printf("\nThere is no triplet value\n\n");
            else
            {
                temp1=temp1->next;
            }
*/
