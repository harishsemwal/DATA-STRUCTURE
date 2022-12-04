#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *start = NULL;

struct node *createNode()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}

void insertElement()
{
    int n;
    struct node *temp, *temp2;
    printf("Enter The size of Linklist: ");
    scanf("%d",&n);

    printf("Enter The Elements: ");
    for(int i = 0 ; i < n ; i++)
    {
        temp = createNode();
        scanf("%d",&temp->info);

        if(start == NULL)
        {
            start = temp;
            temp->next = NULL;
        }
        else
        {
            temp2 = start;
            while(temp2->next!=NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp;
            temp->next = NULL;
        }
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
            if(temp->info % 2 == 0)
            {
                printf("%d->",temp->info);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    insertElement();
    dispaly();
}