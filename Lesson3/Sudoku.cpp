#include<bits/stdc++.h>

using namespace std;

/*
    keep placing numbers and then call recursion to check if that is a part of the correct solution.

    checking
        row and column is easy to check
        for checking the block
            i divided by n**(-1/2) multiplied by n**(-1/2) as integer operations gives starting position for i,j
*/

bool KyaNumberRakhSakteHai(int mat[][9], int i, int j, int n, int number){
    //row and column
    for(int k=0;k<n;k++){
        if(mat[i][k]==number||mat[k][j]==number){
            return false;
        }
    }

    //block checking
    n=sqrt(n); //n=3 now. previos n was 9.
    int starti=(i/n)*n;
    int startj=(j/n)*n;

    for(int k=starti;k<starti+n;k++){
        for(int l=startj;l<startj+n;l++){
            if(mat[k][l]==number){
                return false;
            }
        }
    }

    return true;
}

bool Sudoku(int mat[][9], int i, int j, int n){
    //base case - when every row is filled.
    if(i==n){
        //print Sudoku
        for(int k=0;k<n;k++){
            for(int l=0;l<n;l++){
                cout<<mat[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    //after the row is complete
    if(j>=n){
        return Sudoku(mat,i+1,0,n);
    }

    //if already filed then continue to next column, same row though.
    if(mat[i][j]!=0){
        return Sudoku(mat,i,j+1,n);
    }

    //recursive case
    for(int number=1;number<=n;number++){
        if(KyaNumberRakhSakteHai(mat,i,j,n,number)){
            mat[i][j]=number;
            bool KyaBaakiBaatBani = Sudoku(mat,i,j+1,n); //check for the next column, same row.
            if(KyaBaakiBaatBani){
                return true;
            }
            mat[i][j]=0;
        }
    }
    return false;
}

int main(){

    int mat[9][9] = {
        {5,3,0,0,7,0,0,0,0},
    	{6,0,0,1,9,5,0,0,0},
    	{0,9,8,0,0,0,0,6,0},
    	{8,0,0,0,6,0,0,0,3},
    	{4,0,0,8,0,3,0,0,1},
    	{7,0,0,0,2,0,0,0,6},
    	{0,6,0,0,0,0,2,8,0},
    	{0,0,0,4,1,9,0,0,5},
    	{0,0,0,0,8,0,0,7,9}
    };
    Sudoku(mat,0,0,9);

    return 0;
}
