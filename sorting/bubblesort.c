#include <stdio.h>


void bubbleSort(int array[] , int size){
    int i,j;
    for( i=0;i<size-1;i++){
        for( j=i+1;j<size;j++){
            if(array[i]>array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
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

    bubbleSort(array,9);

    for(int i=0;i<9;i++){
        printf("%d\t",array[i]);
    }
    printf("\n");

    return 0;

}
