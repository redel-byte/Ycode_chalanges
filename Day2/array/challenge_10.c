#include<stdio.h>

int search(int arr[],int len,int nbr_rech){
  for(int i = 0 ; i < len; i++){
    if(arr[i] == nbr_rech){
      return arr[i];
    }
  }
    return 2126458849;
}
int main(){
  int index, nbr_rech;
  printf("max_index = ");
  scanf("%d",&index);
  int arr[index];
  printf("le nomber de recherch est : ");
  scanf("%d",&nbr_rech);
  for(int i = 0 ;i<index;i++){
    printf("arr[%d]=",i+1);
    scanf("%d",&arr[i]);
  }

  int resutl = search(arr,index,nbr_rech);
  if (resutl ==2126458849 ){
    printf("[!] Not found.");
  }
  else{
    printf("nbr_rech found:  %d",resutl);
  }
}
