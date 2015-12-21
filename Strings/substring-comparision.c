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

	int i=0
	while(i<=searchSpan)
}