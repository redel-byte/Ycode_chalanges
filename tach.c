#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CONTACT 1000
#define MAX_PHONE_LEN 9

struct contact
{
    char name[50];
    char phone[50];
    char email[50];
};
struct contact contacts[MAX_CONTACT];

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
int check_email_true(char email[])
{
    int find_aro = 0, find_dot = 0;
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            find_aro++;
        }
        if (find_aro == 1)
        {
            int j = i;
            while (email[j] != '\0')
            {
                j++;
                if (email[j] == '.')
                    find_dot++;
            }
        }
    }
    if (find_aro != 1 && find_dot != 1)
    {
        return -1;
    }
    return 1;
}
int check_phone_true(char phone[])
{
    int len = strlen(phone);
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(phone[i]))
            return 0;

        if (len != 9)
        {
            return 0;
        }
        return 1;
    }
}

void menu()
{
    printf(
        "1. Ajouter un Contact."
        "2. Modifier un Contact."
        "3. Supprimer un Contact."
        "4. Afficher Tous les Contacts."
        "5. Rechercher un Contact."
        "6. Quit.\nChoie:");
}

void ajouter_contact(struct contact contacts[], int *count)
{
    char name[50], phone[50], email[50];

    printf("Le nome du contact: ");
    fgets(name, 50, stdin);
    remove_new_line(name);
    strcpy(contacts[*count].name, name);

    printf("Le numero du conatct: ");
    fgets(phone, 50, stdin);
    remove_new_line(phone);
    if (check_phone_true(phone))
        strcpy(contacts[*count].phone, phone);
    else
        return 0;

    printf("L'email de contact: ");
    fgets(email, 50, stdin);
    remove_new_line(email);
    if (check_email_true(email))
        strcpy(contacts[*count].email, email);
    else
        return 0;
}

void modifier_contact(struct contact contacts[], int *count)
{
    char name_search[50], phone_search[50], email_search[50];
}
int search(struct contact contacts[], int *count, int input)
{
    char name_search[50], phone_search[50], email_search[50];
    switch (input)
    {
    case 1:
        printf("Name: ");
        fgets(name_search, sizeof())
    }
}