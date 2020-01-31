#include<bits/stdc++.h>

using namespace std;

void inParanthesis(char *s, int i, char *out, int j, int f){
    if(s[i] == ')'){
        // cout<<1111;
        // cout<<out[0];
        out[j]='\0';
        // cout<<j;
        // for(int x=0;x<strlen(out); x++){
        //     cout<<out[x];
        // }
        cout<<out;
        return;
    }

    if(f){
        // cout<<2221;
        // cout<<s[i];
        out[j] = s[i];
        j++;
        // cout<<out[j];
    }

    if(s[i]=='('){
        // cout<<3333;
        f=1;
    }

    inParanthesis(s, i+1, out, j, f);
}

int main(){

    char a[100];
    cin>>a;
    char out[100];

    inParanthesis(a, 0, out, 0, 0);

    return 0;
}
