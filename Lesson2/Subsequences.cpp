#include<bits/stdc++.h>

using namespace std;

void Subsequences(char *in, int i, char *out, int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    //output main aek baar i'th element lelo
    out[j]=in[i];
    Subsequences(in,i+1,out,j+1);

    //output main aek baar i'th element mat lo
    Subsequences(in,i+1,out,j);
}

int main(){
    char in[100];
    cin>>in;
    char out[100];

    Subsequences(in,0,out,0);

    return 0;
}
