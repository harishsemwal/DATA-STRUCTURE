#include <stdio.h>
#include <stdlib.h>

struct stacks
{
    int top;
    int capacity;
    int *array;
};

struct stacks *create_stack(int cap)
{
    struct stacks *stack;
    stack = (struct stacks *)malloc(sizeof(struct stacks));
    stack->top = -1;
    stack->capacity = cap;
    stack->array = malloc(sizeof(int) * stack->capacity);

    return stack;
}

int isFull(struct stacks *stack)
{
    if ((stack->capacity) - 1 == stack->top)
    {
        return 1; // condition is true
    }
    else
    {
        return 0; // condition is false
    }
}

int isEmpty(struct stacks *stack)
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

void push(struct stacks *stack)
{
    if (isFull(stack))
    {
        printf("Overflow !!\n");
    }
    else
    {
        stack->top++;
        printf("Enter The Element: ");
        scanf("%d", &stack->array[stack->top]);
    }
}

int pop(struct stacks *stack)
{
    int item;
    if (isEmpty(stack))
    {
        printf("Underflow !!!");
    }
    else
    {
        item = stack->array[stack->top];
        stack->top--;
        return item;
    }
}

int menu()
{
    int choice;
    printf("\n1-:Push\n");
    printf("2-:Pop\n");
    printf("Enter Your choice: ");
    scanf("%d", &choice);

    return choice;
}

int main()
{
    struct stacks *stack;
    int items;
    stack = create_stack(4);
    while (1)
    {
        switch (menu())
        {
        case 1:
            push(stack);
            break;
        case 2:
            items = pop(stack);
            printf("The poped Element is: %d\n", items);
            break;
        default:
            break;
        }
    }
}
