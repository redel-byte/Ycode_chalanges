#include<stdio.h>

void remplacer(int arr[],int len,int new_value,int old_value){
  for(int i = 0; i < len; i++){
    if(arr[i] == old_value){
      arr[i] = new_value;
    }
  }
}

int main(){
  int total_numbers;
  printf("total numbers is: ");
  scanf("%d",&total_numbers);
  int arr[total_numbers],new_value,old_value;
  for(int i = 0; i < total_numbers;i++){
    printf("l'element de tableau:\n");
    printf("arr[%d]=",i+1);
    scanf("%d",&arr[i]);
  }
  printf("number a remplacer: ");
  scanf("%d",&old_value);
  printf("nomber de remplacer: ");
  scanf("%d",&new_value);
  
  remplacer(arr,total_numbers,new_value,old_value);
  printf("[");
  for(int i = 0;i < total_numbers;i++){
    printf("%d",arr[i]);
    if(i < total_numbers -1){
      printf(",");
    }
  }
  printf("]");
}
