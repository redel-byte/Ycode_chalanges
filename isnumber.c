#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_ANIMAL 200

struct zoo
{
    int id;
    char nom[50];
    char espece[50];
    int age;
    char habitat[50];
    double poids;
};
void tree_nom(struct zoo animal[], int lenght)
{
    struct zoo buffer;
    int i = 0;
    for (int i = 0; i < 29; i++)
    {
        for (int j = i + 1; j < 20; j++)
        {
            if (strcmp(animal[i].nom, animal[j].nom) > 0)
            {
                buffer = animal[i];
                animal[i] = animal[j];
                animal[j] = buffer;
            }
        }
    }
}
int main()
{
    struct zoo animal[MAX_ANIMAL] =
        {
            {1, "Simba", "Lion", 5, "Savane", 190.5},
            {2, "Nala", "Lion", 4, "Savane", 175},
            {3, "ShereKhan", "Tigre", 8, "Jungle", 220.3},
            {4, "Baloo", "Ours", 12, "Forêt", 310},
            {5, "Raja", "Éléphant", 15, "Savane", 540.7},
            {6, "Marty", "Zèbre", 6, "Savane", 300.2},
            {7, "Gloria", "Hippopotame", 10, "Rivière", 450},
            {8, "Alex", "Lion", 7, "Savane", 200},
            {9, "Julien", "Lémurien", 3, "Jungle", 12.5},
            {10, "Melman", "Girafe", 9, "Savane", 390.8},
            {11, "Timon", "Suricate", 2, "Désert", 1.2},
            {12, "Pumbaa", "Phacochère", 5, "Savane", 120},
            {13, "Scar", "Lion", 11, "Savane", 210.4},
            {14, "Kaa", "Serpent", 6, "Jungle", 45},
            {15, "Iko", "Perroquet", 4, "Jungle", 2.1},
            {16, "Dumbo", "Éléphant", 3, "Savane", 320},
            {17, "Kiki	Chien", "sauvage", 7, "Savane", 25},
            {18, "Donatello", "Tortue", 40, "Rivière", 90.5},
            {19, "Polly", "Oiseau", 5, "Jungle", 1.5},
            {20, "Kong", "Gorille", 13, "Jungle", 180}};

    tree_nom(animal, 20);
    for (int i = 0; i < 20; i++)
    {
        printf("Animal number [%d]:\n", i + 1);
        printf("Name: %s\n", animal[i].nom);
        printf("Type: %s\n", animal[i].espece);
        printf("Age: %d\n", animal[i].age);
        printf("Habitat: %s\n", animal[i].habitat);
        printf("weight: %.2f\n\n", animal[i].poids);
    }
}