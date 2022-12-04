// Evaluate
//Harish Prasad Semwal
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define max 50
int evaluate_postfix(char exp[]);
void push(int stack[],int num);
int pop(int stack[]);

int stack[max];
int top = -1;

int main()
{
    char exp[100];
    int value;

    printf("Enter The infix expression: ");
    gets(exp);

    value = evaluate_postfix(exp);

    printf("The value is : %d\n", value);
    return 0;
}

int evaluate_postfix(char exp[])
{
    int a , b;
    for (int i = 0; i <= strlen(exp); i++)
    {
        if(isdigit(exp[i]))
        {
            push(stack, (int)(exp[i] - '0'));
        }
        else
        {
            a = pop(stack);
            b = pop(stack);
            switch (exp[i])
            {
            case '+':
                push(stack,b + a);
                break;
            case '-':
                push(stack,b - a);
                break;
            case '*':
                push(stack,b * a);
                break;
            case '/':
                push(stack,b / a);
                break;
            case '^':
                push(stack,pow(b , a));
                break;
            default:
                break;
            }
        }
    }
    return pop(stack);
}

void push(int stack[],int num)
{
    if(top == max - 1)
    {
        printf("Overflow !!");
    }
    else
    {
        top++;
        stack[top] = num;
    }
}

int pop(int stack[])
{
    int number;
    if(top == -1)
    {
        printf("Underflow");
    }
    else
    {
        number = stack[top];
        top--;
        return number;
    }
}