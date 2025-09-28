#include <stdio.h>

void max(int arr[], int size) {
    int max_num = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }
    printf("Le maximum nombre est: %d\n", max_num);
}

void min(int arr[], int len) {
    int min_num = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] < min_num) {
            min_num = arr[i];
        }
    }
    printf("Le minimum nombre est: %d\n", min_num);
}

void somme_and_moyenne(int arr[], int size) {
    int somme_num = 0;
    for (int i = 0; i < size; i++) {
        somme_num += arr[i];
    }
    printf("La somme est: %d\n", somme_num);
    printf("La moyenne est: %.2f\n", (float)somme_num /size);
}

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = ", i + 1);
        scanf("%d", &arr[i]);
    }

    max(arr,size);
    min(arr,size);
    somme_and_moyenne(arr,size);

    return 0;
}
