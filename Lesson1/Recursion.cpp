//re-install the gcc compiler.
#include<bits/stdc++.h>

using namespace std;

int factorial(int n){
    if(n==1){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

bool checkSorted(int a[], int n){
    //base case
    //size(a)
    if(n==0 || n==1){
        return true;
    }

    //recursive case
    bool KyaChotaSortedHai = checkSorted(a+1,n-1);
    if(a[0]<=a[1] && KyaChotaSortedHai){
        return true;
    }else{
        return false;
    }
}

int sum(int a[], int n){
    if(n==0){
        return 0;
    }
    int chotaAns = sum(a+1, n-1);
    return a[0]+chotaAns;
}

void Print(int a[], int n){
    if(n==0){
        return;
    }
    else{
        cout<<a[0]<<" ";
        Print(a+1, n-1);
    }
}

int power(int a, int x){
    if(x==1){
        return a;
    }else{
        return a*power(a,x-1);
    }
}

// void noToWords(int n){
//     string a[10] = {
//         "zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
//     };
//     if(n/10 != 0){
//         cout<<a[n%10];
//         noToWords(n/10);
//     }else{
//         cout<<" "<<a[n];
//         return;
//     }
// }

int firstIndex(int a[], int n, int x){
    if(n<0){
        return -999;
    }
    if(a[0]==x){
        return n-1;
    }else{
        return firstIndex(a+1,n-1,x);
    }
}

// int lastIndex(int a[], int n, int i, int x){
//     static int val=-999;
//     //base case
//     if(i==n){
//         return val;
//     }
//     //recursive case
//     if(a[i]==x){
//         val = i;
//     }else{
//         val = lastIndex(a,n,i+1,x);
//     }
// }

/*  *check last indices function from github*  */

void bubbleSort(int a[], int n){
    if(n==0){
        return;
    }
    //recursive case
    int min = 0;
    for(int j=0;j<n;j++){
        if(a[j]<=a[min]){
            min = j;

        }
    }
}

int main(){

    // int n;
    // cin>>n;
    // cout<<fibonacci(n)<<endl;

    int a[] = {1,3,5,16,8,9};
    int n = sizeof(a)/sizeof(int);

    // if(checkSorted(a,n)){
    //     cout<<"Sorted";
    // }else{
    //     cout<<"Not Sorted";
    // }
    // return 0;

    // Print(a,n);

    // int a,x;
    // cin>>a>>x;
    // cout<<power(a,x)<<endl;

    // int x;
    // cin>>x;
    // noToWords(x);

    int ans = n - firstIndex(a,n,5);
    // int ans = lastIndex(a,n,0,5);
    cout<<ans<<endl;
}
