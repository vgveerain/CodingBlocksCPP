#include<bits/stdc++.h>

using namespace std;

// void stringToInt(char *s, int i){
//     if(s[i] == '\0'){
//         return;
//     }else{
//         cout<<(s[i]-'0');
//         stringToInt(s,i++);
//     }
// }

int stringToInt(char *s, int n){
    if(n==0){
        return 0;
    }

    int last_digit = s[n-1]-'0';
    int ans = stringToInt(s, n-1);
    return (ans*10)+last_digit;
}

int main(){
    char s[100];
    cin>>s;
    // for(int i=0;i<strlen(s);i++){
    //     cout<<s[i];
    // }
    cout<<stringToInt(s,strlen(s));
    // stringToInt(s,0);
}
