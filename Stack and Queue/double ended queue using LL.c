#include<stdio.h>
#include<stdlib.h>

void enqueuerear();
void enqueuefront();
void dequeuerear();
void dequeuefront();
void display();
void getrear();
void getfront();
void erase();
void getcount();
int isEmpty();

struct node
{
    int data;
    struct node* next;
    struct node* prev;
}*newnode,*temp;
 struct node *front=NULL;
 struct node *rear=NULL;

void main()
{
    int choice;
    printf("\t\t\t\t***\tDouble Ended Queue Using Linked List\t***");
    while(1)
    {
        printf("\n1. Enqueue Rear");
        printf("\n2. Enqueue Front");
        printf("\n3. Dequeue Rear");
        printf("\n4. Dequeue Front");
        printf("\n5. Display");
        printf("\n6. Rear Element");
        printf("\n7. Front Element");
        printf("\n8. Count");
        printf("\n9. Erase all element");
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueuerear();
                    break;
            case 2: enqueuefront();
                    break;
            case 3: dequeuerear();
                    break;
            case 4:dequeuefront();
                    break;
            case 5: display();
                    break;
            case 6: getrear();
                    break;
            case 7: getfront();
                    break;
            case 8: getcount();
                    break;
            case 9: erase();
                    break;
            case 10: exit(1);

            default: printf("\nEnter valid option!!!");
        }
    }

}

int count=0,item;

int isEmpty()
{
    if(front==NULL&&front==NULL)
        return 1;
    else
        return 0;
}

void enqueuerear()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    if(isEmpty())
    {
        front=rear=newnode;
        newnode->data=item;
        newnode->next=newnode;
        newnode->prev=newnode;
        count++;
        printf("\nData inserted successfully");
    }
    else
    {
        newnode->data=item;
        rear->next=newnode;
        newnode->prev=rear;
        newnode->next=front;
        front->prev=newnode;
        rear=newnode;
        count++;
        printf("\nData inserted successfully");
    }
}

void enqueuefront()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert: ");
    scanf("%d",&item);
    if(isEmpty())
    {
        front=rear=newnode;
        newnode->data=item;
        newnode->next=newnode;
        newnode->prev=newnode;
        front=rear=newnode;
        count++;
        printf("\nData inserted successfully");
    }
    else
    {
        newnode->data=item;
        front->prev=newnode;
        rear->next=newnode;
        newnode->next=front;
        newnode->prev=front->prev;
        front=newnode;
        count++;
        printf("\nData inserted successfully");
    }
}
void dequeuerear()
{
    if(isEmpty())
        printf("\nQueue is Empty");
    else
    {
        temp=rear;
        rear=rear->prev;
        rear->next=front;
        front->prev=rear;
        printf("The deleted element is: %d",temp->data);
        free(temp);
        count--;
    }
}

void dequeuefront()
{
    if(isEmpty())
        printf("\nQueue is Empty");
    else
    {
        temp=front;
        front=front->next;
        front->prev=rear;
        rear->next=front;
        printf("\nThe deleted element is: %d",temp->data);
        free(temp);
        count--;
    }
}

void display()
{
    temp=front;
    printf("\nThe queue elements are:  ");
    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp->next!=front);
    printf("%d",rear->data);
}

void getrear()
{
    if(isEmpty())
        printf("\nQueue is Empty");
    else
        printf("\nThe rear element is: %d",rear->data);
}

void getfront()
{
    if(isEmpty())
        printf("\nQueue is Empty");
    else
        printf("\nThe front element is: %d",front->data);
}

void erase()
{
    if(isEmpty())
        printf("\nQueue is Empty");
    else
    {
        int yn;
        printf("\nAre you want to erase all element\nIf yes press 1 otherwise 0: ");
        scanf("%d",&yn);
        if(yn==1)
        {
            printf("\nThe elements are deleted:  ");
            while(front!=rear)
            {
                temp=front;
                front=front->next;
                printf("\n%d\t",temp->data);
                free(temp);
                count--;
            }
            free(front);
            free(rear);
        }
    }
}

void getcount()
{
    if(isEmpty())
        printf("\nQueue is Empty");
    else
        printf("\nThere is %d elements in the Queue",count);
}
