#include <stdio.h>
#include <stdlib.h>

int main()

{
    int n, arr[50], temp;
    printf("Enter The number of Element: ");
    scanf("%d",&n);

    printf("Enter The Element: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("The Element: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    
}