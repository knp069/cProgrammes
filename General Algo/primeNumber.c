#include <stdio.h>

int prime(int n){

    if ( n == 2 || n==3 )
        return 1;

    if (n%2==0)
        return 0;

    int i=3;

    for(i=3;i*i<=n;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main(){

    printf("printitng prime numbers upto 50\n");
    int i=2;
    for(i=2;i<=50;i++){
        (prime(i))?printf("%d\n",i):printf("");;
    }
    printf("\n");
    return 0;
}
