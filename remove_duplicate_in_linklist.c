#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int info;
	struct node *next;
};
void remove_duplicate(struct node *start);

void display(struct node *start)
{
	printf("\nThe Element is: \n");
	struct node *temp;
	temp = start;
	
	while(temp != NULL)
	{
		printf("%d ",temp->info);
		temp = temp->next;
	}
}

void insertion()
{
	int i, n;
	struct node *start = NULL;
	struct node *temp, *temp2;
	printf("Enter The number of Element: ");
	scanf("%d",&n);
	
	printf("Enter the Elements: ");
	for(i = 0 ; i < n ; i++)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		scanf("%d",&temp->info);
		
		if(start == NULL)
		{
			start = temp;
			temp->next = NULL;
		}
		else
		{
			temp->next = start;
			start = temp;
		}
	}
	display(start);
	remove_duplicate(start);
}

void remove_duplicate(struct node *start)
{
	struct node *current, *index , *temp;
	current = start;
	while(current->next!= NULL)
	{
		index = current;
		while(index!=NULL && index->next!= NULL)
		{
			if(current->info == index->next->info)
			{
				temp = index->next;
				index->next = index->next->next;
				free(temp);
			}
			else
			{
				index = index->next;
			}
		}
		current = current->next;
	}
	display(start);
}

int main()
{
	insertion();	
}