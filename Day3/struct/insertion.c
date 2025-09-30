#include <stdio.h>

void insertion(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {1, 4, 3, 5, 6, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    print(arr, len);
    insertion(arr, len);
    printf("\n");
    print(arr, len);
}