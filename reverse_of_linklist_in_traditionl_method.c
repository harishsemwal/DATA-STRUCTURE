//reverse of Linklist

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
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
	{
		temp = (struct node *)malloc(sizeof(struct node));
		scanf("%d",&temp->info);
		temp->next = NULL;
		
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
}
int display(struct node *start)
{
	struct node *temp;
	temp = start;
	if(start == NULL)
	{
		printf("insertion is not possible !!\n\n");
	}
	else
	{
		temp = start;
		while(temp!=NULL)
		{
			printf("%d->",temp->info);
			temp = temp->next;
		}
	}
}

int reverse_node(struct node **starts)
{
	struct node *start = NULL;
	struct node *temp1 = NULL;
	struct node *temp2 = NULL;
	
	start = *starts;
	while(start!=NULL){
		temp2 = start->next;
		start->next = temp1;
		temp1 = start;
		start = temp2;
	}
	display(temp1);
}
int main()
{
	struct node *start = NULL;
	
	insertion_node(&start);
	printf("\nBefore reverse: \n");
	display(start);
	
	printf("\nAfter reverse: \n");
	reverse_node(&start);
	
	
}
