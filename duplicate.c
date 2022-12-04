// remove Duplicate Element in the linklist.

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *start = NULL;

// void delete_duplicate()
// {
// 	struct node *current, *index, *dup;
// 	current = start;

// 	while(current!= NULL)
// 	{
// 		index = current;
// 		while(index->next != NULL)
// 		{
// 			if(current->info == index->next->info)
// 			{
// 				dup = index->next;
// 				index->next = index->next->next;
// 				free(dup);
// 			}
// 			else
// 			{
// 				index = index->next;
// 			}
// 		}
// 	}
// 	current = current->next;
// }


void delete_duplicate()
{
	struct node *index = start;
	struct node *current, *dup;
	while(index != NULL)
	{
		current = index;
		while(current->next != NULL)
		{
			if(index->info == current->next->info)
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

struct node *create_node()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}

void insert_end()
{
    struct node *temp, *temp2;
    temp = create_node();
    printf("Enter The Element: ");
    scanf("%d", &temp->info);

    if (start == NULL)
    {
        start = temp;
        temp->next = NULL;
    }
    else
    {
        temp2 = start;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->next = NULL;
    }
}


void dispaly()
{
    struct node *temp;
    if(start == NULL)
    {
        printf("list is Empty !!!");
    }
    else
    {
        temp = start;
        while(temp !=NULL)
        {
			printf("%d->",temp->info);
            temp = temp->next;
        }
    }
}

int main()
{
	int choice;
	while(1)
	{
	printf("\n\nPlease choese one choice at a one time:\n");
	printf("1->: insert element:\n");
	printf("2->: duplicate:\n");
	printf("3->: display\n");
	printf("4->: exit:\n");
	
	
	printf("Enter Your choice: ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1 : insert_end();
				break;
		case 2 : delete_duplicate();
				break;
		case 3 : dispaly();
				break;
			
	}
	}
}
