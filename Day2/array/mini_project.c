#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int input, prix[100],count = 0;
    char Titre[100][100];
    char Auteur[100][100];
    int quantite[100];
    char titre_de_recher[100];

    
while(1){
  printf(
        "_______________________menu_______________________\n"
        "1-Ajouter un livre au stock.\n"
        "2-Afficher tous les livres disponibles.\n"
        "3-Rechercher un livre par son titre.\n"
        "4-Mettre à jour la quantité d'un livre.\n"
        "5-Supprimer un livre du stock.\n"
        "6-Afficher le nombre total de livres en stock.\n"
        "7-Exit\n");

    scanf("%d", &input);
    while (getchar() != '\n');
    switch (input)
    {
    case 1:
        printf("Titre du livre: ");
        fgets(Titre[count], sizeof(Titre[count]), stdin);
        printf("Auteur du livre: ");
        fgets(Auteur[count], sizeof(Auteur[count]), stdin);
        printf("Prix du livre: ");
        scanf("%d",&prix[count]);
        printf("Quantité en stock: ");
        scanf("%d",&quantite[count]);
        break;
    case 2:
        for(int i = 0;i < count;i++){
          printf(
            "Le Titre : %s"
            "L'Auteur : %s"
            "Prix : %d"
            "Quantite : %d\n",
            Titre[i], Auteur[i], prix[i], quantite[i]);
        }
        break;
    case 3:
        printf("searsh: ");
        fgets(titre_de_recher,sizeof(titre_de_recher), stdin);
        for(int i = 0; i < count;i++){
          if(strcmp(Titre[i],titre_de_recher)==0){
              printf(
              "Le Titre : %s\n"
              "L'Auteur : %s\n"
              "Prix : %d\n"
              "Quantite : %d\n",
              Titre[i], Auteur[i], prix[i], quantite[i]);
          }
        }
    case 4:
        // code;
        break;
    case 5:
        // code;
        break;
    case 6:
        // code;
        break;
    case 7:
        exit(0);
    default:
        printf("[+]Try agine.\n");
    }
    count++;
  }
}
