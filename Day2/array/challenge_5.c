#include <stdio.h>

int main()
{

    int arr[6];
    printf("enter the value of arr[0]: ");
    scanf("%d", &arr[0]);
    printf("Enter the value of arr[1]: ");
    scanf("%d", &arr[1]);
    printf("Enter the value of arr[2]: ");
    scanf("%d", &arr[2]);
    printf("Enter the value of arr[3]: ");
    scanf("%d", &arr[3]);
    printf("enter the value of arr[4]: ");
    scanf("%d", &arr[4]);
    printf("Enter the value of arr[5]: ");
    scanf("%d", &arr[5]);
    int som = arr[0];
    for (int i = 1; i < 6; i++)
    {
        if (som > arr[i])
        {
            som = arr[i];
        }
    }
    printf("le max  num est: %d", som);
    return 0;
}