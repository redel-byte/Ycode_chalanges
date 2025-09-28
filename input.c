#include<stdio.h>
#include<string.h>
#include<ctype.h>

char buffer[10000];
void input(){
  fgets(buffer,sizeof(buffer),stdin);
  if(strlen(buffer)>0 && buffer[strlen(buffer)-1]=='\n'){
    buffer[strlen(buffer)-1]='\0';
  }
  for(int i = 0;i < strlen(buffer);i++){
    buffer[i] = tolower(buffer[i]);
  }
}
int main(){
  input();
  printf("%s",buffer);
  return 0;
}
