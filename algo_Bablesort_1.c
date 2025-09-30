#include <stdio.h>
#include <string.h>

void tree(int arr[], int len)
{
    int buffer;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (len > 1 && arr[j] > arr[j + 1])
            {
                buffer = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buffer;
            }
        }
    }
}
void print(int arr[], int len)
{
    printf("[");
    for (int i = 0; i < len; i++)
    {
        printf("%d", arr[i]);
        if (i < len - 1)
        {
            printf(",");
        }
    }
    printf("]");
}

int main()
{
    int len;
    printf("enter the numbers to stock in array: ");
    scanf("%d", &len);
    getchar();
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        printf("arr[%d] = ", i + 1);
        scanf("%d", &arr[i]);
        getchar();
    }
    int min = arr[0];
    print(arr, len);
    tree(arr, len);
    printf("\n");
    print(arr, len);
}