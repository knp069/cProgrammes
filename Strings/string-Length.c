#include <stdio.h>

int strlen(char* str ){
	int i=0;
	while( str[i] !=0 ){
		i++;
	}
	return i;
}

int main(){
	char a[] = "apple";
	printf("The length of the string %s is %d \n" , a,strlen(a));
	return 0;
}