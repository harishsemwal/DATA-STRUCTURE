// Queue
#include <stdio.h>
#include <stdlib.h>

struct arrayQueue
{
    int front, rear;
    int capacity;
    int *array;
};
struct arrayQueue *Q = NULL;
struct arrayQueue *createQueue(int capacity)
{
    struct arrayQueue *Q = (struct arrayQueue *)malloc(sizeof(struct arrayQueue));
    if (Q != NULL)
    {
        return NULL;
    }
    Q->capacity = capacity;
    Q->front = Q->rear = -1;

    Q->array = malloc(Q->capacity * sizeof(int));

    if (!Q->array)
    {
        return NULL;
    }
    return Q;
}

int isEmptyQueue(struct arrayQueue *Q)
{
    return (Q->front == -1);
}

int isFullQueue(struct arrayQueue *Q)
{
    return ((Q->rear + 1) % Q->capacity == Q->front);
}

int Queuesize(struct arrayQueue *Q)
{
    return ((Q->capacity - Q->front + Q->rear + 1) % Q->capacity);
}

void insertion()
{
    int data;
    printf("Enter The Element: ");
    scanf("%d",&data);

    if (isFullQueue(Q))
    {
        printf("OverFlow\n");
    }
    else
    {
        Q->rear = (Q->rear + 1) % Q->capacity;
        Q->array[Q->rear] = data;
        if (Q->front == -1)
        {
            Q->front = Q->rear;
        }
    }
}

int deQueue()
{
    int data = -1;
    if (isEmptyQueue(Q))
    {
        printf("Queue is Empty !!\n");
        return -1;
    }
    else
    {
        data = Q->array[Q->front];
        if (Q->front == Q->rear)
        {
            Q->front = Q->rear = -1;
        }
        else
        {
            Q->front = (Q->front + 1) % Q->capacity;
        }
        return data;
    }
}

void deleteQueue()
{
    if (Q)
    {
        if (Q->array)
        {
            free(Q->array);
        }
        free(Q);
    }
}

int menu()
{
    int choice;
    printf("\n\nPlease choese The one choice at a Time: \n\n");
    printf("5 -> : Insertion in Queue:\n");
    printf("6 -> : Delition in Queue: \n");
    printf("7 -> : Delete Complete Node: \n");
    printf("Enter The Best Choice: \n");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    while (1)
    {
        switch (menu())
        {
        case 5:
            insertion();
            break;
        case 6:
            deQueue();
            break;
        case 7:
            deleteQueue();
            break;
        default:
            printf("\n\nInvalid Choice !!");
            break;
        }
    }
}