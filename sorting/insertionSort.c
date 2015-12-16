#include <stdio.h>


void insertionSort(int array[] , int size){
    int i,j;
    for( i=1;i<size;i++){
        int key = array[i];
        for(j=0;j<i && key >;){

        }
    }
    return;
}


int main(){
    int array[9] = {1,4,2,7,3,9,8,5,6};
    int i;
    for(int i=0;i<9;i++){
        printf("%d\t",array[i]);
    }
    printf("\n");

    insertionSort(array,9);

    for(int i=0;i<9;i++){
        printf("%d\t",array[i]);
    }
    printf("\n");

    return 0;

}
