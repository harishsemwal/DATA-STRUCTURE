// Implimintaiton of Queue using linklist.

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

    printf("Enter the Element: ");
    scanf("%d",&newnode->info);

    if(front == NULL && rear == NULL)
    {
        front = rear = newnode;
        newnode->next = NULL;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void display()
{
    struct node *disp;
    disp = front;
    
    while(disp!= NULL)
    {
        printf("%d ",disp->info);
        disp = disp->next;
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;

    if(front == NULL && rear == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("The Dequeue element is %d.\n",temp->info);
        front = front->next;
        free(temp);
    }
    
}

void peek()
{
    if(front == NULL && rear == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Top peek Element is: %d.",front->info);
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n\nWelcome to Queue using linklist: \n");
        printf("1->insertion: \n");
        printf("2->delete: \n");
        printf("3->display: \n");
        printf("4->peek: \n");
        printf("Enter Your choice: ");
        scanf("%d",&choice);
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