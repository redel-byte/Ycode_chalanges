#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int buffer = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > cle)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cle;
    }
}

void afficher(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
}

int main()
{
    int arr[] = {8, 4, 3, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Avant tri: ");
    afficher(arr, n);

    insertionSort(arr, n);

    printf("Apres tri (Insertion): ");
    afficher(arr, n);

    return 0;
}