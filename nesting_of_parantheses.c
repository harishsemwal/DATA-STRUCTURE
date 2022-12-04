// Implementing parentheses cheacker.

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#define max 5

int top = -1;
char stk[max];

void push(char c)
{
    if(top == max - 1)
    {
        printf("OverFlow !!");
    }
    else
    {
        top++;
        stk[top] = c;
    }
}

char pop()
{
    char temp;
    if(top == -1)
    {
        printf("Underflow");
    }
    else
    {
        temp = stk[top];
        top--;
        return temp;
    }
}

int main()
{
    char str[50], temp;
    int flag = 1;

    printf("Enter The expression: ");
    gets(str);

    for (int i = 0; i < strlen(str); i++)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(str[i]);
        }
        if(str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if(top == -1)
            {
                flag = 0;
            }
            else
            {
                temp = pop();
                if(str[i] == ')' && (temp == '[' || temp == '{'))
                {
                    flag = 0;
                }
                if(str[i] == '}' && (temp == '(' || temp == '['))
                {
                    flag = 0;
                }
                if(str[i] == ']' && (temp == '(' || temp == '{'))
                {
                    flag = 0;
                }
            }
        }
    }
     if(top >= 0)
        {
            flag = 0;
        }
        if(flag == 1)
        {
            printf("\nValid Expression !!");
        }
        else
        {
            printf("Invalid Expression !!");
        }
}