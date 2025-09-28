#include <stdio.h>

void tree(int numbers[],int lenght)
{
  int num_buffer;
  for(int i = 0;i < lenght-1;i++){
    if(numbers[i]>numbers[i+1]){
      num_buffer = numbers[i];
      numbers[i] = numbers[i+1];
      numbers[i + 1] = num_buffer;
    }
}
}
 


int main(){

  int n; 
  printf("n=");
  scanf("%d",&n);
  int numbers[n];
  for(int i = 0;i < n;i++){
    printf("numbers[%d] = ",i + 1);
    scanf("%d",&numbers[i]);

  }
    tree(numbers,n);
  printf("[");
    for(int i =0;i<n;i++){
      printf("%d",numbers[i]);
    if(i < n - 1){
      printf(", ");
    }
    }
  printf("]");
  return 0;
  }



