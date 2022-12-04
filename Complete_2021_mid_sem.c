// remove Duplicate Element from the linklist.

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node *next;
};

struct node *start = NULL;

void insertion()
{
    struct node *temp, *tempw;
    temp = (struct node *)malloc(sizeof(struct node));
    
    printf("Enter The Element: ");
    scanf("%d",&temp->info);
    
    if(start == NULL)
    {
    	start = temp;
    	temp->next = NULL;
    }
    else
    {
        tempw = start;
        while(tempw->next != NULL)
        {
        	tempw = tempw->next;
		}
		tempw->next = temp;
		temp->next = NULL; 
    }
}

void display()
{
	struct node *temp;
	temp = start;
	
	if(start == NULL)
	{
		printf("Linklist is Empty !!!\n");
	}
	else
	{
		while(temp!= NULL)
		{
			printf("%d ",temp->info);
			temp = temp->next;
		}
	}
}

void remove_duplicate()
{
	struct node *index, *current, *dup;
	index = start;
	
	while(index!= NULL)
	{
		current = index;
		while(current->next!= NULL)
		{
			if(current->info == current->next->info)
			{
				dup = current->next;
				current->next = current->next->next;
				free(dup);
			}
			else
			{
				current = current->next;
			}
		}
		index = index->next;
	}
}

void delete_search()
{
	int num;
	struct node *temp, *pretemp,*another;
	temp = start;
	
	printf("Enter The Element which you can delete: ");
	scanf("%d",&num);
	
	if(start == NULL)
	{
		printf("Linklist is Empty !!");
	}
	else
	{
		while(temp->info != num)
		{
			pretemp = temp;
			temp = temp->next;
		}
		
		another = temp;
		pretemp->next = temp->next;
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
		printf("delete_search; \n");
		
		printf("Enter The choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1 : insertion();
				break;
			case 2 : remove_duplicate();
				break;
			case 3 : display();
				break;
			case 4 : delete_search();
				break;
		}
	}
}

