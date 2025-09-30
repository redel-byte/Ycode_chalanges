#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const int MAX_CONTACT = 1000;
int count = 0;

struct contact
{
    char name[50];
    char phone[50];
    char email[50];
};

void remove_new_line_and_lowercase(char str[])
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
    for (int i = 0; i < len; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void menu()
{
    printf(
        "1. Ajouter un Contact\n"
        "2. Modifier un Contact\n"
        "3. Supprimer un Contact\n"
        "4. Afficher Tous les Contacts\n"
        "5. Rechercher un Contact\n"
        "6. Quitter\n");
}

void ajoute_contact(struct contact contacts[])
{
    char name[50], phone[50], email[50];
    printf("Name of the contact: ");
    fgets(name, sizeof(name), stdin);
    remove_new_line_and_lowercase(name);
    printf("phone of the contact: ");
    fgets(phone, sizeof(phone), stdin);
    remove_new_line_and_lowercase(phone);
    printf("email of the contact: ");
    fgets(email, sizeof(email), stdin);
    remove_new_line_and_lowercase(email);

    strcpy(contacts[count].name, name);
    strcpy(contacts[count].phone, phone);
    strcpy(contacts[count].email, email);

    printf("[+] The contact: (Name: %s||Phone: %s||Email: %s)\nadded successfully.\n",
           contacts[count].name,
           contacts[count].phone,
           contacts[count].email);

    count++;
}

void modifier_contact(struct contact contacts[])
{
    char shearching_name[50], new_name[50], new_phone[50], new_email[50], choice;
    int found = 0;
    printf("Enter the name of the contact you want to modify:\n");
    fgets(shearching_name, sizeof(shearching_name), stdin);
    remove_new_line_and_lowercase(shearching_name);
    for (int i = 0; i < count; i++)
    {
        if (!strcmp(shearching_name, contacts[i].name))
        {
            found = 1;

            printf("Do you want to change The contact name[Y/N]: ");
            scanf(" %c", &choice);
            choice = tolower(choice);
            getchar();
            if (choice == 'y')
            {
                printf("New Name: ");
                fgets(new_name, sizeof(new_name), stdin);
                remove_new_line_and_lowercase(new_name);
                strcpy(contacts[i].name, new_name);
            }

            printf("Do you want to change the contact phone number[y/n]: ");
            scanf(" %c", &choice);
            choice = tolower(choice);
            getchar();
            if (choice == 'y')
            {
                printf("New phone: ");
                fgets(new_phone, sizeof(new_phone), stdin);
                remove_new_line_and_lowercase(new_phone);
                strcpy(contacts[i].phone, new_phone);
            }

            printf("Do you want to change the contact email[Y/N]: ");
            scanf(" %c", &choice);
            choice = tolower(choice);
            getchar();
            if (choice == 'y')
            {
                printf("New email: ");
                fgets(new_email, sizeof(new_email), stdin);
                remove_new_line_and_lowercase(new_email);
                strcpy(contacts[i].email, new_email);
            }
            return;
        }
    }
    if (!found)
    {
        printf("[!] Contact not found.\n");
    }
}

void suppreme_contact(struct contact contacts[])
{
    char searching_name[50];
    printf("Enter the name of the contact you want to delete: ");
    fgets(searching_name, sizeof(searching_name), stdin);
    remove_new_line_and_lowercase(searching_name);

    for (int i = 0; i < count; i++)
    {
        if (!strcmp(searching_name, contacts[i].name))
        {
            for (int j = i; j < count - 1; j++)
            {
                contacts[j] = contacts[j + 1];
            }
            count--;
            printf("[+] Contact deleted.\n");
            return;
        }
    }
    printf("[!] Contact not found.\n");
}

void afficher_contacts(struct contact contacts[])
{
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s||Phone: %s||Email: %s\n",
               contacts[i].name,
               contacts[i].phone,
               contacts[i].email);
    }
}

void rechercher_contact(struct contact contacts[])
{
    char searching_name[50];
    printf("searching: ");
    fgets(searching_name, sizeof(searching_name), stdin);
    remove_new_line_and_lowercase(searching_name);
    for (int i = 0; i < count; i++)
    {
        if (!strcmp(searching_name, contacts[i].name))
        {
            printf("[+] Contact found.\n");
            printf("%s||%s||%s\n",
                   contacts[i].name,
                   contacts[i].phone,
                   contacts[i].email);
            return;
        }
    }
    printf("[!] Contact not found.\n");
}

int main()
{
    int choice;
    struct contact contacts[MAX_CONTACT];
    while (1)
    {
        menu();
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            ajoute_contact(contacts);
            break;
        case 2:
            modifier_contact(contacts);
            break;
        case 3:
            suppreme_contact(contacts);
            break;
        case 4:
            afficher_contacts(contacts);
            break;
        case 5:
            rechercher_contact(contacts);
            break;
        case 6:
            exit(0);
        default:
            printf("[!] Invalid choice.\n");
        }
    }
}