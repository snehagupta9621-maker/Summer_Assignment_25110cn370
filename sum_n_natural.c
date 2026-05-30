#include<stdio.h>
int main()
{ int n ,i, sum=0;
  printf("enter no. ");
  scanf("%d",&n);
  i=1;
  while(i<=n){
   
    sum+=i;
    i++;
  }
    printf("sum of first %d n natural no. is %d",n,sum);
    return 0;
}
