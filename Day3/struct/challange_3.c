#include<stdio.h>
#include<string.h>


struct rectange{
  int longueur, largeur;
};


int aire(int l,int L){
  return (float)l*L;
}
int main(){
  struct rectange r;
  printf("longuuer: ");
  scanf("%d",&r.longueur);
  printf("largeur: ");
  scanf("%d",&r.largeur);
  printf("l'aire de rectange est: %i",aire(r.largeur,r.longueur));
}
