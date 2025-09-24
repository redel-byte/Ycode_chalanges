#include <stdio.h>

int main()
{
    int som = 0;
    int arr[4];
    printf("enter the value of arr[0]: ");
    scanf("%d", &arr[0]);
    printf("Enter the value of arr[1]: ");
    scanf("%d", &arr[1]);
    printf("Enter the value of arr[2]: ");
    scanf("%d", &arr[2]);
    printf("Enter the value of arr[3]: ");
    scanf("%d", &arr[3]);

    for (int i = 0; i < 4; i++)
    {
        som += arr[i];
    }
    printf("[");
    printf("%d", som);
    printf("]");
    return 0;
}