//Circular Queue using array.
#include <stdio.h>
#include <stdlib.h>
#define max 5

int front = -1;
int rear = -1;
int queue[50];

void enqueue()
{
    int num;
    printf("Enter the element: ");
    scanf("%d",&num);

    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num; 
    }
    else if((rear+1) % max == front)
    {
        printf("Queue is Full");
    }
    else
    {
        rear = (rear+1)%max;
        queue[rear] = num;
    }
}

void dequeue()
{
    int temp;

    if(front == -1 && rear == -1)
    {
        printf("Queue is Empty !!!");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        temp = queue[front];
        front = (front+1) % max;
        printf("The Deleted Element is: ",temp);
    }
}

void peek()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is Empty!!\n");
    }
    else
    {
        printf("The top Element is: %d.",front);
    }
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        int i = front;
        while(i!= rear)
        {
            printf("%d ",queue[i]);
            i = (i+1)%max; 
        }
        printf("%d ",queue[i]);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n\nWelcome to Circular Queue Operations: \n");
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