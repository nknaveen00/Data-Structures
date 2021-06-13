#include<stdio.h>
#include<stdlib.h>


int n;
int stack[20],top=-1,i,item;

void push();
void pop();
void display();
void reverse(int);

void main()
{
    int choice;
    printf("\t\t\t\t*****Stack reverse using Recursion*****");
    printf("\nEnter stack size: ");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Reverse\n4.display\n5.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push();
                    break;

            case 2: pop();
                    break;

            case 3: if(top==-1)
                        printf("\nStack is Empty");
                    else
                    {
                        printf("\nThe reverse elements of stack: ");
                        reverse(top);
                    }
                    break;

            case 4: display();
                    break;

            case 5: exit(1);

            default: printf("\nEnter valid option!!!");
        }
    }
}


void push()
{
    if(top==n-1)
        printf("\nStack is Full");
    else
    {
        printf("\nEnter the element to insert: ");
        scanf("%d",&item);
        stack[++top]=item;
        printf("\nData inserted successfully");
    }
}

void pop()
{
    if(top==-1)
        printf("\nStack is Empty");
    else
    {
        printf("\nThe deleted element is: %d",stack[top]);
        top--;
        printf("\nData deleted successfully");
    }
}

void reverse(int rev)
{
    if(rev!=-1)
    {
        printf("%d\t",stack[rev]);
        reverse(--rev);
    }
}

void display()
{
    if(top==-1)
        printf("\nStack is Empty");
    else
    {
        printf("\nThe stack elements are: ");
        for(i=top;i>=0;i--)
            printf("%d\t",stack[i]);
    }
}
