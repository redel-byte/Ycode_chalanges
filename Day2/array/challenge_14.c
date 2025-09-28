#include<stdio.h>

void fusion(int arr1[],int arr2[],int result[],int len1,int len2){
  for(int i = 0 ;i < len1+len2;i++){
    if(i < len1){
    result[i] = arr1[i];
    }
    if(i >= len1){
    result[i] = arr2[i - len1];
    }
  }
}

int main(){
  int len1,len2;
  printf("lenght of the fist array is: ");
  scanf("%d",&len1);
  printf("lenght of the second array is: ");
  scanf("%d",&len2);
  int arr1[len1],arr2[len2];
  for(int i = 0;i < len1;i++){
    printf("arr1[%d] = ",i+1);
    scanf("%d",&arr1[i]);
  }
  for(int i = 0;i < len2;i++){
    printf("arr2[%d] = ",i+1);
    scanf("%d",&arr2[i]);
  }
  int fus[len1+len2];
  fusion(arr1,arr2,fus,len1,len2);
  printf("[");
  for(int i = 0; i < len1+len2;i++){
    printf("%d",fus[i]);
    if(i < len1+len2 -1){
      printf(",");
    }
  }
  printf("]");
}
