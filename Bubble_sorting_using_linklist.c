#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *start = NULL;

struct node *CreateNode()
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    return n;
}

void Insertion()
{
    struct node *temp1, *temp2;
    temp1 = CreateNode();
    printf("Enter The Value: ");
    scanf("%d", &temp1->info);
    temp1->link = NULL;
    if (start == NULL)
    {
        start = temp1;
    }
    else
    {
        temp2 = start;
        while (temp2->link != NULL)
        {
            temp2 = temp2->link;
        }
        temp2->link = temp1;
    }
}

void display()
{
    struct node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
}

void bubble_short()
{
    struct node *current, *index;
    int temp;
    current = start;

    if (start == NULL)
    {
        printf("shorting is not possible !!\n");
    }
    else
    {
        while (current != NULL)
        {
            index = current->link;

            while (index != NULL)
            {
                if (current->info > index->info)
                {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;
                }
                index = index->link;
            }
            current = current->link;
        }
    }
}

int menu()
{
    int choice;
    printf("\n1->: insertion:\n");
    printf("2->: display:\n");
    printf("3->: bubble short in linklist: \n");
    printf("4->:exit:\n");
    printf("Enter The choice: ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    while (1)
    {
        switch (menu())
        {
        case 1:
            Insertion();
            break;
        case 2:
            bubble_short();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
}
