// remove duplicate Element from an array

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, arr[50];

    printf("Enter The number of Element: ");
    scanf("%d",&n);

    printf("Enter The Elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);

    }

    for(int i = 0; i < n-1 ; i++)
    {
        for (int j = i + 1; j < n ; j++)
        {
            if(arr[i] == arr[j])
            {
                for(int k = j; k < n ; k++)
                {
                    arr[k] = arr[k+1];
                }
                n--;
                j--;
            }
        }
        
    }

    printf("The Elements: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}