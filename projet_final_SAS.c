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
  for (int i = 0; i < lenght; i++)
  {
    for (int j = i + 1; j < lenght; j++)
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
void tree_age(struct zoo animal[], int lenght)
{
  struct zoo buffer;
  for (int i = 0; i < lenght - 1; i++)
  {
    for (int j = i + 1; j < lenght; j++)
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
  fgets(name_search, 50, stdin);

  for (int i = 0; i < count; i++)
  {
    if (!strcmp(name_search, animal[i].nom))
    {
      return i;
    }
  }
  return -1;
}
int search_espese(struct zoo animal[], int count)
{
  char espese_search[10][10] = {"savane", "jungle", "désert", "aquatique"};
  int choice, j = 1;
  printf("1. savane\n2. jungle\n3. désert\n4. aquatique.");
  scanf("%d", &choice);
  getchar();
  for (int i = 0; i < count; i++)
  {
    if (5 > choice && choice > 0)
      if (!strcmp(espese_search[choice], animal[i].espece))
      {
        printf("Animal number [%d]:\n", j);
        printf("Name: %s\n", animal[i].nom);
        printf("Type: %s\n", animal[i].espece);
        printf("Age: %d\n", animal[i].age);
        printf("Habitat: %s\n", animal[i].habitat);
        printf("weight: %.2f\n\n", animal[i].poids);
        j++;
      }
  }
}
void modifier_habital(struct zoo animal[], int lenght)
{
  char name_search[50], habitat[4][11] = {"savane", "jungle", "désert", "aquatique"};
  int choice;
  int animal_indix = search_name(animal, lenght);
  if (animal_indix)
  {
    printf("Entez new habite d'animal: \n1. savane\n3. jungle\n4. désert\n4. aquatique.");
    scanf("%d", &choice);
    getchar();
    if (choice > 0 && choice < 5)
    {
      strcpy(animal[animal_indix].habitat, habitat[choice - 1]);
      printf("habitat changed seccufelly to %s\n", habitat);
    }
    else
      printf("[!] animal not found.");
  }
}
void modifier_age(struct zoo animal[], int count)
{
  char name_search[50];
  int new_age;
  printf("Enter animal name: ");
  fgets(name_search, sizeof(name_search), stdin);
  remove_new_line(name_search);
  int index = search_name(animal, count);
  if (index)
  {
    printf("Enter new age of %s : ", animal[index].nom);
    scanf("%d", &new_age);
    while (getchar() != '\0')

      animal[index].age = new_age;
  }
  else
    printf("animal not found.");
}
void suppreme_animal(struct zoo animal[], int *count, int id)
{
  for (int i = id; i < *count - 1; i++)
  {
    animal[i] = animal[i + 1];
  }
  (*count)--;
  printf("[+] animal with id %d deleted.", id);
}
float moyenne_age(struct zoo animal[], int count)
{
  int total = animal[0].age;
  for (int i = 1; i < count; i++)
  {
    total += animal[i].age;
  }
  return (float)total / count;
}
void sort(struct zoo animal[], int count)
{
  struct zoo buffer;
  for (int i = 0; i < count; i++)
  {
    for (int j = 1; j < count; j++)
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
void statistiques(struct zoo animal[], int count)
{
  printf("Nombre total d’animaux dans le zoo est: %d\nÂge moyen des animaux est: %f\nPlus vieux est %s,et le plus jeune animal est: %s", count, moyenne_age(animal, count), animal[0].nom, animal[count - 1].nom);
}

void menu(int count)
{
  printf(
      "\n1. Ajouter un animal.\n"
      "2. Afficher les animaux.\n"
      "3. Modifier un animal.\n"
      "4. Supprimer un animal.\n"
      "5. Rechercher un animal.\n"
      "6. Statistiques.\n"
      "7. Quit.\n"
      "%dchoix: ",
      count);
}
void ajouter_animal(struct zoo animal[], int *count)
{
  char name[50], espece[10], habitat[11][11] = {"savane", "jungle", "désert", "aquatique"};
  int choice;
  float poids;

  printf("Enter the name of the animal: ");
  fgets(name, 50, stdin);
  remove_new_line(name);
  if (strlen(name) > 0)
    strcpy(animal[*count].nom, name);

  printf("Enter the type of %s: ", name);
  fgets(espece, 10, stdin);
  remove_new_line(espece);
  if (strlen(espece) > 0)
    strcpy(animal[*count].espece, espece);

  printf("Enter the age of %s %s: ", espece, name);
  scanf("%d", &animal[*count].age);
  getchar();

  printf("the habitat of the animal is:\n1. savane.\n2. jungle.\n3. desert.\n4. aquatique.\nChoice: ");
  scanf("%d", &choice);
  getchar();
  strcpy(animal[*count].habitat, habitat[choice - 1]);

  printf("Enter the weight of %s: ", name);
  scanf("%f", &poids);
  getchar();
  animal[*count].poids = poids;

  printf("Animal name :%s \ntype: %s \nhabitat: %s \nage: %d \nweight:%.2f \n added succesfelly.\n", name, espece, habitat[choice - 1], animal[*count].age, poids);
  (*count)++;
}
void afficher_animal(struct zoo animal[], int count)
{
  int choice;
  printf(
      "1. Afficher la liste complète.\n"
      "2. Trier par nom.\n"
      "3. Trier par âge.\n"
      "4. Afficher uniquement les animaux d’un habitat spécifique.\n\n");
  scanf("%d", &choice);
  getchar();
  switch (choice)
  {
  case 1:
    for (int i = 0; i < count; i++)
    {
      printf("Animal number [%d]:\n", i + 1);
      printf("Name: %s\n", animal[i].nom);
      printf("Type: %s\n", animal[i].espece);
      printf("Age: %d\n", animal[i].age);
      printf("Habitat: %s\n", animal[i].habitat);
      printf("weight: %.2f\n\n", animal[i].poids);
    }
    break;
  case 2:
    tree_nom(animal, count);
    for (int i = 0; i < count; i++)
    {
      printf("Animal number [%d]:\n", i + 1);
      printf("Name: %s\n", animal[i].nom);
      printf("Type: %s\n", animal[i].espece);
      printf("Age: %d\n", animal[i].age);
      printf("Habitat: %s\n", animal[i].habitat);
      printf("weight: %.2f\n\n", animal[i].poids);
    }
    break;
  case 3:
    tree_age(animal, count);
    for (int i = 0; i < count; i++)
    {
      printf("Animal number [%d]:\n", i + 1);
      printf("Name: %s\n", animal[i].nom);
      printf("Type: %s\n", animal[i].espece);
      printf("Age: %d\n", animal[i].age);
      printf("Habitat: %s\n", animal[i].habitat);
      printf("weight: %.2lf\n\n", animal[i].poids);
    }
    break;
  case 4:
    printf("still thinking how to make it work.\n\n");
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
          {17, "Kiki Chien", "sauvage", 7, "Savane", 25},
          {18, "Donatello", "Tortue", 40, "Rivière", 90.5},
          {19, "Polly", "Oiseau", 5, "Jungle", 1.5},
          {20, "Kong", "Gorille", 13, "Jungle", 180}};
  int count = 20, choice, id;
  while (count < MAX_ANIMAL)
  {
    menu(count);
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
      ajouter_animal(animal, &count);
      break;
    case 2:
      afficher_animal(animal, count);
      break;
    case 3:
      printf("1. Modifier l’habitat d’un animal.\n"
             "2. Modifier l’âge.\n\n");
      scanf("%d", &choice);
      getchar();
      switch (choice)
      {
      case 1:
        modifier_habital(animal, count);
        break;
      case 2:
        modifier_age(animal, count);
        break;
      }
    case 4:
      printf("Enter ID of the animal you want to delete: ");
      scanf("%d", id);
      getchar();
      suppreme_animal(animal, &count, id);
      break;
    case 5:
      printf("1. Rechercher par id.\n"
             "2. Rechercher par nom.\n"
             "3. Rechercher par espèce.\n\n");
      scanf("%d", &choice);
      getchar();
      switch (choice)
      {
      case 1:
        printf("ID: ");
        scanf("%d", &id);
        getchar();
        printf("Animal number [%d]:\n", id);
        printf("Name: %s\n", animal[id].nom);
        printf("Type: %s\n", animal[id].espece);
        printf("Age: %d\n", animal[id].age);
        printf("Habitat: %s\n", animal[id].habitat);
        printf("weight: %.2f\n\n", animal[id].poids);
        break;
      case 2:
        search_name(animal, count);
        break;
      case 3:
        search_espese(animal, count);
        break;
      }
      break;
    case 6:
      statistiques(animal, count);
      break;
    case 7:
      exit(0);
    }
  }
  printf("[!] The zoo is full of animals.");
}