// Evaluate prefix

#include <stdio.h>
#include <stdlib.h>
#define max 5

int stack[50];
int top = -1;
int evaluate_prefix(char str[])
{
    int i = 0, op1, op2, value;
    while(str[i] != '\0')
    {
        if(str[i] >= '1' && str[i] <= '9')
        {
            push(stack, (int)str[i]- '1');
        }
        else
        {
            op1 = pop(stack);
            op2 = pop(stack);

            switch(str[i])
            {
                case 1 : value = op2 + op1;
                    break;
                case 2 : value = op2 - op1;
                    break;
            }
            psuh(stack,value);
        }
        i++;
    }
    return(pop(stack));
}

void push(int stack[], int val)
{
    if(top == max -1)
    {
        printf("Stack is Full \n");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

int pop(int stack[])
{
    int num;
    
    if(top == -1)
    {
        printf("Stack is Empty");
    }
    else
    {
        num = stack[top];
        top--;
    }
    return num;
}

int main()
{
    int val;
    char str[50];
    printf("Enter The Expression: ");
    gets(str);

    val = evaluate_prefix(str);

    printf("The Sum is: %d.",val);
}
