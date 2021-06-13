#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*other,*first,*head=NULL;

void createnode();
void display();

int main()
{
    int n;
    printf("\t\t\t\tCreating node and display");
    printf("\nNumber of node to create\n");
    scanf("%d",&n);
    createnode(n);
    display();
    return 0;
}

void createnode(int n)
{
    int item;
    first=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter element 1: ");
    scanf("%d",&item);
    first->data=item;
    first->next=NULL;
    head=first;
    printf("1st element is inserted successfully");

    for(int i=2;i<=n;i++)
    {
        other=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter element %d: ",i);
        scanf("%d",&item);
        other->data=item;
        other->next=NULL;

        head->next=other;
        head=head->next;
        printf("%dth element is inserted successfully",i);
    }
}

void display()
{
    printf("\nThe List elements are: ");
    head=first;
    do
    {
        printf("%d\t",head->data);
        head=head->next;
    }while(head!=NULL);
}
