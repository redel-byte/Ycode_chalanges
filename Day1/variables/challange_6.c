#include <stdio.h>
#include <string.h>

void main()
{

    int a;
    int b;

    printf("num1 = ");
    scanf("%d", &a);

    printf("num2 = ");
    scanf("%d", &b);

    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);
}
