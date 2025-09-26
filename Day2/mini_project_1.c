#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void remove_newline(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}
int menu(){
    int input;
      printf(
            "\n_______________________menu_______________________\n"
            "1- Ajouter un livre au stock.\n"
            "2- Afficher tous les livres disponibles.\n"
            "3- Rechercher un livre par son titre.\n"
            "4- Mettre à jour la quantité d'un livre.\n"
            "5- Supprimer un livre du stock.\n"
            "6- Afficher le nombre total de livres en stock.\n"
            "7- Exit\n"
            "Choix: ");
        scanf("%d", &input);
        while(getchar() != '\0');
  return input;
}
int main() {
    int input , prix[100], count = 0;
    char Titre[100][100];
    char Auteur[100][100];
    int quantite[100], new_quantite;
    char titre_recher[100], new_titre[100];
    char buffer_titre[100][100], buffer_auteur[100][100];
    int buffer_prix[100], buffer_quantite[100];
    while (1) {
        input = menu();
        switch (input) {
        case 1: 
            printf("Titre du livre: ");
            fgets(Titre[count], sizeof(Titre[count]), stdin);
            remove_newline(Titre[count]);
            printf("Auteur du livre: ");
            fgets(Auteur[count], sizeof(Auteur[count]), stdin);
            remove_newline(Auteur[count]);
            printf("Prix du livre: ");
            scanf("%d", &prix[count]);
            printf("Quantité en stock: ");
            scanf("%d", &quantite[count]);
            while (getchar() != '\n');
            count++;
            break;
        case 2: 
            if (count == 0) {
                printf("[!] aucun livr disponibl.\n");
            } else {
                for (int i = 0; i < count; i++) {
                    printf("\nLivre %d:\n", i + 1);
                    printf("  Titre   : %s\n", Titre[i]);
                    printf("  Auteur  : %s\n", Auteur[i]);
                    printf("  Prix    : %d\n", prix[i]);
                    printf("  Quantité: %d\n", quantite[i]);
                }
            }
            break;
        case 3:
            printf("[+]rechercher: ");
            fgets(titre_recher, sizeof(titre_recher), stdin);
            remove_newline(titre_recher);
            for (int i = 0; i < count; i++) {
                if (strcmp(Titre[i], titre_recher) == 0) {
                    printf("\n[+] Livre trouvé:\n");
                    printf("  Titre   : %s\n", Titre[i]);
                    printf("  Auteur  : %s\n", Auteur[i]);
                    printf("  Prix    : %d\n", prix[i]);
                    printf("  Quantité: %d\n", quantite[i]);
                    
                    break;
                }
            }
            break;
        case 4:
            printf("Titre du livre: ");
            fgets(new_titre, sizeof(new_titre), stdin);
            remove_newline(new_titre);
            for (int i = 0; i < count; i++) {
                if (strcmp(Titre[i], new_titre) == 0) {
                    printf("Nouvou quantite: ");
                    scanf("%d", &new_quantite);
                    while (getchar() != '\n');
                    quantite[i] = new_quantite;
                    printf("[+]quantite updated.\n");
                    break;
                }
            }
            break;
        case 5: 
            printf("titre de livre to supprimer: ");
            fgets(new_titre, sizeof(new_titre), stdin);
            remove_newline(new_titre);
            int j = 0,skip = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(Titre[i], new_titre) == 0) {
                    skip++;
                    continue;
                }
                strcpy(buffer_titre[j], Titre[i]);
                strcpy(buffer_auteur[j], Auteur[i]);
                buffer_prix[j] = prix[i];
                buffer_quantite[j] = quantite[i];
                j++;
            }
            if (skip) {
                count = j;
                for (int i = 0; i < count; i++) {
                    strcpy(Titre[i], buffer_titre[i]);
                    strcpy(Auteur[i], buffer_auteur[i]);
                    prix[i] = buffer_prix[i];
                    quantite[i] = buffer_quantite[i];
                }
                printf("[+]Livre supprime.\n");
            } else {
                printf("[!] Livre non trouve.\n");
            }
            break;
        case 6: 
            printf("le bombre total de Livres en stock est: %d\n", count);
            break;
        case 7:
            exit(0);
        default:
            printf("[!]invalide Choix.\n");
        }
    }
}
