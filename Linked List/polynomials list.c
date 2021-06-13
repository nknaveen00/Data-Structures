
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int pow;
    struct node* next;
}*head1,*head2,*head3;

struct node* insert(struct node*);
void display(struct node*);
void sum();
struct node*reverse(struct node*);
void insertvalue(int);

void main()
{
    int ch;
    printf("\t\t\t***\tDelete node which have greater element on it's right side\t***");
    do
    {
        printf("\n1. INSERT LIST 1");
        printf("\n2. INSERT LIST 2");
        printf("\n3. DISPLAY LIST 1");
        printf("\n4. DISPLAY LIST 2");
        printf("\n5. SUM");
        printf("\n6. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head1=insert(head1);
                    break;
            case 2: head2=insert(head2);
                    break;
            case 3: display(head1);
                    break;
            case 4: display(head2);
                    break;
            case 5: sum();
                    break;
            case 6: exit(1);

            default: printf("\nEnter valid option");
        }
    }while(ch<=4);
}

struct node* insert(struct node* start)
{
    int item,power;
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    printf("\nEnter the power value: ");
    scanf("%d",&power);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->data=power;
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
        printf("\nThe elements are\n");
        while(temp!=NULL)
        {
            printf("\n| %dx^ | %d |  |---->",temp->data,temp->pow);
            temp=temp->next;
        }
    }
}

void sum()
{
    if((head1==NULL)&&(head2==NULL))
        printf("\nList is Empty");
    else
    {
        if((head1==NULL)&&(head2!=NULL))
        {
            head3=head2;
        }
        else if((head1!=NULL)&&(head2==NULL))
        {
            head3=head1;
        }
        else
        {
            head1=reverse(head1);
            head2=reverse(head2);
            struct node* temp1=head1;
            struct node* temp2=head2;
            int carry=0,res;
            while(temp1!=NULL||temp2!=NULL)
            {
                if(temp1!=NULL&&temp2==NULL)
                {
                    res=temp1->data;
                    insertvalue(res);
                    temp1=temp1->next;
                }
                else if(temp2!=NULL&&temp1==NULL)
                {
                    res=temp2->data;
                    insertvalue(res);
                    temp2=temp2->next;
                }
                else if(temp1!=NULL&&temp2!=NULL)
                {
                    res=temp1->data + temp2->data;
                    insertvalue(res);
                    temp1=temp1->next;
                    temp2=temp2->next;
                }
            }
            if(carry>=1)
                insertvalue(carry);

            head1=reverse(head1);
            head2=reverse(head2);
            printf("\nList 1");
            display(head1);
            printf("\nList 2");
            display(head2);
            printf("\nResultant List");
            display(head3);

        }

    }
}
void insertvalue(int info)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=info;
    newnode->next=head3;
    if(head3==NULL)
    {
        head3=newnode;
    }
    else
    {
        newnode->next=head3;
        head3=newnode;
    }
}

struct node* reverse(struct node* start)
{
    if(start!=NULL)
    {
        struct node* curr=start;
        struct node* temp=NULL;
        while(curr->next!=NULL)
        {
            temp=curr->next;
            curr->next=temp->next;
            temp->next=start;
            start=temp;
        }
    }
    return start;
}


