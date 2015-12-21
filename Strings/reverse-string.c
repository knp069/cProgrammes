#include <stdio.h>

int strlen(char* str ){
	int i=0;
	while( str[i] !=0 ){
		i++;
	}
	return i;
}

void strrev(char* str){
	int len  = strlen(str);
	int i=0;
	while( i <len/2){
		char temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;
		i++;
	}
	return ;
}

int main(){

	char a[] = "apple";

	printf("the reverse of %s ", a);
	strrev(a);
	printf("%s \n",a);
	return 0;
}