#include <stdio.h>
#include <string.h>

#define MAX_ANIMAL 200

struct zoo
{
    char nom[50], espece[50], habitat[50];
    int age;
    float poids;
}

remove_new_line(char str[])
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}
void capitalize(char str[])
{
    int len = strlen(str);
    str[0] = toupper(str[0]);
    for (int i = 1; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }
}
void tree_nom(struct zoo animal[], int lenght)
{
    struct zoo buffer;
    int i = 0;
    char buffer[50];
    while (i < lenght - 1)
    {
        int j = 1;
        while (j < lenght)
        {
            if (strcmp(animal[i].nom, animal[i + 1].nom) > 0)
            {
                buffer = animal[i];
                animal[i] = animal[i + 1];
                animal[j] = buffer;
            }
            j++;
        }
        i++;
    }
}
void tree_age(struct zoo animal[], int lenght)
{
    struct zoo buffer;
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 1; j < lenght; j++)
        {
            if (animal[i].age > animal[j].age)
            {
                buffer = animal[i];
                animal[i] = animal[j];
                animal[j] = animal[i];
            }
        }
    }
}

int search(struct zoo animal[], int lenght, char name_search[50])
{
    for (int i = 0; i < lenght; i++)
    {
        if (!strcmp(name_search, animal[i].nom))
        {
            return i;
        }
    }
    return -1;
}
void modifier_habital(struct zoo animal[], int lenght)
{
    char name_search[50], habitat[50];
    printf("Enter animal name: ");
    fgets(name_search, sizeof(name_search), stdin);
    remove_new_line(name_search);

    int animal_indix = search(animal, lenght, name_search);
    if (animal_indix)
    {
        printf("Entez new habite d'animal: ");
        fgets(habitat, sizeof(habitat), stdin);
        remove_new_line(habitat);
        strcpy(animal[animal_indix].habitat, habitat);
        printf("habitat revoved seccufelly to %s", habitat);
    }
}
void modifier_age(struct zoo animal[], int lenght)
{
    char name_search[50];
    int new_age;
    printf("Enter animal name: ");
    fgets(name_search, sizeof(name_search), stdin);
    remove_new_line(name_search);
}