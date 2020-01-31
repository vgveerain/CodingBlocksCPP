//re-install the gcc compiler.
#include<bits/stdc++.h>

using namespace std;

int main(){
    // string s("Hello World;");
    //
    // char a[] = "Whatever;";
    // string s1(a);
    //
    // string s3;
    // getline(cin, s3);
    //
    // cout<<endl;

    string s[10];
    cin>>s[0];
    cin>>s[1];

    for(int i=0;i<2;i++){
        for(int j=0;s[i][j]!='\0';j++){
            cout<<s[i][j]<<" ";
        }
    }
    cout<<endl;
}
