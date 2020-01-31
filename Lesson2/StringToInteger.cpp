#include<bits/stdc++.h>

using namespace std;

// int StringToInteger(char *a, int n, int i){
//     static int s=0;
//     if(i==n-1){
//         return s;
//     }else{
//         s*=10;
//         s+=(a[i]-(int)('0'));
//         s*=10;
//         s+=StringToInteger(a,n,i++);
//     }
// }

int StringToInteger(char *a, int n){
    if(n==0){
        return 0;
    }

    int last_digit=a[n-1]-'0';
    int ans=StringToInteger(a, n-1);

    return (ans*10)+last_digit;
}

int main(){
    char a[]={'2','4','0','8'};
    // int n = sizeof(a)/sizeof(char);
    int n = strlen(a);

    cout<<StringToInteger(a,n)*100<<endl;

    return 0;
}
