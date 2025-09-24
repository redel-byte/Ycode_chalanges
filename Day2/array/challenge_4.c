#include <stdio.h>

int main()
{
    int size;
    int arr[size];
    int i = 0;
    printf("enter the size of array: ");
    scanf("%d", &size);

    while (i < size)
    {
        printf("arr[%d]", i);
        scanf("%d", &arr[i]);
        i++;
    }
    int som = arr[0];
    for (int i = 0; i < 6; i++)
    {
        if (som < arr[i])
        {
            som = arr[i];
        }
    }
    printf("le max  num est: %d", som);
    return 0;
}