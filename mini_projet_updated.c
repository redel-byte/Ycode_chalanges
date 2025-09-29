#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CONTACTS 1000
#define PHONE_LEN 9

struct contact {
    char nom[50];
    char phone[50];
    char email[50];
};

// --- Helpers ---
void trim_newline(char str[]) {
    int len = strlen(str);
    if(len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void to_lowercase(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int check_phone(char phone[]) {
    int len = strlen(phone);
    if(len != PHONE_LEN) return 0;
    for(int i = 0; i < len; i++) {
        if(!isdigit(phone[i])) return 0;
    }
    return 1;
}

int check_email(char email[]) {
    char *at = strchr(email, '@');
    if(!at) return 0;
    char *dot = strchr(at, '.');
    if(!dot) return 0;
    return 1;
}

void menu() {
    printf("\n=== MENU ===\n");
    printf("1. Ajouter un contact\n");
    printf("2. Modifier un contact\n");
    printf("3. Supprimer un contact\n");
    printf("4. Afficher tous les contacts\n");
    printf("5. Rechercher un contact\n");
    printf("6. Quitter\n");
    printf("Choix: ");
}

// --- Core ---
int ajouter_contact(struct contact contacts[], int count) {
    if(count >= MAX_CONTACTS) {
        printf("[!] Liste pleine.\n");
        return count;
    }

    char name[50], phone[50], email[50];

    printf("Nom: ");
    fgets(name, sizeof(name), stdin);
    trim_newline(name);
    to_lowercase(name);

    printf("Numero (9 chiffres): ");
    fgets(phone, sizeof(phone), stdin);
    trim_newline(phone);

    if(!check_phone(phone)) {
        printf("[!] Numero invalide.\n");
        return count;
    }

    printf("Email: ");
    fgets(email, sizeof(email), stdin);
    trim_newline(email);
    to_lowercase(email);

    if(!check_email(email)) {
        printf("[!] Email invalide.\n");
        return count;
    }

    strcpy(contacts[count].nom, name);
    strcpy(contacts[count].phone, phone);
    strcpy(contacts[count].email, email);

    printf("[+] Contact ajouté: %s || %s || %s\n", 
           contacts[count].nom, contacts[count].phone, contacts[count].email);

    return count + 1;
}

void afficher_contacts(struct contact contacts[], int count) {
    if(count == 0) {
        printf("[!] Aucun contact.\n");
        return;
    }
    for(int i = 0; i < count; i++) {
        printf("Contact %d: %s || %s || %s\n",
               i + 1, contacts[i].nom, contacts[i].phone, contacts[i].email);
    }
}

void rechercher_contact(struct contact contacts[], int count) {
    char search[50];
    printf("Nom a rechercher: ");
    fgets(search, sizeof(search), stdin);
    trim_newline(search);
    to_lowercase(search);

    for(int i = 0; i < count; i++) {
        if(strcmp(contacts[i].nom, search) == 0) {
            printf("[+] Trouvé: %s || %s || %s\n",
                   contacts[i].nom, contacts[i].phone, contacts[i].email);
            return;
        }
    }
    printf("[!] Contact non trouvé.\n");
}

int supprimer_contact(struct contact contacts[], int count) {
    char name[50];
    printf("Nom a supprimer: ");
    fgets(name, sizeof(name), stdin);
    trim_newline(name);
    to_lowercase(name);

    for(int i = 0; i < count; i++) {
        if(strcmp(contacts[i].nom, name) == 0) {
            for(int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            printf("[+] Contact %s supprimé.\n", name);
            return count - 1;
        }
    }
    printf("[!] Contact non trouvé.\n");
    return count;
}

int modifier_contact(struct contact contacts[], int count) {
    char name[50];
    printf("Nom du contact a modifier: ");
    fgets(name, sizeof(name), stdin);
    trim_newline(name);
    to_lowercase(name);

    for(int i = 0; i < count; i++) {
        if(strcmp(contacts[i].nom, name) == 0) {
            int choix;
            printf("1. Modifier nom\n2. Modifier numero\n3. Modifier email\nChoix: ");
            scanf("%d", &choix);
            getchar(); // nettoyer le buffer

            if(choix == 1) {
                char newname[50];
                printf("Nouveau nom: ");
                fgets(newname, sizeof(newname), stdin);
                trim_newline(newname);
                to_lowercase(newname);
                strcpy(contacts[i].nom, newname);
            } else if(choix == 2) {
                char newphone[50];
                printf("Nouveau numero: ");
                fgets(newphone, sizeof(newphone), stdin);
                trim_newline(newphone);
                if(check_phone(newphone)) {
                    strcpy(contacts[i].phone, newphone);
                } else {
                    printf("[!] Numero invalide.\n");
                }
            } else if(choix == 3) {
                char newmail[50];
                printf("Nouvel email: ");
                fgets(newmail, sizeof(newmail), stdin);
                trim_newline(newmail);
                to_lowercase(newmail);
                if(check_email(newmail)) {
                    strcpy(contacts[i].email, newmail);
                } else {
                    printf("[!] Email invalide.\n");
                }
            }
            return count;
        }
    }
    printf("[!] Contact non trouvé.\n");
    return count;
}

int main() {
    struct contact contacts[MAX_CONTACTS];
    int count = 0;
    int choix;

    while(1) {
        menu();
        if(scanf("%d", &choix) != 1) {
            printf("[!] Entrée invalide.\n");
            while(getchar() != '\n'); // vider buffer
            continue;
        }
        getchar(); // enlever le \n

        if(choix == 1) {
            count = ajouter_contact(contacts, count);
        } else if(choix == 2) {
            count = modifier_contact(contacts, count);
        } else if(choix == 3) {
            count = supprimer_contact(contacts, count);
        } else if(choix == 4) {
            afficher_contacts(contacts, count);
        } else if(choix == 5) {
            rechercher_contact(contacts, count);
        } else if(choix == 6) {
            printf("Bye!\n");
            exit(0); 
        } else {
            printf("[!] Choix invalide.\n");
        }
    }
    return 0;
}
