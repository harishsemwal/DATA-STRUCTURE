#include <stdio.h>
#include<stdlib.h>
struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};

struct ArrayStack *createstack(int cap)
{
    struct ArrayStack *stack;
    stack = malloc(sizeof(struct ArrayStack));
    stack->capacity = cap;
    stack->top = -1;
    stack->array = malloc(sizeof(int) * stack->capacity);
    return stack;
}

int isFull(struct ArrayStack *stack)
{
    if ((stack->top) == (stack->capacity - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct ArrayStack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct ArrayStack *stack,int item)
{
    if (!isFull(stack))
    {  
        stack->top++;
        stack->array[stack->top] = item;
    }
}

int pop(struct ArrayStack *stack)
{
    int item;
    if (!isEmpty(stack))
    {
        item = stack->array[stack->top];
        stack->top--;
        return item;
    }
    return -1;
}
int main()
{
    int choice, items;
    struct ArrayStack *stack;
    stack = createstack(4); 
    while (1)
    {
            printf("1 ->: Push \n");
            printf("2 ->: pop \n");
            printf("Exit\n");

            printf("Enter The choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case '1':
            printf("Enter The  number: ");
            scanf("%d", &items);
            push(stack,items);
            break;
     case '2':
            items = pop(stack);
            if (items == -1)
            {
                printf("Empty");
            }
            else
            {
                printf("The item is: %d", items);
            }
            break;
    case '3': exit(0);
              break;
        }
    }
}