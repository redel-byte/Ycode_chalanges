#include <stdio.h>

void main()
{
    int a;
    int b;
    int c;

    printf("num1 = ");
    scanf("%d", &a);
    printf("num2 = ");
    scanf("%d", &b);
    printf("num3 = ");
    scanf("%d", &c);

    printf("%d", a * 2 + b * 3 + c * 5 / 10);
}