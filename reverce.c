#include <stdio.h>
#include <string.h>

typedef struct
{
    char first_name[50];
    char last_name[50];
    int age;
} person;

void reverce(char str[])
{
    int len = strlen(str);
    int lenght = len;
    char reverce_str[50];
    for (int i = 0; i < lenght + 1; i++)
    {
        reverce_str[i] = str[len - 1];
        len--;
    }
    strcpy(str, reverce_str);
}

int main()
{
    person people[10] = {
        {"Alice", "Smith", 25},
        {"Bob", "Johnson", 30},
        {"Charlie", "Williams", 22},
        {"David", "Brown", 28},
        {"Eve", "Jones", 24},
        {"Frank", "Garcia", 27},
        {"Grace", "Martinez", 45},
        {"Alice", "Martinez", 18},
        {"Bob", "Smith", 67},
        {"Hannah", "Smith", 23},
        {"Ian", "Johnson", 29},
        {"Julia", "Martinez", 21}};

    for (int i = 0; i < 10; i++)
    {
        reverce(people[i].first_name);
        reverce(people[i].last_name);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("First name: %s__Last name: %s___Age: %d\n", people[i].first_name, people[i].last_name, people[i].age);
    }
    return 0;
}