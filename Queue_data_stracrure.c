#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max];
int front = -1,rear = -1;

void enqueue()
{
    int num;
    if(rear == max-1 || front > rear)
    {
        printf("Overflow\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    printf("Enter The Element: ");
    scanf("%d",&num);
    queue[rear] = num;
}

void dequeue()
{
    int value;
    if(front == -1 || front > rear)
    {
        printf("Underflow\n");
    }
    else
    {
        value = queue[front];
        front++;
        if(front>rear)
        {
            front = rear = -1;
        }
        printf("The Deleted element is %d.",value);
    }
}

void display()
{
    if(front > rear)
    {
        printf("not possible");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ",queue[i]);
        }
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
        default:
            printf("invalid choice !!!");
            break;
        }
    }
}