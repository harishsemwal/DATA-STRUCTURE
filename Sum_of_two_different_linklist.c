//Sum of Two different Linklist

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node sumkerde(struct node *start1,struct node *start2);
void display(struct node *start1,struct node *start2);

int main()
{
    int sum, n;
    struct node *start1 = NULL;
    struct node *start2 = NULL;

    struct node *temp, *temp2;
    printf("Enter The number of element: ");
    scanf("%d", &n);

    printf("Enter The First Linklist Element: \n");
    for (int i = 1; i <= n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Element: ");
        scanf("%d", &temp->info);

        if (start1 == NULL)
        {
            start1 = temp;
            temp->next = NULL;
        }
        else
        {
            temp2 = start1;
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp;
            temp->next = NULL;
        }
    }

    printf("Enter The second Linklist Element: \n");
    for (int i = 1; i <= n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Element: ");
        scanf("%d", &temp->info);

        if (start2 == NULL)
        {
            start2 = temp;
            temp->next = NULL;
        }
        else
        {
            temp2 = start2;
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp;
            temp->next = NULL;
        }
    }

    display(start1,start2);
}

void display(struct node *start1,struct node *start2)
{
    struct node *temp1, *temp2;
  
    temp1 = start1;
    temp2 = start2;

    printf("The first linklist element is: \n");
    while(temp1!= NULL)
    {
        printf("%d ",temp1->info);
        temp1 = temp1->next;
    }

    printf("The second linklist element is: \n");
    while(temp2!= NULL)
    {
        printf("%d ",temp2->info);
        temp2 = temp2->next;
    }

    struct node *sum;
    sum = sumkerde(start1,start2);
    printf("The sum is: \n");
    while(sum!=NULL)
    {
        printf("%d ",sum->info);
        sum = sum->next;
    }
}

struct node sumkerde(struct node *start1,struct node *start2)
{
    struct node *temp1 = start1;
    struct node *temp2 = start2;
    struct node *temp3 = NULL;
    struct node *temp4 = NULL;
    struct node *temp = NULL;

    while(temp1!=NULL && temp2!= NULL)
    {
        temp3 = (struct node *)malloc(sizeof(struct node *));
        temp3 ->info = temp1->info + temp2->info;
        if(temp3 == NULL)
        {
            temp4 = temp3;
            temp3->next = NULL;
        }
        else
        {
            temp = temp4;
            while(temp->next!= NULL)
            {
                temp = temp3->next;
            }
            temp->next = temp3;
            temp3->next = NULL;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp3;
}

