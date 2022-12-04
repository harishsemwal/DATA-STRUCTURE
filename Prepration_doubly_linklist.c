#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *prev;
	struct node *next;
};
struct node *start = NULL;

void insertion()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter The Element: ");
	scanf("%d",&temp->info);
	
	if(start == NULL)
	{
		start = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else
	{
		temp->next = start;
		temp->prev = NULL;
		start->prev = temp;
		start = temp;
	}
}

void display()
{
	struct node *temp;
	if(start == NULL)
	{
		printf("Linklist is Empty !!!");
	}
	else
	{
		temp = start;
		while(temp!= NULL)
		{
			printf("%d->",temp->info);
			temp = temp->next;
		}
	}
}

void delete_doubly()
{
	int num;
	struct node *temp;
	
	if(start == NULL)
	{
		printf("linklist is Empty !!");
	}
	else
	{
		struct node *temp;
		
		printf("Enter The Element which You can to delete: ");
		scanf("%d",&num);
		
		while(temp->info != num)
		{
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}
}

int main()
{
	int choice;
	while(1)
	{
		printf("\n\nInsertion: \n");
		printf("Delition: \n");
		printf("Display: \n");
		
		printf("Enter The choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1 : insertion();
				break;
			case 2 : delete_doubly();
				break;
			case 3 : display();
				break;
		}
	}
}
