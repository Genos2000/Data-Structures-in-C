#include <stdio.h>
 
void main()
{
    int i, j, a, number1[10];
 
       printf("Enter the numbers \n");
    for (i = 0; i < 10; i++)
         {
        scanf("%d", &number1[i]);
         }
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (number1[i] > number1[j])
            {
                a =  number1[i];
                number1[i] = number1[j];
                number1[j] = a;
            }
        }
    }
    printf("The numbers arranged in ascending order are given below \n");
    for (i = 0; i < 10; ++i)
        printf("%d\n", number1[i]);
return 0;
}
