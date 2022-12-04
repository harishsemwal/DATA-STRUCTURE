//evaluate The prefix expression on the stack.
// loop Ulta.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 50

int evaluate_expression(char str[]);
void push(char str[],int value);
int pop(char str[]);
char stack[max];
int top = -1;

int main()
{
    char str[100];
    int value;
    printf("Enter The expression: ");
    gets(str);
    value = evaluate_expression(str);
    printf("The postfix value is: %d\n",value);
}

int evaluate_expression(char str[])
{
    int i = 0;
    float op1, op2, value;
    while(str[i]!='\0')
    {
        if(str[i] >= 0 && str[i] <= 9)
        {
            push(str,str[i] - '0');
        }
        else
        {
            op2 = pop(str);
            op1 = pop(str);

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
            }
            push(str,value);
        }
        i++;
    }
    return pop(str);
}

void push(char str[],int value)
{
    printf("The value is : %d\n",value);
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
