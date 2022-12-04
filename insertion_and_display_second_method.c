#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int insertion_node(struct node **start)
{
	int size, i;
	struct node *temp, *temp2;
	
	printf("Enter The size: ");
	scanf("%d",&size);
	
	printf("Enter The Elements: ");
	for(i = 1 ; i <= size ; i++)
		
		if(*start == NULL)
		{
			*start = temp;
		}
		else
		{
			temp2 = *start;
			while(temp2->next!=NULL)
			{
				temp2 = temp2->next;
			}
			temp2->next = temp;
		}
}

void display_node(struct node *start)
{
	struct node *temp;
	temp = start;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct node *start = NULL;
	insertion_node(&start);
	display_node(start);
}
