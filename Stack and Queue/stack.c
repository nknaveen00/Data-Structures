#include<stdio.h>

void insert();
void topele();
void display();
void deleete();

int ele;
int top=-1;
int stack[5];

int main()
{
    int choice;
    //scanf("%d",&choice);
    while(1)
    {
    printf("\n1.Insert\n2.Top element\n3.Display\n4.Delete\n5.Exit\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insert();
                break;

        case 2:topele();
                break;

        case 3:display();
                break;

        case 4:deleete();
                break;

        case 5:return(0);
                break;

        default:printf("\nEnter correct option");
    }
    }
    return 0;
}

void insert()
{
    if(top==4)
        printf("\nStack is Full");
    else
    {
        printf("Enter element to insert: ");
        scanf("%d",&ele);
        top++;
        stack[top]=ele;
    }
}

void topele()
{
    if(top==-1)
        printf("\nStack is Empty");
    else
        printf("The top element is: %d",stack[top]);
}

void display()
{
    if(top==-1)
        printf("\nStack is Empty");
    else
    {
        printf("The stack elements are\n");
        for(int i=top;i>=0;i--)
            printf("%d\t",stack[i]);
    }

}

void deleete()
{
    if(top==-1)
        printf("\nStack is Empty");
    else
    {
        printf("The deleted element is: %d",stack[top]);
        top--;
    }
}
