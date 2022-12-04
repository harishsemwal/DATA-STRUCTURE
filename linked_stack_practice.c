#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int capacity;
    int *array;
};
struct stack *st = NULL;

struct stack *create_stack(int cap)
{
    struct stack *st;
    st = (struct stack *)malloc(sizeof(struct stack));
    st->capacity = cap;
    st->top = -1;
    st->array = malloc(sizeof(int)*st->capacity);
    return st;
}

int isfull(struct stack *st)
{
    if(st->top == st->capacity-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(struct stack *st)
{
    if(st->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push()
{
    int num;
    if(isfull(st))
    {
        printf("Overflow");
    }
    else
    {
        printf("Enter the Element: ");
        scanf("%d",&num);
        st->top++;
        st->array[st->top] = num;
    }
}

void pop()
{
    int value;
    if(st->top == -1)
    {
        printf("Underflow");
    }
    else
    {
        value = st->array[st->top];
        st->top--;
        printf("The poped value is %d\n",value);
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
        case 1 : push();
            break;
        case 2 : pop();
            break;
        // case 3 : peek();
        //     break;
        // case 4 : display();
        //     break;
        default: printf("invalid !!!");
            break;
        }
    }
}
