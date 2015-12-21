#include <stdio.h>
#include <stdlib.h>


int strlen(char* str ){
	int i=0;
	while( str[i] !=0 ){
		i++;
	}
	return i;
}

void strcat(char* str1 , char* str2){
	

	int j = strlen(str1);
	int i=0;

	while(str2[i] !=0){
		str1[i+j]=str2[i];
		i++;
	}
	str1[i+j]='\0';
}

int main(){

	char a[15]="apple";
	char b[] = "ball";

	printf("The concatenation of %s and %s is ",a,b);
	strcat(a,b);
	printf("%s \n",a);
	return 0;
}