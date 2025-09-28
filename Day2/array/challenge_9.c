#include<stdio.h>

void reverse(int numbers[], int length) {
    int num_buffer;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (numbers[j] < numbers[j + 1]) {
                num_buffer = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = num_buffer;
            }
        }
    }
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    int numbers[n];
    for (int i = 0; i < n; i++) {
        printf("numbers[%d] = ", i + 1);
        scanf("%d", &numbers[i]);
    }

    reverse(numbers, n);

    printf("\nreversed numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
