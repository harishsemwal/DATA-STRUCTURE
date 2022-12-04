// Dequeue using array
// do revise this topic ......
#include <stdio.h>
#include <stdlib.h>
#define max 5

int dequeue[max];
int front = -1,rear = -1;

void enqueuefront()
{
    int num;
    printf("Enter The Element: ");
    scanf("%d",&num);

    if((front == 0 && rear == 0) || (front == rear + 1))
    {
        printf("Queue is Full !!\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        dequeue[front] = num;
    }
    else if (front == 0)
    {
        front = max - 1;
        dequeue[front] = num;
    }
    else{
        front--;
        dequeue[front] = num;
    }
}

void enqueue_rear()
{
    int num;
    printf("Enter The Element: ");
    scanf("%d",&num);

    if((front == 0 && rear == max - 1) || (front = rear + 1))
    {
        printf("Queue is full\n");
    }
    else if((front == -1)&&(rear == -1))
    {
        front = rear = 0;
        dequeue[rear] = num;
    }
    else if(rear == max -1)
    {
        rear = 0;
        dequeue[0] = num;
    }
    else{
        rear++;
        dequeue[rear] = num;
    }
}

void display()
{
    int i = front;
    while(i!= rear)
    {
        printf("%d ",dequeue[i]);
        i = (i+1)%max;
    }
    printf("%d ",dequeue[rear]);
}

void getfront()
{
    printf("The front element is %d.",dequeue[front]);
}

void dequeue_front()
{
    if((front == -1)&&(rear == -1))
    {
        printf("Empty\n");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else if(front = rear -1)
    {
        front = 0;
        printf("%d ",dequeue[front]);
    }
    else{
        printf("%d ",dequeue[front]);
        front++;
    }
}

void dequeue_rear()
{
    if(front == -1 && rear == -1)
    {
        printf("Empty");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else if(rear == 0)
    {
        printf("The delete element is %d", dequeue[rear]);
        rear = max -1;
    }
    else
    {
        printf("The delete element is %d.",dequeue[rear]);
        rear--;
    }
}

int main()
{
	int choice;
	while(1)
	{
	printf("\n\nPlease choese one choice at a one time:\n");
	printf("1->: insert element front:\n");
	printf("2->: insert element rear :\n");
	printf("3->: display all the elements:\n");
	printf("4->: display the front element:\n");
	printf("5->: exit:\n");
	
	
	printf("Enter Your choice: ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1 : enqueuefront();
				break;
		case 2 : enqueue_rear();
				break;
		case 3 : display();
				break;
		case 4 : getfront();
				break;
		case 5 : dequeue_front();
				break;
        case 6 : dequeue_rear();
                break;
        case 7 : exit(0);
                break;
        default : printf("Dhiyan se Option choese ker Bhaii \n");
                  printf("maar khaega kya dhang se select kar !!\n");
                break;
			
	}
	}
}