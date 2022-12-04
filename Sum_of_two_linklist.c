#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int sumkerde(struct node *start);

int main()
{
    int sum, n;
    struct node *start = NULL;
    struct node *temp, *temp2;
    printf("Enter The number of element: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Element: ");
        scanf("%d", &temp->data);

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
    sum = sumkerde(start);
    printf("The sum of The linklist element is: %d", sum);
}

int sumkerde(struct node *start)
{
    int sum = 0;
    struct node *temp = start;
    while (temp != NULL)
    {
        sum = sum + temp->data;
        temp = temp->next;
    }

    return sum;
}