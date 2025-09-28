#include<stdio.h>

void copy(int orig[],int cop_arry[],int len){
  for(int i =0; i< len;i++){
    cop_arry[i] = orig[i];
  }
}
int main(){
  int index;
  printf("max index: ");
  scanf("%d",&index);
  int orig[index],cop_arry[index];
  for(int i =0;i<index;i++){
    printf("orig[%d]=",i+1);
      scanf("%d",&orig[i]);
    }
  
  copy(orig,cop_arry,index);
  for(int i  = 0;i < index; i++){
    printf("orig=%d:copy=%d\n",orig[i],cop_arry[i]);
  }
}
