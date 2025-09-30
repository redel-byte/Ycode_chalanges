#include <ctype.h>
#include <stdio.h>

int main()
{
    char string[] = "elhabib";
    char number[] = "129485";
    char mix[] = "32h4g525345jk";

    printf("%s:%d", string, isdigit(string));
    printf("%s:%d", number, isdigit(number));
    printf("%s:%d", mix, isdigit(mix));
}
