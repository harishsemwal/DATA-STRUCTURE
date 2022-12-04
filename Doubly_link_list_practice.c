#include<stdio.h>
#include<stdlib.h>


// crate a node 
struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

struct node *start = NULL;

struct node *create_node()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter The Element: ");
    scanf("%d",&temp->info);
    temp->prev = temp->next = NULL;
    return temp;
}

void insertion()
{
    struct node *temp , *temp2;
    temp = create_node();
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        temp2 = start;
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp->prev = temp2;
        temp2->next = temp;
    }
}

void display()
{
    struct node *temp;
    if(start == NULL)
    {
        printf("linklist is Empty !!\n");
    }
    else
    {
        temp = start;
        while(temp != NULL)
        {
            printf("%d->",temp->info);
            temp = temp->next;
        }
    }
}

void deltion()
{
    struct node *temp;
    temp = start;
    if(start == NULL)
    {
        printf("Linklist is Empty !!");
    }
    if(start->next == NULL)
    {
        printf("The Deleted Node is: %d.",start->info);
        start = NULL;
    }
    else
    {
        temp = start;
        start = start->next;
        start->prev = NULL;
        printf("The Deleted Node is: %d.",temp->info);
        free(temp);
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1->: insertion \n");
        printf("2->: delition:\n");
        printf("3->: Display\n");
        printf("4->: Exit\n");

        printf("Enter The choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1 : insertion();
            break;
        case 2 : deltion();
            break;
        case 3 : display();
            break;
        case 4 : exit(0);
            break;
        default: printf("invalid\n");
            break;
        }
    }
}