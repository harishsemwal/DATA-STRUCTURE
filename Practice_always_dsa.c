#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_node()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    return temp;
}

void insertion()
{
    struct node *temp, *temp2;
    temp = create_node();

    printf("\n\nEnter The Element: ");
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

void display()
{
    struct node *temp;
    temp = start;

    if (start == NULL)
    {
        printf("Linklist is Empty !!");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void insert_beg()
{
    struct node *temp;

    temp = create_node();
    printf("Enter The Element: ");
    scanf("%d",&temp->data);

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

void insert_mid()
{
    int key;
    struct node *temp, *temp2, *temp3;
    temp = create_node();
    
    printf("Enter The Element: ");
    scanf("%d",&temp->data);

    printf("Enter The pos: ");
    scanf("%d",&key);

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
            if(temp2->data == key)
            {
                temp->next = temp2->next;
                temp2->next = temp;
            }
            temp2 = temp2->next;
        }
    }
}

void delete_end()
{
    struct node *temp;
    if(start == NULL)
    {
        printf("linklist is Empty !!!");
    }
    else if(start->next = NULL)
    {
        start->next = NULL;
    }
    else
    {
        temp = start;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n1-> insertion: \n");
        printf("2-> display: \n");
        printf("3-> insert begning: \n");
        printf("4-> insert mid: \n");
        printf("5-> Delete end:\n");
        printf("Enter The choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_beg();
            break;
        case 4:
            insert_mid();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("invalid choice !!");
            break;
        }
    }
}