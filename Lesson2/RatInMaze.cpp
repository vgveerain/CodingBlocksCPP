#include<iostream>

using namespace std;

//send your rat either way. After sending it one way, it decreases the maze size. Then we call recursion on it.
//each recursive call checks if the recursive call underneath it returned true or false for available paths.
//each block uses an || statement for available paths in right and down direction.

//base case
//  ~ i==m-1
//  ~ j==n-1
//  ~ or source == destination

bool RatInMaze(char maze[][5], int sol[10][10], int i, int j, int m, int n){
    //base case
    if(i==n-1 && j==m-1){
        sol[i][j]=1;
        for(int k=0;k<n;k++){
            for(int l=0;l<m;l++){
                cout<<sol[k][l]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    //recursive case
    sol[i][j]=1;
    if(j+1<m && maze[i][j+1]!='X'){
		bool KyaRightSeRaastaMilla=RatInMaze(maze,sol,i,j+1,n,m);
		if(KyaRightSeRaastaMilla){
			return true;
		}
	}

	if(i+1<n && maze[i+1][j]!='X'){
		bool KyaNeecheSeRaastaMilla=RatInMaze(maze,sol,i+1,j,n,m);
		if(KyaNeecheSeRaastaMilla){
			return true;
		}
	}
	sol[i][j]=0;
	return false;
}

int main(){

    char maze[][5]={
        "0000",
        "00XX",
        "0000",
        "XX00"
    };
    int sol[10][10]={0};

    RatInMaze(maze, sol, 0,0,4,4);

    return 0;
}
