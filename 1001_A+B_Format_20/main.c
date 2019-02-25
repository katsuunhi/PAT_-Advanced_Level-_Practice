#include<stdio.h>

int f(int x){
  if(x/1000){
    printf("%d",f(x/1000));
    if(100 <= x%1000)
      printf(",%d",x%1000);
    if(10 <= x%1000 && x%1000 < 100)
      printf(",0%d",x%1000);
    if(x%1000 < 10)
      printf(",00%d",x%1000);
    printf("\n%d\n",x%1000);

  }
  else
    return x;
}


int main(){
  
  long int a;
  long int b;
  long int sum = 0;
  
  scanf("%d %d", &a, &b);
  sum = a + b;
  if(sum < 0){
    printf("-");
    sum = -sum;
  }
  f(sum);
  
  return 0;
}