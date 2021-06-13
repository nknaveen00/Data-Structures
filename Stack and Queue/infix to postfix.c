#include<stdio.h>

char infix[50],arr[50],stack[30];
int i=0,top=-1,point=0,opre,spre,ass1,ass2;

int operatorprecedence(char);

void main()
{
    printf("\t\t\t\t*****INFIX to POSTFIX coversion*****");
    printf("\nEnter the INFIX expression: ");
    gets(infix);
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
            stack[++top]=infix[i];
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            {
                arr[point]=stack[top];
                point++;
                top--;
            }
            top--;
        }
        else if(infix[i]>='1'&&infix[i]<='9'||infix[i]>='a'&&infix[i]<='z'||infix[i]>='A'&&infix[i]<='Z')
        {
            arr[point]=infix[i];
            point++;
        }
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='%'||infix[i]=='^')
        {
            if(top==-1||stack[top]=='(')
                stack[++top]=infix[i];
            else
            {
                opre=operatorprecedence(infix[i]);
                spre=operatorprecedence(stack[top]);
                if(spre<=opre||stack[top]=='(')
                {
                    top++;
                    stack[top]=infix[i];
                }
                else
                {
                    while(spre>=opre&&top>=-1)
                    {
                        arr[point]=stack[top];
                        point++;
                        top--;
                        spre=operatorprecedence(stack[top]);
                    }
                    stack[++top]=infix[i];
                }
            }
        }
        i++;
    }
    while(top>=-1)
    {
        arr[point]=stack[top];
        point++;
        top--;
    }
    printf("\nThe POSTFIX expression is: %s",arr);
}


int operatorprecedence(char x)
{
    if(x=='/'||x=='*'||x=='%')
        return 2;
    else if(x=='+'||x=='-')
        return 1;
    else if(x=='^')
        return 3;
    else if(x=='(')
        return 0;
}

