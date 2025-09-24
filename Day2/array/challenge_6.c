#include <stdio.h>

int main()
{

    int facteur;
    int a;
    int i = 0;
    printf("Enter the value of the [facteur]: ");
    scanf("%d", &facteur);
    printf("Enter the value of thr index: ");
    scanf("%d", &a);
    int arr[a];
    while (i < a)
    {
        printf("enter the value of arr[%d]:", i);
        scanf("%d", &arr[i]);
        i++;
    }

    for (int i = 0; i < a; i++)
    {
        arr[i] *= facteur;
        printf("%d\n", arr[i]);
    }
    return 0;
}