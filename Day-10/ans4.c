//Write a program to Print character pyramid.
#include<stdio.h>
int main(){
    int i,j,n;
    char ch='A';
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=i;j<n;j++){
            printf(" ");
        }
        for(j=1;j<=(2*i-1);j++){
            printf("%c",ch);
        }
        ch++;
        printf("\n");
    }
    return 0;
}