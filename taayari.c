#include<stdio.h>
#include<stdlib.h>


// crate a node 
struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

struct node *start = NULL;

struct node *create_node()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter The Element: ");
    scanf("%d",&temp->info);
    temp->prev = temp->next = NULL;
    return temp;
}

void insertion()
{
    struct node *temp , *temp2;
    temp = create_node();
    
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
    	temp->next = start;
    	start = temp;
    	temp->prev = NULL;
    }
}

void display()
{
    struct node *temp;
    if(start == NULL)
    {
        printf("linklist is Empty !!\n");
    }
    else
    {
        temp = start;
        while(temp != NULL)
        {
            printf("%d->",temp->info);
            temp = temp->next;
        }
    }
}

void deltion()
{
	int num;
	printf("Enter The Element which You want to delete: ");
	scanf("%d",&num);
	
	struct node *temp;
	temp = start;
	if(start == NULL)
	{
		printf("Linklist is Empty");
	}
	else
	{
		struct node *temp2;
		while(temp->next != NULL)
		{
			if(temp->info == num)
			{
				//temp2 = temp;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				//free(temp);
			}
			temp = temp->next;
		}
	}
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n\n1->: insertion \n");
        printf("2->: delition:\n");
        printf("3->: Display\n");
        printf("4->: Exit\n");

        printf("Enter The choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1 : insertion();
            break;
        case 2 : deltion();
            break;
        case 3 : display();
            break;
        case 4 : exit(0);
            break;
        default: printf("invalid\n");
            break;
        }
    }
}
