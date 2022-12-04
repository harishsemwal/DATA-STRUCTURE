#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

// Insertion In Frist node

void insertionFirst(struct node **start, int data)
{
    struct node *newPtr;
    newPtr = (struct node *)malloc(sizeof(struct node));

    newPtr->info = data;
    newPtr->prev = NULL;
    if (*start == NULL)
    {
        newPtr->next = NULL;
    }
    *start = newPtr;
}

// Insertion In Last node

void InsertionLast(struct node **start, int data)
{
    struct node *newPtr, *temp;
    newPtr = (struct node *)malloc(sizeof(struct node));

    newPtr->info = data;
    newPtr->next = NULL;

    if (*start == NULL)
    {
        newPtr->prev = NULL;
        *start = newPtr;
    }
    else
    {
        temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        newPtr->prev = temp;
        temp->next = newPtr;
    }
}

// For Searching Element

struct node *matchInfo(struct node **start, int data)
{
    struct node *temp;
    if (*start == NULL)
    {
        return NULL;
    }
    else
    {
        temp = *start;
        while (temp->next != NULL)
        {
            if (temp->info == data)
            {
                return (temp);
            }
            temp = temp->next;
        }
    }
}

// Insert Element In Intermidiate In Dobly Linklist

void insertion_intermidiate(struct node **start, struct node *infoptr, int data)
{
    if (infoptr == NULL)
    {
        printf("Invalid Insertion");
    }
    else
    {
        struct node *newptr;
        newptr = (struct node *)malloc(sizeof(struct node));
        newptr->info = data;
        newptr->prev = infoptr;
        newptr->next = infoptr->next;

        if (infoptr->next != NULL)
        {
            infoptr->next->prev = newptr;
        }
        infoptr->next = newptr;
    }
}

// Delition First node in Dobly Linklist.

void deletionFirst(struct node **start)
{
    struct node *temp;
    temp = *start;
    if (*start == NULL)
    {
        printf("Delition is not possible !!");
    }
    else
    {
        *start = (*start)->next;
        (*start)->prev = NULL;
        free(temp);
    }
}

int deletionLast(struct node **start)
{
    struct node *temp;
    temp = *start;
    if (start == NULL)
    {
        printf("Delition is not possible !!\n");
    }
    else
    {
        if ((*start)->next == NULL)
        {
            *start = NULL;
            return 0;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            return temp;
        }
    }
}

void deletionIntermidiate(struct node **start, struct node *infoPtr)
{
    if (*start == NULL)
    {
        printf("Delition is not posible !!\n");
    }
    else
    {
        if ((*start)->next == NULL)
        {
            *start = NULL;
        }
        else
        {
            while ((*start)->next != NULL)
            {
                if ((*start)->next == infoPtr)
                {
                    infoPtr->prev->next = infoPtr->next;
                    infoPtr->next->prev = infoPtr->prev;
                }
                *start = (*start)->next;
            }
        }
    }
}

void viewList(struct node **start)
{
    struct node *temp;
    
    if(*start == NULL)
    {
        printf("List is Empty !!\n");
    }
    else
    {
        temp = start;
        while(temp->next!=NULL)
        {
            printf("%d ",temp->info);
            temp = temp->next;
        }
    }
}

int main()
{
    struct node *start = NULL;
    struct node *infoPtr;

    // Insertion Operations

    insertionFirst(&start, 15);
    insertionLast(&start, 10);
    infoPtr = matchInfo(&start, 15);
    insertion_intermidiate(&start, infoPtr, 18);

    // Deletetion Operations

    deletionFirst(&start);
    deletionLast(&start);
    deletionIntermidiate(&start, infoPtr);

    // To Display The Linklist

    viewList(&start);
    getList(&start);
}