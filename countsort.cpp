#include <iostream>
#include <stdlib.h>
using namespace std;

void countsort(int a[] , int size);

int main(){
	int a[100],size;
	int i;
	cout<<"enter size : ";
	cin>>size;
	for ( i = 0; i < size; ++i){
		cin>>a[i];
	}
	for ( i = 0; i < size; ++i){
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	
	countsort(a,size);

	for ( i = 0; i < size; ++i){
		cout<<a[i]<<"\t";
	}
	cout<<endl;

	return 0;
}


void countsort(int a[],int size){
	int * c = (int *)malloc(sizeof(int)*100);
	int b[size];
	int i;
	for ( i = 0; i < 100; ++i){
		/* code */
		c[i]=0;
	}
	for ( i = 0; i < size; ++i){
		/* code */
		c[a[i]]=c[a[i]]+1;
	}
	for ( i = size-1 ; i >= 0; --i){
		/* code */
		b[c[a[i]]] = a[i];
		c[a[i]]=c[a[i]]-1;
	}
	for ( i = 0; i < size; ++i){
		/* code */
		a[i]=b[i];
	}
	return ;
}