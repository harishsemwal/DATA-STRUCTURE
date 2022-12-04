//infix to postfix
#define max 10
#include <stdio.h>
#include <stdlib.h>

float stack[max];
int top = -1;
int post(char str[]);
int main()
{
    int value;
    char str[100];

    printf("Enter The expression: ");
    scanf("%s",str);

    value = poste(str);
    printf("The value is: %0.2f",value);
}

int poste(char str[])
{
    int a, b;
    for (int i = 0; i < strlen(str); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            push(str,str[i] - '0');
        }
        else
        {
            a = pop(str[i]);
            b = pop(str[i]);
            switch (str[i])
            {
            case '+': push(str,b+a);
                break;
            case '-': push(str,b-a);
                break;
            case '*': push(str,b*a);
                break;
            case '/': push(str,b/a);
                break;
            }
        }
    }
    return pop(str);
}

void push(float str[],int val)
{
    if(top == -1)
    {
        printf("Overflow !!");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

int pop(int str[])
{
    int val = -1;
    if(top == -1)
    {
        printf("underflow !!");
    }
    else
    {
        val = stack[top];
        top--;
    }
    return val;
}

