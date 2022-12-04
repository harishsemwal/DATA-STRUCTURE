// To perform mmany Operation In linklist.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *start = NULL;

struct node *create_node();
void display_node();

void insert_beg();
void insert_end();
void insert_mid();
/*
void  insert_after();
void  delete_beg();
void  delete_end();
void  delete_node();
void  delete_after();
void  delete_list();
void  sort_list();
*/

//  For Creating purpose of the node
struct node *create_node()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}

//  For Displaying purpose of the node
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

// insert the node in Begining of the linklist

void insert_beg()
{
    struct node *temp, *temp2;
    temp = create_node();
    printf("Enter The Element: ");
    scanf("%d", &temp->info);

    if (start == NULL)
    {
        start = temp;
        temp->next = NULL;
    }
    else
    {
        temp2 = start;
        start = temp;
        temp->next = temp2;
    }
}

// Insert Element End of the linklist.
void insert_end()
{
    struct node *temp, *temp2;
    temp = create_node();
    printf("Enter The Element: ");
    scanf("%d", &temp->info);

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

// Insert Element in mid of The linklist.
void insert_mid()
{
    int mid;
    struct node *temp, *temp2, *temp3;

    printf("\nEnter The Element Where You can add node in linklist: ");
    scanf("%d", &mid);

    temp = create_node();
    printf("Enter The new node Element: ");
    scanf("%d", &temp->info);

    if (start == NULL)
    {
        printf("List is Empty !!!\n");
    }
    else
    {
        temp2 = start;
        while (temp2 != NULL)
        {
            if (temp2->info == mid)
            {
                
            }
        }
    }
}

void display()
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

int menu()
{
    int choice;
    printf("\n\n1-> Display Linklist Elements: \n");
    printf("2-> Insertion node Begning of The Linklist: \n");
    printf("3-> Insertion node End of The Linklist: \n");
    printf("4-> Insertion node mid of The Linklist: \n");
    printf("5-> Exit: \n");
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
            display_node();
            break;
        case 2:
            insert_beg();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_mid();
            break;
        case 5:
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
