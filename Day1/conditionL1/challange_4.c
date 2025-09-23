#include <stdio.h>
#include <math.h>

int main() {
    double a;
    double b;
    double c;
    double Delta;

    printf("__To calculate Delta__\n"); 
    printf("Enter the value of A: ");
    scanf("%lf", &a);
    printf("Enter the value of B: ");
    scanf("%lf", &b);
    printf("Enter the value of C: ");
    scanf("%lf", &c);
  
    Delta = pow(b, 2) - 4 * a * c;
    printf("Delta = %lf\n", Delta);

    if (Delta > 0) {
        printf("L'equation admet deux solutions:\n");
        printf("X1 = %.2lf\n", (-b + sqrt(Delta)) / (2 * a));
        printf("X2 = %.2lf\n", (-b - sqrt(Delta)) / (2 * a));
    } 
    else if (Delta == 0) {
        printf("L'equation admet une solution: X = %.2lf\n", -b / (2 * a));
    } 
    else {
        printf("L'equation n'admet aucun solution relle.\n");
    }

    return 0;
}
