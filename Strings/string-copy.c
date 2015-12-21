#include <stdio.h>
#include <stdlib.h>

int strlen(char* str ){
	int i=0;
	while( str[i] !=0 ){
		i++;
	}
	return i;
}

void strcpy(char* str1 , char* str2){

	int i=0;
	while(str2[i] !=0){
		str1[i]=str2[i];
		i++;
	}
	str1[i]='\0';
}

int main(){
	char a[10];
	char b[]= "apple";

	strcpy(a,b);
	printf("a := %s is a copy of b:= %s \n",a,b);
	return 0;
}