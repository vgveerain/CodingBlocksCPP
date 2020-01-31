#include<bits/stdc++.h>

using namespace std;

/*
    every row must have a queen.
        ~ the solution

    go ahead and place a queen at the available place and check further.
    if successful then done, if not then the previous position is wrong.
    the problem gets broken to a smaller problem from nxn after placing every queen.
    if you can't place a queen in the row, below the last placed queen, then the solution is wrong and thus backtrack the solution and fix it.

    Base case
        the no. of rows left is 0.
*/

bool CanPlaceQueenHere(int board[][10], int i, int j, int n){
    //as we are placing queens row wise thus we need to check for queens above the current cell only.

    //column above and current row is needed, but here we are checking all of both row and column.
    for(int k=0;k<n;k++){
        if(board[i][k]||board[k][j]){
            return false;
        }
    }

    //left upper diagonal
    int k=i;
    int l=j;
    while(k>=0 && l>=0){
        if(board[k][l]){
            return false;
        }
        k--;
        l--;
    }

    //right upper diagonal
    k=i;
    l=j;
    while(k>=0 && l<n){
        if(board[k][l]){
            return false;
        }
        k--;
        l++;
    }

    return true;
}

bool NQueen(int board[][10], int n, int i){
    //base case
    if(i==n){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cout<<board[j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        //return true;
        return false;
        //we are returning false because we want to print every possible case.
    }

    //recursive case
    for(int j=0;j<n;j++){
        if(CanPlaceQueenHere(board,i,j,n)){
            board[i][j]=1;
            bool KyaBaakiBaatBani=NQueen(board,n,i+1);
            if(KyaBaakiBaatBani){
                return true;
            }
            board[i][j]=0;
        }
    }
    return false;
}

int main(){

    int board[10][10]={0};
    int n;
    cin>>n;

    NQueen(board,n,0);

    return 0;
}
