#include <stdio.h>

int factorial(int n , int a){

    if (n==0)
        return 1;

    if (n<0)
        return -1;

    if (n==1)
        return a;

    return factorial(n-1 , a*(n-1));
}

int main(){

    printf("printing first 10 factorial number \n");

    int i=1;
    for(i=1;i<=10;i++){
        printf("%d ,",factorial(i,i));
    }
    printf("\n");
    return 0;
}
