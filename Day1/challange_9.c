#include <stdio.h>
#include <math.h>

int main()
{
    int x1, y1, z1, x2, y2, z2;
    double X, Y, Z, distance;

    printf("Ax = ");
    scanf("%d", &x1);
    printf("Bx = ");
    scanf("%d", &x2);
    printf("Ay = ");
    scanf("%d", &y1);
    printf("By = ");
    scanf("%d", &y2);
    printf("Az = ");
    scanf("%d", &z1);
    printf("Bz = ");
    scanf("%d", &z2);

    X = pow(x2 - x1, 2);
    Y = pow(y2 - y1, 2);
    Z = pow(z2 - z1, 2);


    printf("The distance between two points A and B is: %.2f\n",sqrt(X + Y + Z));

    return 0;
}

