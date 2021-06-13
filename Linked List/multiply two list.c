#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert(struct node*);
void display(struct node*);
void multiply(struct node*,struct node*);


int count=0;

void main()
{
    system("color 5f");
    struct node* list1=NULL;
    struct node* list2=NULL;
    int choice;
    do
    {
        printf("\n1. INSERT LIST 1");
        printf("\n2. INSERT LIST 2");
        printf("\n3. DISPLAY LIST 1");
        printf("\n4. DISPLAY LIST 2");
        printf("\n5. MULTIPLY");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: list1=insert(list1);
                    break;
            case 2: list2=insert(list2);
                    break;
            case 3: display(list1);
                    break;
            case 4: display(list2);
                    break;
            case 5: multiply(list1,list2);
                    break;
        }
    }while(choice>0&&choice<=5);

}

struct node* insert(struct node* head)
{
    int item;
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    count++;
    if(head==NULL)
    {
        head=newnode;
        printf("\nData inserted successfully\n");
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        printf("\nData inserted successfully\n");
    }
    return head;
}

void display(struct node* head)
{
    if(head==NULL)
        printf("\nList is Empty\n");
    else
    {
        struct node* temp=head;
        printf("\nThe list elements are:  ");
        do
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }while(temp!=NULL);
        printf("\n");
    }
}

void multiply(struct node* list1, struct node* list2)
{
    if(list1==NULL&&list2==NULL)
        printf("\nList is Empty");
    else
    {
        long long n= 1000000007;
        long long num1 = 0, num2 = 0;
        while (list1!=NULL || list2!=NULL)
        {
            if(list1!=NULL){
                num1 = ((num1)*10)%n+list1->data;
                list1 = list1->next;
            }

            if(list2)
            {
                num2 = ((num2)*10)%n + list2->data;
                list2 = list2->next;
            }
        }
        printf("The multiplication of two lists are: %d",((num1%n)*(num2%n))%n);
    }
}
