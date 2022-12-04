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
	struct node *temp, *temp2;
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
		temp2 = start;
		while(temp2->next != NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp;
		temp->next = NULL;
	}
}

//void bubble_short()
//{
//    struct node *current, *index;
//    int temp;
//    current = start;
//
//    if (start == NULL)
//    {
//        printf("shorting is not possible !!\n");
//    }
//    else
//    {
//        while (current != NULL)
//        {
//            index = current->next;
//
//            while (index != NULL)
//            {
//                if (current->info > index->info)
//                {
//                    temp = current->info;
//                    current->info = index->info;
//                    index->info = temp;
//                }
//                index = index->next;
//            }
//            current = current->next;
//        }
//    }
//}
//
//void bubble_short()
//{
//	struct node *current, *index;
//	int temp;
//	
//	current = start;
//	
//	while(current!= NULL)
//	{
//		index = current->next;
//		while(index!= NULL)
//		{
//			if(current->info > index->info)
//			{
//				temp = current->info;
//				current->info = index->info;
//				index->info = temp;
//			}
//		}
//		index = index->next;
//	}
//	current = current->next;
//}

void remove_dup()
{
	struct node *current, *index, *dup;
	
	current = start;
	
	while(current!= NULL)
	{
		index = current;
		while(index->next != NULL)
		{
			if(current->info == index->next->info)
			{
				dup = index->next;
				index->next = index->next->next;
				free(dup); 
			}
			else
			{
				index = index->next;
			}
		}
		current = current->next;
	}

}


void display()
{
	struct node *temp;
	if(start == NULL)
	{
		printf("Empty");
	}
	else
	{
		temp = start;
		printf("\nThe Element is: \n");
		while(temp != NULL)
		{
			printf("%d ", temp->info);
			temp = temp->next;
		}
	}
}

int main(){
	
	insertion();
	insertion();
	insertion();
	insertion();
	
	display();
	
	remove_dup();
	
	display();
}

