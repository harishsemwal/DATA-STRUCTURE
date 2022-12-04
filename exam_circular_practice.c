#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

struct node *create_node()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}

void insert_beg()
{
    struct node *temp, *ptr;
    temp = create_node();

    printf("Enter the Element: ");
    scanf("%d", &temp->data);

    if (start == NULL)
    {
        start = temp;
        temp = start;
    }
    else
    {
        ptr = start;
        start = temp;
        temp->next = ptr;
    }
}

void display()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("linklist is Empty !!!\n");
    }
    else
    {
        temp = start;
        while (temp->next != start)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("1->insertion: \n");
        printf("2->display: \n");
        printf("Enter Your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            display();
            break;
        default:
            printf("invalid choice !!!");
            break;
        }
    }
}