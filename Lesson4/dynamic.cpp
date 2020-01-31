#include<bits/stdc++.h>

using namespace std;

// this function returns an int pointer.
// int *fun(int n){
//     int *arr = new int[n];
//     for(int i=0;i<n;i++){
//         arr[i] = i;
//     }
//
//     return arr;
// }

int main(){
    /* ----- BASICS -----*/
    // int *a = new int;
    // *a = 10;
    // cout<<*a<<endl;
    // delete a;
    //
    // int n;
    // cin>>n;
    // int *arr = new int[n];
    //
    // for(int i=0;i<n;i++){
    //     arr[i] = i;
    // }
    //
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // delete []arr;




    /* ------ Allocation using function ------ */
    // int n;
    // cin>>n;
    // int *arr = fun(n);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // delete []arr;





    /* ------ 2D Array Dynamically ------ */
    /*
        we need to store the 2D array as a list of arrays, 
        which is list of pointers, 
        which is essentially, pointer to pointers.
        
        no, of rows -
            int **rows = new int*[rowCount];
        no. of cols -
            rows[0] = new int[colCount];
            rows[1] = new int[colCount];
            .
            .
            .
            .
            rows[rowCount-1] = new int[colCount];
    */

    // int c,r;
    // cin>>r>>c;
    //
    // int **a = new int*[r];
    // for(int i=0;i<r;i++){
    //     a[i] = new int[c];
    // }
    // int num=1;
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         a[i][j] = num;
    //         num++;
    //     }
    // }
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //
    // //deleting a 2D array
    // for(int i=0;i<r;i++){
    //     delete[] a[i];
    // }
    // delete []a;
    // a=NULL;
    //
    // return 0;
}
