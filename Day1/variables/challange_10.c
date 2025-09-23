#include<stdio.h>
#include<math.h>

int main(){
  double rayon;

  printf("Enter the value of the 'rayon' : ");
  scanf("%lf",&rayon);

  printf("le volume de sphere est: %.2lf",(4/3) * M_PI * pow(rayon,3));

  return 0;
}
