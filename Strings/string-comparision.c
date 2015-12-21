#include <stdio.h>

int strcmp(char* str1 , char* str2){

	int i=0;

	while(str1[i]!=0 && str2[i]!=0 && str1[i] == str2[i]){
		i++;
	}

	if( str1[i] == 0 && str2[i] == 0){
		return 0;
	}

	if (str1[i] == 0 || str1[i]<str2[i]){
		return -1;
	}

	if (str2[i] == 0 || str1[i]>str2[i]){
		return 1;
	}
}

int main(){

	char a[] = "apple";
	char b[] = "boy";
	char c[] = "apple";

	printf("the result of comparision is %d and %d\n",strcmp(b,a),strcmp(a,c));
	return 0;
}