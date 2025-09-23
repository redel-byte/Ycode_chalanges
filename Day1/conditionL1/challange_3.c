#include<stdio.h>



int main(){


int num1;
int num2;
  printf("num1 = ");
  scanf("%d",&num1);
  printf("num2 = ");
  scanf("%d",&num2);

if(num1 == num2){
  printf("%d",(num1+num2)*3);
}
else{
  printf("%d",num1+num2);
  }
}
