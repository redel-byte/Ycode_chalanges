#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

const int MAX_CONTACTS = 1000;

struct contact {
  char nom[50];
  char phone[50];
  char email[50];
};
void remove_new_line(char str[]){
  int len = strlen(str);
  if(len > 0 &&str[len -1] == '\n'){
    str[len -1] = '\0';
  }
  for(int i = 0;i<len;i++){
    if(len>0&&str[i] != '\0'){
      str[i] = tolower(str[i]);
    }
  }
}
void menu(){
  printf(
    "1. Ajouter un Contact.\n"
    "2. Modifier un Contact.\n"
    "3. Supprimer un Contact.\n"
    "4. Afficher Tous les Contacts.\n"
    "5. Rechercher un Contact.\n"
    "6. Quit.\n"
    "Choice: "
  );
}
void ajouter_contact(struct contact contacts[],int count){
  char name[50],phone[50],email[50];
  printf("Entrez le nom de contact: ");
  fgets(name,sizeof(name),stdin);
  remove_new_line(name);
  printf("Entez le numero de contact: ");
  fgets(phone,sizeof(phone),stdin);
  remove_new_line(phone);
  printf("Entrez l'email de contact: ");
  fgets(email,sizeof(email),stdin);
  remove_new_line(email);

  strcpy(contacts[count].nom,name);
  strcpy(contacts[count].phone,phone);
  strcpy(contacts[count].email,email);
  count++;
  
  printf("[+] (%s||%s||%s)-->a ete ajoute avec succes.\n",contacts[count - 1].nom,contacts[count - 1].phone,contacts[count - 1].email);
}
void modifier_contact(struct contact contacts[],int count){
    char name_buffer[50],phone_buffer[50],email_buffer[50],searching_name[50];
    int choice;
  printf("Entez le nome de Recherche: ");
  fgets(searching_name,sizeof(searching_name),stdin);
  remove_new_line(searching_name);
  for(int i = 0;i < count;i++){
    if(strcmp(contacts[i].nom,searching_name) == 0)
      printf(
        "Do you want to change:"
        " 1. Contact name."
        " 2. Contact phone."
        " 3. Contact email."
             );
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("New contact name :");
        fgets(name_buffer,sizeof(name_buffer),stdin);
        remove_new_line(name_buffer);
        strcpy(contacts[i].nom , name_buffer);
        break;
      case 2:
        printf("New contact phone number: ");
        fgets(phone_buffer,sizeof(phone_buffer),stdin);
        remove_new_line(phone_buffer);
        strcpy(contacts[i].phone,phone_buffer);
        break;
      case 3:
        printf("New contact email: ");
        fgets(email_buffer,sizeof(email_buffer),stdin);
        remove_new_line(email_buffer);
        strcpy(contacts[i].email,email_buffer);
        break;
    }
  }
}
void supprimer_contacts(struct contact contacts[],int count)
{
  char nom_suppr_buffer[50];
  printf("nome de contact a supprimer: ");
  fgets(nom_suppr_buffer,sizeof(nom_suppr_buffer),stdin);
  remove_new_line(nom_suppr_buffer);
  for(int i = 0;i< count; i++){
    if(!strcmp(contacts[i].nom,nom_suppr_buffer)){
      contacts[i]= contacts[i+1];
      count--;
      printf("[+] Le contact %s a ete supprimer.",nom_suppr_buffer);
    }
    else{
      printf("le Contact %s non trouve.",nom_suppr_buffer);
    }
  }
}
void afficher_contacts(struct contact contacts[],int count){
  for(int i =0;i < count;i++){
    printf("Contact %d:\nnome : %s || numero : %s || email : %s\n",i+1,contacts[i].nom,contacts[i].phone,contacts[i].email);
  }
}
void Rechercher_contact(struct contact contacts[],int count){
  char searching_name[50];
  printf("Rechercher: ");
  fgets(searching_name,sizeof(searching_name),stdin);
  remove_new_line(searching_name);
  for(int i = 0 ; i < count ; i++){
    if(!strcmp(contacts[i].nom, searching_name)){
      printf("name : %s|| phone: %s||email: %s",contacts[i].nom,contacts[i].phone,contacts[i].email);
    }
    else{
      printf("[!] Contact Not found.");
    }
  }
}
int main(){
  struct contact contacts[MAX_CONTACTS];
  int count = 0,input;
  char name,phone,email;

  while(1){
    menu();
    scanf("%d",&input);
    getchar();
    switch(input){
      case 1:
        ajouter_contact(contacts,count);
        break;
      case 2:
        modifier_contact(contacts,count);
        break;
      case 3:
        supprimer_contacts(contacts,count);
        break;
      case 4:
        afficher_contacts(contacts,count);
        break;
      case 5:
        Rechercher_contact(contacts,count);
        break;
      case 6:
        exit(0);
      default:
        printf("[!] Option indisponible.\n");
    }

  }
}
