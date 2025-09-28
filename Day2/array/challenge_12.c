#include<stdio.h>

int paire_impaire(int num){
    if (num % 2 == 0){
      return 0;
    }
    return 1; 
  }
int main(){
  int index;
  printf("Total numbers : ");
  scanf("%d",&index);
  int arr[index];
  for(int i = 0;i < index; i++){
    printf("arr[%d]= ",i+1);
    scanf("%d",&arr[i]);
  }
  for(int i = 0; i< index; i++){
    int result = paire_impaire(arr[i]);
    if(result == 0){
      printf("le nember [%d] est paire.\n",arr[i]);
    }
    else{
      printf("le nember [%d] est impaire.\n",arr[i]);
    }
  }
}
