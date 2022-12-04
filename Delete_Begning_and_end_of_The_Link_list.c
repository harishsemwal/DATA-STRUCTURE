#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
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
    temp1->next = NULL;
    if (start == NULL)
    {
        start = temp1;
    }
    else
    {
        temp2 = start;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
}

void display_node()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("List is Empty !!!");
    }
    else
    {
        printf("\nThe Linklist Element is: \n");
        temp = start;
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->next;
        }
    }
}

void delition_mid()
{
    int element;
    printf("Enter The Element which You can Delete: ");
    scanf("%d", &element);

    struct node *temp, *pretemp;
    temp = start;
    pretemp = temp;
    while (pretemp->info!= element)
    {
        pretemp = temp;
        temp = temp->next;
    }
    pretemp->next = temp->next;
    if (temp == start)
    {
        start = pretemp->next;
    }
    free(temp);
}

int menu()
{
    int choice;
    
    printf("\n\n1-> Insertion node in The Linklist: \n");
    printf("2-> Display Linklist Elements: \n");
    printf("3-> Delition node mid of The Linklist: \n");
    printf("4-> Exit: \n");
    printf("Enter Your choice: ");
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
            display_node();
            break;
        case 3:
            delition_mid();
            break;
        case 4:
            printf("\n\nThanks Visiting Here !!\n");
            printf("Please Visit again an again !!\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice !!\n");
            break;
        }
    }
}
