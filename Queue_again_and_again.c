//array repreasentation of queue.

#include<stdio.h>
#include<stdlib.h>
#define max 10

void insert(void);
void deletes(void);
void peek(void);
void display(void);

int queue[max];
int front = -1, rear = -1;
 
int main()
{
	int choice;
	while(1)
	{
	printf("\n\nPlease choese one choice at a one time:\n");
	printf("1->: insert element:\n");
	printf("2->: delete element:\n");
	printf("3->: display peek element:\n");
	printf("4->: display all elements:\n");
	printf("5->: exit:\n");
	
	
	printf("Enter Your choice: ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1 : insert();
				break;
		case 2 : deletes();
				break;
		case 3 : peek();
				break;
		case 4 : display();
				break;
		case 5 : exit(0);
				 break;
			
	}
	}
}

void insert()
{
	int value;
	printf("Enter The value which you can insert: ");
	scanf("%d",&value);
	
	if(rear == max-1)
	{
		printf("Overflow !!\n");
	}
	else if((front == -1) && (rear == -1))
	{
		front = rear = 0;
	}
	else
	{
		rear++;
	}
	queue[rear] = value;
    
    display();
}

void deletes()
{
	int value;
	if(front == -1 && front > rear)
	{
		printf("Underflow !!!\n");
	}
	else
	{
		value = queue[front];
		front++;
		
		if(front > rear)
		{
			front = rear = -1;
		}
	}
	printf("The deleteted Element is : %d",value);
}

void display()
{
    int i;
	if((front > rear) || (front == -1))
    {
        printf("Underflow !!!\n");
    }
    else
    {
        for(i = front ; i <= rear ;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}

void peek()
{
	int item;
	
	if(front == -1 && front > rear)
	{
		printf("Underflow !!!\n");
	}
	else
	{
		item = queue[front];
	}
	printf("The peek Element is: %d",item);
}
