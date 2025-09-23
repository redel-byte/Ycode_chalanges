#include <stdio.h>
#include <math.h>

void main()
{

    int a, b, c;

    printf("point1 = ");
    scanf("%d", &a);
    printf("point2 = ");
    scanf("%d", &b);
    printf("point3 = ");
    scanf("%d", &c);
    printf("le Moyenne géométrique est %d", pow((a * b * c), (1 / 3)));
}