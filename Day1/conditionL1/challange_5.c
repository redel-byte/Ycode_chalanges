#include<stdio.h>

int main(){

  int anne;

  printf("$_");
  scanf("%d",&anne);
  
  printf("_Mois %d\n",anne * 365/30);
  printf("_jours %d\n",anne * 365);
  printf("_Minutes %d\n",anne * 365*24*60);
  printf("_Secondes %d\n",anne * 365 * 24 * 60 *60);

}
