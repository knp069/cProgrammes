#include <iostream>

using namespace std;

bool check(int sudoku[][9]);

bool issafe(int a[][9] , int n , int row , int col){
  for (int i = 0; i < 9; i++) {
    /* code */
    if (i!=row){
      if(a[i][col] == n){
        return false;
      }
    }
  }
  for (int i = 0; i < 9; i++) {
    /* code */
    if (i!=col){
      if(a[row][i] == n){
        return false;
      }
    }
  }
  for (int i = row/3; i < row/3+3; i++) {
      for (int j = col/3; j < col/3+3; j++) {
          if(i!=row and j!=col){
              if(a[row][col]== n){
                  return false;
              }
          }
    }
  }
}

int main(){
  return 0;
}
