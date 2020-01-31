#include<bits/stdc++.h>

using namespace std;

int sumOfDigits(char *s){
    if(s[0]=='\0'){
        return 0;
    }

    int ans = s[0]-'0';
    return ans + sumOfDigits(s+1);
}

int main(){
    char a[100];
    cin>>a;

    cout<<sumOfDigits(a);

    return 0;
}
