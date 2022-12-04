// Circular Queue

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node *next;
};

struct node *tail = NULL;

void insertion_beg()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter The Element: ");
    scanf("%d",&newnode->info);

    if(tail == NULL)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void insertion_end()
{
    struct node *temp, *start = tail->next;

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter The Element: ");
    scanf("%d",&newnode->info);

    if(tail == NULL)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void insertion_spacific()
{
    int pos, len, i = 0;
    struct node *temp, *start = tail->next;

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter The Element: ");
    scanf("%d",&newnode->info);

    printf("Enter The position: ");
    scanf("%d",&pos);

    if(pos < 0 || pos > len)
    {
        printf("Invalid !!");
    }
    else if(pos == 1)
    {
        insertion_beg();
    }
    else
    {

        while(i < pos-1)
        {
            start = start->next;
            i++;
        }
        newnode->next = start->next;
        start->next = newnode;
    }

}
void delete_spacific()
{
    int pos, i=0, len;
    struct node *start = tail->next, *prev;
    if(tail == NULL)
    {
        printf("Empty !!");
    }

    printf("Enter The postion: ");
    scanf("%d",&pos);

    if(pos < 0 || pos > len)
    {
        printf("Empty");
    }
    else
    {   while(i < pos-1)
        { 
            prev = start;
            start = start->next;
            i++;
        }
        prev->next = start->next;
        free(start);
    }
}

void delition_end()
{
    struct node *prev , *current;

    if(tail == NULL)
    {
        printf("Empty !!");
    }
    else
    {
        current = tail->next;
        while(current->next != tail->next)
        {
            prev = current;
            current = current->next;
        }

        tail = prev;
        prev->next = prev->next->next;
    }
}

void delition_beg()
{
    struct node *start = tail->next;
    if(tail == NULL)
    {
        printf("Empty");
    }
    else
    {
        tail->next = start->next; 
        free(start);
    }
}

// void insertion_end()
// {
//     struct node *newnode, *temp2;
//     newnode = (struct node *)malloc(sizeof(struct node));

//     printf("Enter The Element: ");
//     scanf("%d",&newnode->info);

//     if(start == NULL)
//     {
//         start = newnode;
//         newnode->next = start;
//     }
//     else
//     {
//         temp2 = start;
//         while(temp2->next!= start)
//         {
//             temp2 = temp2->next;
//         }
//         temp2->next = newnode;
//         newnode->next = start;
//     }
// }

void display()
{
    struct node *temp;
    struct node *start = tail->next;
    if(start == NULL)
    {
        printf("linklist is Empty !!!");
    }
    else
    {
        temp = start;
        while(temp->next!=start)
        {
            printf("%d ",temp->info);
            temp = temp->next;
        }
        printf("%d ",temp->info);
    }
}

int main()
{
    insertion_beg();
    insertion_beg();
    insertion_beg();
    insertion_beg();

    display();
    delete_spacific();
   // delition_end();
    printf("\n");
    // delition_beg();
    //insertion_spacific();
    display();
}