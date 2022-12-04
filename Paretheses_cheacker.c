// Implementing parentheses cheacker.

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 int main()
 {
        int flag = 1, top = -1, i;
        char stack[5];
        char temp;
        char str[50];
        printf("Etner The string: ");
        gets(str);
        
        for (i = 0; i < strlen(str); i++)
        {
            if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            {
                top++;
                stack[top] = str[i];
            }

            if(str[i] == ')' || str[i] == ']' || str[i] == '}')
            {
                if(top == -1)
                {
                    flag = 0;
                }
                else
                {
                    temp = stack[top];
                    top--;
                    
                    if((str[i] == ')') && (temp == '{' || temp == '['))
                    {
                        flag = 0;
                    }
                    if((str[i] == ']') && (temp == '(' || temp == '{'))
                    {
                        flag = 0;
                    }
                    if((str[i] == '}') && (temp == '(' || temp == '['))
                    {
                        flag = 0;
                    }
                }
            }
        }
        
        if(top >= 0)
        {
            flag = 0;
        }
        if(flag == 1)
        {
            printf("Valid");
        }
        else
        {
            printf("Invalid");
        }
    }
    
    
//     for (int i = 0; i < strlen(str); i++)
//     {
//         if (str[i] == '(' || str[i] == '[' || str[i] == '{')
//         {
//             top++;
//             stack[top] = str[i];
//         }
//         if (str[i] == ')' || str[i] == ']' || str[i] == '}')
//         {
//             if (top == -1)
//             {
//                 flag = 0;
//             }
//             else
//             {
//                 temp = stack[top];
//                 top--;

//                 if (str[i] == ')' && (temp == '[' || temp == '{'))
//                 {
//                     flag = 0;
//                 }
//                 if (str[i] == '}' && (temp == '(' || temp == '['))
//                 {
//                     flag = 0;
//                 }
//                 if (str[i] == ']' && (temp == '(' || temp == '{'))
//                 {
//                     flag = 0;
//                 }
//             }
//         }
//     }
//     if (top >= 0)
//     {
//         flag = 0;
//     }
//     if (flag == 1)
//     {
//         printf("\nValid Expression !!");
//     }
//     else
//     {
//         printf("Invalid Expression !!");
//     }
// }