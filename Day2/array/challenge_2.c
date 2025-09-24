#include <stdio.h>

int main()
{

    int arr[5];
    printf("enter the value of arr[0]: ");
    scanf("%d", &arr[0]);
    printf("Enter the value of arr[1]: ");
    scanf("%d", &arr[1]);
    printf("[");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
        if (i < 4)
        {
            printf(", ");
        }
    }
    printf("]");
    return 0;
}