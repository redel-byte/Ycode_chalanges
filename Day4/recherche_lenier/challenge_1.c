#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}, num;
    printf("entez number de recherche: ");
    scanf("%d", &num);

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == num)
            printf("numbers_found: %d index: %d", num, i);
    }
}