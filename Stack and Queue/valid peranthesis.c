#include<stdio.h>
#include<string.h>


void main()
{
    char stack[50],exp[50];
    int i,top=-1;
    printf("\t\t\t***\tProgram for check parenthesis is balanced or not\t***");
    printf("\n\nEnter the expression:  ");
    gets(exp);



    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            stack[++top]='(';
        else if(exp[i]=='[')
            stack[++top]='[';
        else if(exp[i]=='{')
            stack[++top]='{';
        else if(exp[i]==')')
        {
            if(stack[top]=='(')
                top--;
            else
            {
                printf("\nThis expression is unbalanced");
                break;
            }
        }
        else if(exp[i]==']')
        {
            if(stack[top]=='[')
                top--;
            else
            {
                printf("\nThis expression is unbalanced");
                break;
            }
        }else if(exp[i]=='}')
        {
            if(stack[top]=='{')
                top--;
            else
            {
                printf("\nThis expression is unbalanced");
                break;
            }
        }
    }
    if(top==-1&&exp[i]=='\0')
        printf("\nThis expression is balanced");
}
