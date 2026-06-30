#include<stdio.h>
    int main()
    {int i=1,n,c=0;
        printf("enter no.");
        scanf("%d",&n);
        while (n!=0){
           n=n/10;
           c++; 
        }
printf("no. of digit in %d is %d",n,c);

return 0;








    }
