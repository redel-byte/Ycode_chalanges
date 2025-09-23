#include<stdio.h>

int main(){

  int a;
  int num1;
  int num2;
  int num3;
  int num4;
  int arr[4];

  printf("Enter the number: ");
  scanf("%d",&a);
  num1 = a % 10;
  a /= 10;
  arr[0] = num1;
  num2 = a % 10;
  a /= 10;
  arr[1] = num2;
  num3 = a % 10;
  a /= 10;
  arr[2] = num3;
  num4 = a%10;
  arr[3] = num4;
  
  
  printf("%d%d%d%d\n",arr[0],arr[1],arr[2],arr[3]);
  return 0;
}
