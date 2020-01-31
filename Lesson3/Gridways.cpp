#include<bits/stdc++.h>

using namespace std;

/*
    can only move right and down.
    thus the no. of ways to reach a[i][j] = f(i,j-1)+f(i-1,j);

    base case
        a[0][0] = 1;
*/

int Gridways(int i,int j){
    //base case
    if(i<0||j<0){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    //recursive case
    return Gridways(i-1,j)+Gridways(i,j-1);
}

int ElephantChessWays(int i,int j){
    //base case
    if(i<0||j<0){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }

    //recursive case
    //  the elephant can reach each cell by the (sum of all colums before it + sum of all rows before it) ways.
    int rows=0,cols=0;
    for(int k=0;k<i;k++){
        rows+=ElephantChessWays(k,j);
    }
    for(int k=0;k<j;k++){
        cols+=ElephantChessWays(i,k);
    }
    return rows+cols;
}

int main(){

    cout<<"Gridways"<<endl;

    // int i,j;
    // cin>>i>>j;
    // cout<<Gridways(i,j)<<endl;
    for(int x=0;x<4;x++){
        for(int z=0;z<4;z++){
            cout<<ElephantChessWays(x,z)<<" ";
        }
        cout<<endl;
    }

    return 0;
}
