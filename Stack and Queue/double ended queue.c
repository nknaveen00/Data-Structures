#include<stdio.h>
#include<stdlib.h>

void enqueuerear();
void enqueuefront();
void dequeuerear();
void dequeuefront();
void getrear();
void getfront();
void display();

int n;
void main()
{
    int choice;
    printf("\t\t\t\t***\tDouble Ended Queue\t***");
    printf("\nEnter the size of the queue:");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1. Enqueue using Rear");
        printf("\n2. Enqueue using Front");
        printf("\n3. Dequeue using Rear");
        printf("\n4. Dequeue using Front");
        printf("\n5. Display");
        printf("\n6. Rear element");
        printf("\n7. Front element");
        printf("\n8. Exit");
        printf("\nEnter the your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueuerear();
                    break;
            case 2: enqueuefront();
                    break;
            case 3: dequeuerear();
                    break;
            case 4: dequeuefront();
                    break;
            case 5: display();
                    break;
            case 6: getrear();
                    break;
            case 7: getfront();
                    break;
            case 8: exit(1);
            default: printf("\nEnter valid choice!!!");
        }
    }
}

int queue[30],front=-1,rear=-1,i,item;

void enqueuerear()
{
    if((front==rear+1)||(rear==n-1&&front==0))
        printf("\nQueue is Full");
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        printf("\nEnter the data to insert: ");
        scanf("%d",&item);
        queue[rear]=item;
        printf("\nData inserted successfully");
    }
    else if(rear==n-1)
    {
        rear=0;
        printf("\nEnter the data to insert: ");
        scanf("%d",&item);
        queue[rear]=item;
        printf("\nData inserted successfully");
    }
    else
    {
        printf("\nEnter the data to insert: ");
        scanf("%d",&item);
        rear++;
        queue[rear]=item;
        printf("\nData inserted successfully");
    }
}

void enqueuefront()
{
    if((front==rear+1)||(rear==n-1&&front==0))
        printf("\nQueue is Full");
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        printf("\nEnter the data to insert: ");
        scanf("%d",&item);
        queue[front]=item;
        printf("Data inserted successfully");
    }
    else if(front==0)
    {
        front=n-1;
        printf("\nEnter the element to insert: ");
        scanf("%d",&item);
        queue[front]=item;
        printf("\nData inserted successfully");
    }
    else
    {
        printf("\nEnter the data to insert: ");
        scanf("%d",&item);
        front--;
        queue[front]=item;
        printf("\nData inserted successfully");
    }

}

void dequeuerear()
{
    if(front==-1&&rear==-1)
        printf("\nQueue is Empty");
    else if(front==rear)
    {
        printf("\nThe deleted element is: %",queue[rear]);
        front=rear=-1;
        printf("\nData deleted successfully");
    }
    else if(rear==0)
    {
        printf("\nThe deleted element is: %d",queue[rear]);
        rear=n-1;
        printf("\nData deleted successfully");
    }
    else
    {
        printf("\nThe deleted element is: %d",queue[rear]);
        rear--;
        printf("\nData deleted successfully");
    }
}

void dequeuefront()
{
    if(front==-1&&rear==-1)
        printf("\nQueue is Empty");
    else if(front==n-1)
    {
        printf("\nThe deleted element is: %d",queue[front]);
        front=0;
        printf("\nData deleted successfully");
    }
    else if(front==rear)
    {
        printf("\nThe deleted element is: %d",queue[front]);
        front=rear=-1;
        printf("\nData deleted successfully");
    }
    else
    {
        printf("\nThe deleted element is: %d",queue[front]);
        front++;
        printf("\nData deleted successfully");
    }
}

void display()
{
    if(front==-1&&rear==-1)
        printf("\nQueue is Empty");
    else
    {
        printf("\nThe queue elements are:  ");
        i=front;
        while(i!=rear)
        {
            printf("%d\t",queue[i]);
            i=(i+1)%n;
        }
        printf("%d",queue[rear]);
    }
}

void getfront()
{
    printf("\nThe front element is: %d",queue[front]);
}

void getrear()
{
    printf("\nThe front element is: %d",queue[rear]);
}
