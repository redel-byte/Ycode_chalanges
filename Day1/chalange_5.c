#include <stdio.h>

void main()
{

    int tmp;
    printf("Enter the temperature: ");
    scanf("%d", &tmp);

    if (tmp < 0)
    {
        printf("solide");
    }
    else if (tmp >= 0 && tmp < 100)
    {
        printf("liquid");
    }

    else
    {
        printf("Gaz");
    }
}