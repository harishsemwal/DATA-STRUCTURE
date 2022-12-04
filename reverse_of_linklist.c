// reverse of linklist

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
int reverseNode()
{
    struct node *t1 = NULL, *t2 = NULL, *dis = NULL;
    while (start != NULL)
    {
        t2 = start->link;
        start->link = t1;
        t1 = start;
        start = t2;
    }
    start = t1;
    dis = start;
    printf("The reverse Linklist is: \n");
    while (dis != NULL)
    {
        printf("%d ", dis->info);
        dis = dis->link;
    }
}
int menu()
{
    int ch;
    printf("\nAdd The Value in List: ");
    printf("\nreverse The Linklist Elements");
    printf("\nexit");
    printf("Enter Your choice: ");
    scanf("%d", &ch);
    return ch;
}
void main()
{
    while (1)
    {
        switch (menu())
        {
        case 1:
            Insertion();
            break;
        case 2:
            reverseNode();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid Choice !!");
            break;
        }
    }
}