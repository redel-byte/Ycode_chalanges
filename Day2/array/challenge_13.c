#include<stdio.h>

float moyenne(int arr[],int len){
  float somme = 0;
  for(int i = 0;i < len;i++){
    somme+=arr[i];
  }
  return somme/=len;
}
int main(){
  int len;
  printf("total des nomber est: ");
  scanf("%d",&len);
  int arr[len];
  for(int i = 0;i < len;i++){
    printf("arr[%d]=",i+1);
    scanf("%d",&arr[i]);
  }
  printf("le moyenne est %.2f",moyenne(arr,len));
  return 0;
}
