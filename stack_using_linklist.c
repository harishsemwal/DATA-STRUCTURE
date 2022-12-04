//stack reprasentation using linklist.

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int info;
    struct stack *next;
};

struct stack *top = NULL;

void push()
{
    struct stack *newnode;
    newnode = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter The Element: ");
    scanf("%d",&newnode->info);
    newnode->next = top;
    top = newnode;
}

void display()
{
    struct stack *temp;
    temp = top;
    if(top == NULL)
    {
        printf("List is Empty !!");
    }
    else
    {
        while(temp!= NULL)
        {
            printf("%d ",temp->info);
            temp = temp->next;
        }
    }
}

void peek()
{
    if(top == NULL)
    {
        printf("Empty !!");

    }
    else
    {
        printf("The top Element is %d.",top->info);
    }
}

void pop()
{
    struct stack *temp;

    if(top == NULL)
    {
        printf("Underflow !!!");
    }
    else
    {
        temp = top;
        top = top->next;
        printf("The Poped element is %d.",temp->info);
        free(temp);
    }
}

int main()
{
    int num;
    while(1)
    {
        printf("\n1-> insertion.\n");
        printf("2-> deletion.\n");
        printf("3 -> peek.\n");
        printf("4-> display.\n");
        printf("5-> exit\n");

        printf("Enter Your choice: ");
        scanf("%d",&num);
        switch (num)
        {
        case 1 : push();
            break;
        case 2 : pop();
            break;
        case 3 : peek();
            break;
        case 4 : display();
            break;
        case 5 : exit(0);
            break;
        
        default: printf("Invalid choice !!");
            break;
        }
    }
}