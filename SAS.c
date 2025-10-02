#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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

void remove_new_line(char str[])
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void capitalize(char str[])
{
    int len = strlen(str);
    if (len == 0) return;
    str[0] = toupper(str[0]);
    for (int i = 1; i < len; i++)
        str[i] = tolower(str[i]);
}

void tree_nom(struct zoo animal[], int length)
{
    struct zoo buffer;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
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

void tree_age(struct zoo animal[], int length)
{
    struct zoo buffer;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (animal[i].age > animal[j].age)
            {
                buffer = animal[i];
                animal[i] = animal[j];
                animal[j] = buffer;
            }
        }
    }
}

int search_name(struct zoo animal[], int count)
{
    char name_search[50];
    printf("Enter name of the animal: ");
    fgets(name_search, sizeof(name_search), stdin);
    remove_new_line(name_search);
    capitalize(name_search);

    for (int i = 0; i < count; i++)
    {
        char buffer[50];
        strcpy(buffer, animal[i].nom);
        capitalize(buffer);
        if (strcmp(name_search, buffer) == 0)
        {
            printf("Animal found: %s (%s), id: %d\n", animal[i].nom, animal[i].espece, animal[i].id);
            return i;
        }
    }
    printf("Animal not found.\n");
    return -1;
}

void search_espece(struct zoo animal[], int count)
{
    char espece[50];
    int found = 0;
    printf("Enter species to search: ");
    fgets(espece, sizeof(espece), stdin);
    remove_new_line(espece);
    capitalize(espece);

    for (int i = 0; i < count; i++)
    {
        char buffer[50];
        strcpy(buffer, animal[i].espece);
        capitalize(buffer);
        if (strcmp(buffer, espece) == 0)
        {
            printf("[%d] %s (%s) || Age: %d || Habitat: %s || Poids: %.2f\n",
                   animal[i].id, animal[i].nom, animal[i].espece, animal[i].age,
                   animal[i].habitat, animal[i].poids);
            found = 1;
        }
    }
    if (!found) printf("No animals found for species %s.\n", espece);
}

void modifier_habitat(struct zoo animal[], int count)
{
    int index = search_name(animal, count);
    if (index == -1) return;

    printf("Enter new habitat for %s: ", animal[index].nom);
    fgets(animal[index].habitat, sizeof(animal[index].habitat), stdin);
    remove_new_line(animal[index].habitat);
    capitalize(animal[index].habitat);

    printf("Habitat changed successfully to %s\n", animal[index].habitat);
}

void modifier_age(struct zoo animal[], int count)
{
    int index = search_name(animal, count);
    if (index == -1) return;

    int new_age;
    printf("Enter new age of %s: ", animal[index].nom);
    scanf("%d", &new_age);
    getchar();
    animal[index].age = new_age;
    printf("Age updated.\n");
}

void supprimer_animal(struct zoo animal[], int *count, int index)
{
    if (index < 0 || index >= *count)
    {
        printf("[!] Invalid id.\n");
        return;
    }
    for (int i = index; i < *count - 1; i++)
    {
        animal[i] = animal[i + 1];
        animal[i].id = i + 1;
    }
    (*count)--;
    printf("[+] Deleted.");
}

float moyenne_age(struct zoo animal[], int count)
{
    int total = 0;
    for (int i = 0; i < count; i++) total += animal[i].age;
    return (float)total / count;
}

void statistiques(struct zoo animal[], int count)
{
    if (count == 0)
    {
        printf("No animals.\n");
        return;
    }
    tree_age(animal, count);
    printf("Nombre total d'animaux: %d\n", count);
    printf("Age moyen: %.2f\n", moyenne_age(animal, count));
    printf("Plus jeune: %s (age %d)\n", animal[0].nom, animal[0].age);
    printf("Plus vieux: %s (age %d)\n", animal[count - 1].nom, animal[count - 1].age);

    int max = 0;
    char espece_max[50];
    for (int i = 0; i < count; i++)
    {
        int occ = 0;
        for (int j = 0; j < count; j++)
        {
            if (strcmp(animal[i].espece, animal[j].espece) == 0)
                occ++;
        }
        if (occ > max)
        {
            max = occ;
            strcpy(espece_max, animal[i].espece);
        }
    }
    printf("Espece la plus representee: %s (%d animaux)\n", espece_max, max);
}

void ajouter_animal(struct zoo animal[], int *count)
{
    if (*count >= MAX_ANIMAL)
    {
        printf("[!] Zoo is full.\n");
        return;
    }

    printf("Enter the name: ");
    fgets(animal[*count].nom, sizeof(animal[*count].nom), stdin);
    remove_new_line(animal[*count].nom);
    capitalize(animal[*count].nom);

    printf("Enter species: ");
    fgets(animal[*count].espece, sizeof(animal[*count].espece), stdin);
    remove_new_line(animal[*count].espece);
    capitalize(animal[*count].espece);

    printf("Enter age: ");
    scanf("%d", &animal[*count].age);
    getchar();

    printf("Enter habitat: ");
    fgets(animal[*count].habitat, sizeof(animal[*count].habitat), stdin);
    remove_new_line(animal[*count].habitat);
    capitalize(animal[*count].habitat);

    printf("Enter weight: ");
    scanf("%lf", &animal[*count].poids);
    getchar();

    animal[*count].id = (*count) + 1;
    (*count)++;
    printf("Animal added!\n");
}

void ajouter_animaux_multiple(struct zoo animal[], int *count)
{
    int num;
    printf("How many animals to add? ");
    scanf("%d", &num);
    getchar();
    for (int i = 0; i < num; i++)
    {
        printf("\n___ Adding animal %d ___\n", i + 1);
        ajouter_animal(animal, count);
    }
}

void afficher_animaux(struct zoo animal[], int count)
{
    int choice;
    printf("1. Liste complete\n2. Trier par nom\n3. Trier par age\nChoice: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 2) tree_nom(animal, count);
    else if (choice == 3) tree_age(animal, count);

    for (int i = 0; i < count; i++)
    {
        printf("[%d] %s (%s) || Age: %d || Habitat: %s || Poids: %.2f\n",
               animal[i].id, animal[i].nom, animal[i].espece, animal[i].age,
               animal[i].habitat, animal[i].poids);
    }
}

void menu()
{
    printf("\n1. Ajouter un animal\n");
    printf("2. Ajouter plusieurs animaux\n");
    printf("3. Afficher les animaux\n");
    printf("4. Modifier un animal\n");
    printf("5. Supprimer un animal\n");
    printf("6. Rechercher un animal\n");
    printf("7. Statistiques\n");
    printf("8. Quit\n");
    printf("Choix: ");
}

int main()
{
    struct zoo animal[MAX_ANIMAL] = {
        {1, "Simba", "Lion", 5, "Savane", 190.5},
        {2, "Nala", "Lion", 4, "Savane", 175},
        {3, "ShereKhan", "Tigre", 8, "Jungle", 220.3},
        {4, "Baloo", "Ours", 12, "Foret", 310},
        {5, "Raja", "Elephant", 15, "Savane", 540.7},
        {6, "Marty", "Zebre", 6, "Savane", 300.2},
        {7, "Gloria", "Hippopotame", 10, "Riviere", 450},
        {8, "Alex", "Lion", 7, "Savane", 200},
        {9, "Julien", "Lemurien", 3, "Jungle", 12.5},
        {10, "Melman", "Girafe", 9, "Savane", 390.8},
        {11, "Timon", "Suricate", 2, "Desert", 1.2},
        {12, "Pumbaa", "Phacochere", 5, "Savane", 120},
        {13, "Scar", "Lion", 11, "Savane", 210.4},
        {14, "Kaa", "Serpent", 6, "Jungle", 45},
        {15, "Iko", "Perroquet", 4, "Jungle", 2.1},
        {16, "Dumbo", "Elephant", 3, "Savane", 320},
        {17, "Kiki", "Chien", 7, "Savane", 25},
        {18, "Donatello", "Tortue", 40, "Riviere", 90.5},
        {19, "Polly", "Oiseau", 5, "Jungle", 1.5},
        {20, "Kong", "Gorille", 13, "Jungle", 180}
    };
    int count = 20;
    int choix;

    while (1)
    {
        menu();
        scanf("%d", &choix);
        getchar();

        switch (choix)
        {
        case 1: ajouter_animal(animal, &count); break;
        case 2: ajouter_animaux_multiple(animal, &count); break;
        case 3: afficher_animaux(animal, count); break;
        case 4:
            printf("1. Modifier habitat\n2. Modifier age\nChoix: ");
            scanf("%d", &choix);
            getchar();
            if (choix == 1) modifier_habitat(animal, count);
            else if (choix == 2) modifier_age(animal, count);
            break;
        case 5:
            printf("Enter ID to delete: ");
            scanf("%d", &choix);
            getchar();
            supprimer_animal(animal, &count, choix - 1);
            break;
        case 6:
            printf("1. Rechercher par id\n2. Rechercher par nom\n3. Rechercher par espèce\nChoix: ");
            scanf("%d", &choix);
            getchar();
            if (choix == 1)
            {
                int id;
                printf("ID: ");
                scanf("%d", &id);
                getchar();
                if (id >= 1 && id <= count)
                    printf("[%d] %s (%s) || Age: %d || Habitat: %s || Poids: %.2f\n",
                           id, animal[id - 1].nom, animal[id - 1].espece,
                           animal[id - 1].age, animal[id - 1].habitat,
                           animal[id - 1].poids);
                else printf("Invalid ID.\n");
            }
            else if (choix == 2) search_name(animal, count);
            else if (choix == 3) search_espece(animal, count);
            break;
        case 7: statistiques(animal, count); break;
        case 8: exit(0);
        default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
