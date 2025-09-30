#include <stdio.h>
#include <string.h>
#include<ctype.h>
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

int search_name(struct zoo animal[], int count, char name_search[])
{
    for (int i = 0; i < count; i++)
    {
        if (!strcmp(name_search, animal[i].nom))
        {
            return i;
        }
    }
    return -1;
}
int search_espese(struct zoo animal[],int count,char espese_search[]){
  for(int i = 0;i < count;i++){
    if(!strcmp(espese_search,animal[i].espece)) return i;
  }
  return 0;
}
void modifier_habital(struct zoo animal[], int lenght)
{
    char name_search[50], habitat[50];
    printf("Enter animal name: ");
    fgets(name_search, sizeof(name_search), stdin);
    remove_new_line(name_search);

    int animal_indix = search_name(animal, lenght, name_search);
    if (animal_indix)
    {
        printf("Entez new habite d'animal: ");
        fgets(habitat, sizeof(habitat), stdin);
        remove_new_line(habitat);
        strcpy(animal[animal_indix].habitat, habitat);
        printf("habitat removed seccufelly to %s", habitat);
    }
}
void modifier_age(struct zoo animal[], int count)
{
    char name_search[50];
    int new_age;
    printf("Enter animal name: ");
    fgets(name_search, sizeof(name_search), stdin);
    remove_new_line(name_search);
    int index = search_name(animal,count,name_search);
    if(index){
      printf("Enter new age of %s : ",animal[index].nom);
      scanf("%d",&new_age);
      while(getchar()!='\0')
      
      animal[index].age = new_age;
  }
  else printf("animal not found.");
}
void suppreme_animal(struct zoo animal[],int *count,int id){
  for(int i = id;i < *count-1;i++){
    animal[i] = animal[i+1];
  }
  *count--;
  printf("[+] animal with id %d deleted.",id);
}
float moyenn_age(struct zoo animal[],int count){
  int total = animal[0].age;
  for(int i = 1;i < count;i++){
    total+=animal[i].age;
  }
  return (float)total/count;
}
void sort(struct zoo animal[],int count){
  struct zoo buffer;
  for(int i = 0;i < count;i++){
    for(int j = 1; j < count;j++){
      if(animal[i].age > animal[j].age){
        buffer = animal[i];
        animal[i] = animal[j];
        animal[j] = buffer;
      }
    }
  }
}
void statistiques(struct zoo animal[],int count){
  printf("Nombre total d’animaux dans le zoo est: %d\nÂge moyen des animaux est: %\nPlus vieux est %s,et le plus jeune animal est: %s",count,moyenn_age(animal,count),animal[0].nom,animal[count -1].nom);
}

void menu(){
  printf(
    "1. Ajouter un animal."
    "2. Afficher les animaux."
    "3. Modifier un animal."
    "4. Supprimer un animal."
    "5. Rechercher un animal."
    "6. Statistiques."
    "choix: "
  );
}
void ajouter_animal(struct zoo animal[],int *count){
  char name[50],espece[10],habitat
  printf("Enter the name of the animal: ");

}
int main(){
  struct zoo animal[MAX_ANIMAL];
  int count = 0,choice;
  while(1){
  menu();
    scanf("%d",&choice);
  switch(choice){
      case 1:
      
    }
  }
}
