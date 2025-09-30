#include <stdio.h>

int linearSearch(int arr[], int len, int target)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1
}
int binarySearch(int arr[], int len, int target)
{
    int left = 0, right = len - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; //
        }
        else
        {
            right = mid - 1;
        }
        return -1;
    }

    int main()
    {
        int arr[] = {1, 3, 5, 7, 9, 11, 13};
        int len = sizeof(arr) / sizeof(arr[0]);
        int target;

        printf("");
        scanf("%d", &target);

        //
        int linearResult = linearSearch(arr, len, target);
        if (linearResult != -1)
            printf("%d\n", linearResult);
        else
            printf("\n");

        int binaryResult = binarySearch(arr, len, target);
        if (binaryResult != -1)
            printf("%d\n", binaryResult);
        else
            printf();

        return 0;
    }