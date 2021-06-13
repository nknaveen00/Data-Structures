#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void getmin();
void display();

int n;
void main()
{
    int choice;
    printf("\t\t\t\t*****Special STACK*****");
    printf("\nEnter the size of the stack: ");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Get Minimun");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: getmin();
                    break;
            case 4: display();
                    break;
            case 5: exit(1);

            default: printf("\nEnter valid option!!!");
        }
    }
}

int stack1[20],stack2[20],top1=-1,top2=-1,i,item,temp;
void push()
{
    if(top1==n-1)
        printf("\nStack is Empty");
    else
    {
        printf("\nEnter the element to insert: ");
        scanf("%d",&item);
        stack1[++top1]=item;
        if(top2==-1)
            stack2[++top2]=item;
        else
        {
            if(item<stack2[top2])
                stack2[++top2]=item;
            else
            {
                temp=stack2[top2];
                top2++;
                stack2[top2]=temp;
            }
        }
    }
}
void pop()
{
    if(top1==-1)
        printf("\nStack is Empty");
    else
    {
        printf("\nThe deleted element is: %d",stack1[top1]);
        top1--;
        top2--;

    }
    printf("\nOne element is deleted successfully");
}

void getmin()
{
    if(top1==-1)
        printf("\nStack is Empty");
    else
        printf("\nThe minimum element is: %d",stack2[top2]);
}

void display()
{
    if(top1==-1)
        printf("\nStack is Empty");
    else
    {
        printf("\nThe STACK elements are: ");
        for(i=top1;i>=0;i--)
            printf("%d\t",stack1[i]);
    }
}
