#include<bits/stdc++.h>

using namespace std;

int LCS_DP(char* x, char* y){
    int a[100][100];
    int xi = strlen(x)+1;
    int yj = strlen(y)+1;

    for(int i=0;i<xi;i++){
        for(int j=0;j<yj;j++){
            if(i==0 || j==0){
                a[i][j] = 0;
            }else if(x[i-1]==y[j-1]){
                a[i][j] = 1 + a[i-1][j-1];
            }else{
                a[i][j] = max(a[i-1][j], a[i][j-1]);
            }
        }
    }

    return a[xi-1][yj-1];
}

int main(){
    char x[100], y[100];
    cin>>x;
    cin>>y;
    cout<<LCS_DP(x,y)<<endl;
    return 0;
}
