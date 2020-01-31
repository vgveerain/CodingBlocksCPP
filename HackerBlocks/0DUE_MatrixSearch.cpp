#include<bits/stdc++.h>

using namespace std;

// int searchMatrix(int **m, int x, int y, int k){
//     if(x==0 && y==0){
//         return 0;
//     }
//
//     for(int i=0;i<x;i++){
//         for(int j=0;j<y;j++){
//             if(m[i][j] == k){
//                 return 1;
//             }
//         }
//     }
//
//     return 0;
// }

int main(){

    int x;
    cin>>x;

    int ans[x] = {0};

    int i,j;
    for(int z=0;z<x;z++){
        cin>>i>>j;
        int arr[i][j];
        for(int a=0;a<i;a++){
            for(int b=0;b<j;b++){
                cin>>arr[a][b];
            }
        }
        int k;
        cin>>k;

        for(int a=0;a<i;a++){
            for(int b=0;b<j;b++){
                if(arr[a][b] == k){
                    // return 1;
                    ans[z] = 1;
                    break;
                }
            }
        }

        // int an = searchMatrix(arr,i,j,k);
        // ans[z] = an;
    }

    for(int z=0;z<x;z++){
        cout<<ans[z]<<endl;
    }
    return 0;
}
