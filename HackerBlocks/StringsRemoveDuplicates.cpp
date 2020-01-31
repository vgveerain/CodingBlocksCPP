#include<bits/stdc++.h>

using namespace std;

int main(){

    char a[100];
    cin>>a;

    char out[100];
    int j=1;
    out[0]=a[0];

    char x=a[0];

    for(int i=0;i<strlen(a);i++){
        if(x != a[i]){
            x=a[i];
            out[j]=x;
            j++;
        }
    }
    out[j]='\0';

    cout<<out<<endl;

    return 0;
}
