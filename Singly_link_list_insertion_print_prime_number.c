// Singly Linked list insertion and print prime numbers

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *start = NULL;

struct node *create_node()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}

void insert_end()
{
    struct node *temp, *temp2;
    temp = create_node();
    printf("Enter The Element: ");
    scanf("%d", &temp->info);

    if (start == NULL)
    {
        start = temp;
        temp->next = NULL;
    }
    else
    {
        temp2 = start;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->next = NULL;
    }
}

void display()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("List is Empty !!!");
    }
    else
    {
        printf("\nThe Linklist Element is: \n");
        temp = start;
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->next;
        }
    }
}

void display_prime()
{
    struct node *somePtr, *indexPtr;
    somePtr = start;

    if(start == NULL)
    {
        printf("Linklist is Empty !!");
    }
    else
    {
        while(somePtr != NULL)
        {
            
        }
    }
}

int main()
{
    insert_end();
    insert_end();
    insert_end();

    display();
}