#include <stdio.h>


void change(int* k){
    (*k)++;
}
int main(){
    int k;
    k = 5;
    printf("%d\n",k );
    change(&k);
    printf("%d\n",k );
    return 0;
}
