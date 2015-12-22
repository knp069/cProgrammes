#include <stdio.h>

int strlen(char* str ){
	int i=0;
	while( str[i] !=0 ){
		i++;
	}
	return i;
}

int isPalindrome(char* str){

    int length = strlen(str);
    int i=0;
    while(i<length/2){
        if(str[i] != str[length-i-1])
            return 0;
        i++;
    }
    return 1;
}

int main(){
	char a[] = "elple";
	printf("the string is %d \n" , isPalindrome(a));
	return 0;
}
