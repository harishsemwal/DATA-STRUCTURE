#include <stdio.h>
#include <stdlib.h>
int main()
{
    void **head = NULL, **temp = NULL, **ptr;

    printf("1.Insertion\n");
    printf("2.Deletion\n");
    printf("3.Display\n");
    printf("4.exit\n");

    int choice, flag = 0;
    while (1)
    {
        printf("enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (head == NULL)
            {
                ptr = temp = head = (void *)calloc(2, sizeof(void *));
            }
            else
            {
                temp[1] = (void *)calloc(2, sizeof(void *));
                temp = temp[1];
            }
            temp[0] = (int *)malloc(sizeof(int));
            printf("\nEnter an int element: ");
            scanf("%d", (int *)(temp[0]));
            temp[1] = NULL;
            break;
        case 2:
            ptr = head;
            if (head == NULL)
            {
                printf("Empty queue!");
            }
            else
            {
                head = head[1];
                free(ptr);
            }
            break;
        case 3:
            printf("\n");
            for(ptr=head;ptr!=NULL;ptr=ptr[1])
            {
				printf("%d\n",*((int*)(ptr[0])));
            }

            break;
        case 4:
            flag = 1;
            break;
        default:
            printf("invalid option!\n");
            exit(0);
            break;
        }
        if (flag == 1)
        {
            printf("exit!!");
            break;
        }
    }

    return 0;
}