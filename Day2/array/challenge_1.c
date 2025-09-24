#include <stdio.h>

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
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