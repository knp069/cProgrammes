#include <stdio.h>

int fibbonaci(int n , int a , int b){

    if (n==1)
        return a;

    if (n==2)
        return b;

    return fibbonaci(n-1 , b , a+b);
}

int main(){

    printf("printing first 10 fibbonaci number \n");

    int i=1;
    for(i=1;i<=10;i++){
        printf("%d ,",fibbonaci(i,0,1));
    }
    printf("\n");
    return 0;
}
