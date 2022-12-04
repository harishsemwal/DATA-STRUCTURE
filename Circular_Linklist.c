//circular linklist

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *createlist(struct node *last);
void display(struct node *last);
struct node *addtoempty(struct node *last, int value);
struct node *addathbeg(struct node *last, int value);
struct node *addatend(struct node *last, int value);
struct node *addafter(struct node *last, int value);
struct node *del(struct node *last, int value);

struct node *addatend(struct node *last, int value)
{
    struct node *n;
    n = malloc(sizeof(struct node));
    n->data = value;
    n->next = last->next;
    last->next = n;
    last = n;
    return last;
}

struct node *addtoempty(struct node *last, int value)
{
    struct node *n;
    n = malloc(sizeof(struct node));
    n->data = value;
    last = n;
    last->next = last;
    return last;
}

struct node *addathbeg(struct node *last, int value)
{
    struct node *n;
    n = malloc(sizeof(struct node));
    n->data = value;
    n->next = last->next;
    last->next = n;
    return (last);
}
void dispaly(struct node *last)
{
    struct node *t;
    if (last == NULL)
    {
        printf("list is Empty");
    }
    else
    {
        t = last->next;
        do
        {
            printf("%d ", t->data);
            t = t->next;

        } while (t != last->next);
    }
}