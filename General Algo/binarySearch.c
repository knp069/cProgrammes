//
// Created by nishant on 11/9/17.
//

#include <stdio.h>

int binarySearch(int arr[], int size , int find){
    int left = 0;
    int right = size-1;

    while(left<=right){
        int mid = (right+left)/2;
        if (arr[mid] == find){
            return mid;
        }
        else if ( arr[mid]< find){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}

int main(){


    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int size = 12;

    int find_1 = 2;
    int find_2 = 6;
    int result;
    result = binarySearch(arr,size,find_1);
    if (result  == -1){
        printf("%d Not found\n ",find_1);
    }
    else{
        printf("%d found at %d index\n",find_1,result);
    }


    result = binarySearch(arr,size,find_2);
    if (result  == -1){
        printf("%d Not found\n ",find_2);
    }
    else{
        printf("%d found at %d index\n",find_2,result);
    }
    return 0;
}
