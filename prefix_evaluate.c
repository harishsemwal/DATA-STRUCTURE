//evaluate The prefix expression on the stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 50

void push(char str[],int value);
int pop(char str[]);
char str[max];
char stack[max];
int top = -1;

int main()
{
    int len = 0, op1, op2, value;
    printf("Enter The expression: ");
    gets(str);
    printf("The string is: %s\n",str);
    len = strlen(str);

    for(int i = len - 1 ; i >= 0 ; i--)
    {
        printf("%c ",str[i]);
        if(str[i] >= 0 && str[i] <= 9)
        {
            int val;
            val = str[i] - '0';
            printf("%d ",val);
            push(str,str[i]-val);
        }
        else
        {
            op2 = pop(str);
            printf("%c ",op2);
            op1 = pop(str);
            printf("%c ",op1);
            switch (str[i])
            {
            case '+' : value = op1 + op2;
                break;
            case '-' : value = op1 - op2;
                break;
            case '/' : value = op1 / op2;
                break;
            case '*' : value = op1 * op2;
                break;
            case '%' : value = op1 % op2;
                break;
            }
            push(str,value);
        }
    }
    printf("\nThe Element is: %d\n",str[0]);
}

void push(char str[],int value)
{
    printf("yaha bhi pahuch raha hai\n");
    if(top == max - 1)
    {
        printf("\nOverflow !!!\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

int pop(char str[])
{
    int value = -1;
    if(top == -1)
    {
        printf("Underflow !!!\n");
    }
    else
    {
        value = stack[top];
        top--;
    }
    return value;
}
