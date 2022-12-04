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
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter The Element: ");
    scanf("%d", &temp->info);

    if (start == NULL)
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

void dispaly()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("list is Empty !!!");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("%d->", temp->info);
            temp = temp->next;
        }
    }
}

void reverse()
{
    struct node *temp1 = NULL, *temp2 = NULL, *print;
    while (start != NULL)
    {
        temp2 = start->next;
        start->next = temp1;
        temp1 = start;
        start = temp2;
    }

    start = temp1;

}

int main()
{
    int n;
    printf("Enter The number of Element: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        insertion();
    }
    printf("\n");
    dispaly();
    reverse();
    dispaly();
}