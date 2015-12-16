#define N 8
#include <iostream>
#include <cmath>
#include <stdio.h>


bool isSafe (bool chess[][N] , int i , int j);
bool nQueen (bool chess[][N] , int i );

int queen=0;

void printchess(bool chess[][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if (chess[i][j])
				printf(" Q ");
			else
				printf(" - ");
		}
		printf("\n");
	}
}


bool isSafe(bool chess[][N] , int i , int j){
	int k,l;

	for( k=0;k<i;k++){
		if(chess[k][j]==true)
			return false;
	}

	for( k=i ,  l=j; k>=0 and l<N ; k-- , l++ ){
		if (chess[k][l] == true )
			return false;
	}

	for( k=i ,  l=j; k>=0 and l>=0 ; k-- , l-- ){
		if (chess[k][l] == true )
			return false;
	}
	return true;
}


bool nQueen( bool chess[][N] , int i ){

	if(i >= N){
		return true ;
	}
	for(int k=0;k<N;k++){
		if(isSafe(chess , i , k)){
			chess[i][k] = true ;

			if(nQueen(chess , i+1 ))
				return true;

			chess[i][k] = false;
		}
	}
	return false;
}



int main(){

	bool chess[N][N] = { 
		{false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false},
		{false,false,false,false,false,false,false,false}
	};
	printf("N-Queen Backtracking problem\n");
	if(nQueen(chess,0)){
		printchess(chess);
	}

}