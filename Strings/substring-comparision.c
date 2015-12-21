#include <stdio.h>

int strlen(char* str ){
	int i=0;
	while( str[i] !=0 ){
		i++;
	}
	return i;
}

int isSubstring(char* field , char* key){

	if (strlen(key)>strlen(field))
		return -1;

	int searchSpan = strlen(field)-strlen(key);

	int i=0,j,flag;
	while(i<=searchSpan){
		flag = 0;
		j = 0;
		while(key[j] != 0){
			if(key[j] != field[i]){
				flag = 1;
			}
			i++;
			j++;
		}
		if (flag != 1)
			break;
	}
	if (i > searchSpan && flag == 1)
		return -1;

	return i-j;
}


int main(){

	char a[] = "pine-apple";
	char b[] = "apple";
	printf("Match found at index %d \n" , isSubstring(a,b));
	return 0;
}