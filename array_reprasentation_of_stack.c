#include <stdio.h>
#include <stdlib.h>
#define max 5

int stack[max],top = -1;

void push(int stack[])
{
    int num;
    printf("Enter The Element: ");
    scanf("%d",&num);

    if(top == max - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        stack[top] = num;
    }
}

void pop(int stack[])
{
    int value;
    if(top == -1)
    {
        printf("Underflow");
    }
    else
    {
        value = stack[top];
        top--;
        printf("The poped value is %d\n",value);
    }
}

void peek(int stack[])
{
    if(top == -1)
    {
        printf("Element is not present !!!\n");
    }
    else
    {
        printf("The top element is %d",stack[top]);
    }
}
void display(int stack[])
{
    if(top == -1)
    {
        printf("list is empty !!");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ",stack[i]);
        }
    }
}
int main()
{
    int choice;

    while(1)
    {
        printf("\n1->push\n");
        printf("2->pop\n");
        printf("3->peek\n");
        printf("4->display\n");

        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : push(stack);
            break;
        case 2 : pop(stack);
            break;
        case 3 : peek(stack);
            break;
        case 4 : display(stack);
            break;
        default: printf("invalid !!!");
            break;
        }
    }
}
