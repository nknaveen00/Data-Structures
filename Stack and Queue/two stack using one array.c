#include<stdio.h>
#include<stdlib.h>
#define n 10

void push1();
void push2();
void pop1();
void pop2();
void display1();
void display2();


void main()
{
    int choice;
    printf("\t\t\t*****Implementation two stack using one array*****");
    while(1)
    {
        printf("\n1.Push stack one");
        printf("\n2.Push stack two");
        printf("\n3.Pop stack one");
        printf("\n4.Pop stack two");
        printf("\n5.Display stack one");
        printf("\n6.Display stack two");
        printf("\n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push1();
                    break;
            case 2: push2();
                    break;
            case 3: pop1();
                    break;
            case 4: pop2();
                    break;
            case 5: display1();
                    break;
            case 6: display2();
                    break;
            case 7: exit(1);

            default: printf("\nEnter valid option!!!");
        }
    }
}

int stack[50],top1=-1,item,i,top2=n/2;
void push1()
{
    if(top1==n/2)
        printf("\nStack is Full");
    else
    {
        printf("\nEnter the element to insert stack 1: ");
        scanf("%d",&item);
        stack[++top1]=item;
        printf("\nData inserted successfully");
    }
}

void push2()
{
    if(top2==n-1)
        printf("\nStack is Full");
    else
    {
        printf("\nEnter the element to insert stack 2: ");
        scanf("%d",&item);
        stack[++top2]=item;
        printf("\nData inserted successfully");
    }
}

void pop1()
{
    if(top1==-1)
        printf("\nStack is Empty");
    else
    {
        printf("\nThe deleted element is: %d",stack[top1]);
        top1--;
        printf("\nData deleted successfully");
    }
}

void pop2()
{
    if(top2==n/2)
        printf("\nStack Empty");
    else
    {
        printf("\nThe deleted element is: %d",stack[top2]);
        top2--;
        printf("\nData deleted successfully");
    }
}

void display1()
{
    if(top1==-1)
        printf("\nStack is Empty");
    else
    {
        printf("\nThe stack elements are: ");
        for(i=top1;i>=0;i--)
            printf("%d\t",stack[i]);
    }
}
void display2()
{
    if(top2==n/2)
        printf("\nStack is Empty");
    else
    {
        printf("\nThe stack elements are: ");
        for(i=top2;i>n/2;i--)
            printf("%d\t",stack[i]);
    }
}
