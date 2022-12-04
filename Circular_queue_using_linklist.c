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
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter The Element: ");
    scanf("%d", &newnode->info);

    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
        newnode->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        newnode->next = front;
    }
}

void display()
{
    struct node *disp;
    disp = front;
    if (front == NULL && rear == NULL)
    {
        printf("Queue is Empty !!");
    }
    else
    {
        while (disp->next != front)
        {
            printf("%d ", disp->info);
            disp = disp->next;
        }
        printf("%d ", disp->info);
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("Queue is Empty !!");
    }
    else if (front == rear)
    {
        front = rear = NULL;
        free(temp);
    }
    else
    {
        front = front->next;
        printf("The Deleted element is %d.", temp->info);
        free(temp);
    }
}

void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is Empty !!");
    }
    else
    {
        printf("The peek element is %d.", front->info);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1->insertion: \n");
        printf("2->delete: \n");
        printf("3->display: \n");
        printf("4->peek element: \n");
        printf("Enter Your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        default:
            printf("invalid choice !!!");
            break;
        }
    }
}