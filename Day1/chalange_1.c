#include <stdio.h>

void main()
{

    char name[20], addr[30], sexe[10];
    int age;

    printf("Enter your name:");
    scanf("%s", &name);
    printf("Enter your age:");
    scanf("%d", &age);
    printf("Enter your sexe:");
    scanf("%s", &sexe);
    printf("Enter your email addr:");
    scanf("%s", &addr);

    printf("hello %s\nyour age is %d\nand your sexe is %s\nyour email is %s", name, age, sexe, addr);
}