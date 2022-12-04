#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
void enqueue(struct node **start);
void display(struct node *start);
void add_object(struct node **start);

int main()
{
    struct node *start = NULL;

    enqueue(&start);
    printf("\nThe Element Before adding Element: \n");
    display(start);

    add_object(&start);
    printf("\nThe Element after adding Element: \n");
    display(start);
}

void enqueue(struct node **start)
{
    int num;
    struct node *newnode;

    printf("Enter The number of node: ");
    scanf("%d", &num);

    printf("Enter The Elements: \n");
    for (int i = 0; i < num; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->info);
        newnode->next = NULL;

        if (*start == NULL)
        {
            *start = newnode;
        }
        else
        {
            newnode->next = *start;
            *start = newnode;
        }
    }
}

void display(struct node *start)
{
    struct node *temp;

    if (start == NULL)
    {
        printf("Linklist is Empty !!!\n");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->next;
        }
    }
}

void add_object(struct node **start)
{
    struct node *base = *start;
    struct node *cheack = *start;
    struct node *newnode = NULL, *prev;

    while (cheack->next != NULL)
    {
        if (base!= NULL)
        {
            if ((base->info) % 2 == 0)
            {
                newnode = (struct node *)malloc(sizeof(struct node));
                printf("\nEnter The Element before %d: ", (base)->info);
                scanf("%d", &newnode->info);

                newnode->next = base;
                base = newnode;

                base = base->next;
            }
        }
        else if ((cheack->next->info) % 2 == 0)
        {
            prev = cheack;
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("\nEnter The Element brefore %d: ", cheack->next->info);
            scanf("%d", &newnode->info);

            newnode->next = prev->next;
            prev->next = newnode;
            cheack = cheack->next->next;
        }
        else
        {
            cheack = cheack->next;
        }
    }
}