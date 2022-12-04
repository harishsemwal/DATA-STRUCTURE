// Using Linklist Implement Queue Data structure

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));

    printf("Enter the Element: ");
    scanf("%d",&new->info);
    new->next = NULL;

    if((front == NULL) && (rear == NULL))
    {
        front = rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }
}

void dequeue()
{
    struct node *temp;
    if((rear == NULL) && (front == NULL)) 
    {
        printf("Linklist is Empty !!");
    }
    else
    {
        temp = front;
        printf("The Deleted Element is: %d !!",temp->info);
        front = front->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    if ((front == NULL) && (rear == NULL))
    {
        printf("List is Empty !!!");
    }
    else
    {
        printf("\nThe Linklist Element is: \n");
        temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->next;
        }
    }
}

// void peek()
// {
//     if((front == NULL) && (rear == NULL))
//     {
//         printf("Empty");
//     }
//     else
//     {
//         printf("%d ",front->info);
//     }
// }

int main()
{
    int choice;
    while(1)
    {
        printf("\n1->: enqueue\n");
        printf("2->: dequeue\n");
        printf("3->: Display\n");
        printf("4->: Exit\n");

        printf("Enter The choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1 : enqueue();
            break;
        case 2 : dequeue();
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