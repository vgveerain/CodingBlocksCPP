#include<bits/stdc++.h>

using namespace std;

/*
    print the possible sets of strings formed by typing numbers on the numberpad.
*/

void NumberPad(char *in, char *out, int i, int j, char **key){
    //base case
    if(in[i]=='\0'){
        // for(int k=0;k<strlen(out);k++){
        //     cout<<out[i];
        // }
        // cout<<endl;

        out[j]=='\0';
        cout<<out<<endl;
        return;
    }

    //recursive case
    // for(int k=0;k<strlen(out);k++){
    //
    // }
    int digit = in[i]-'0';
    for(int k=0;key[digit][k]!='\0';k++){
        out[j]=key[digit][k];
        NumberPad(in,out,i+1,j+1,key);
    }
}

// void NumberPad2(char *in, char **out, int i, int j, char **key){
//     //////***********you should shut your stupid ass up**************//////
//
//     //base case
//     if(in[i]=='\0'){
//         for(int k=0;k<sizeof(out)/3;k++){
//             for(int l=0;l<strlen(out[k]);l++){
//                 cout<<out[k][l];
//             }
//             cout<<endl;
//         }
//         cout<<endl;
//         return;
//     }
//
//     //recursive case
//     int digit = in[i]-'0';
//     char mapDigit = key[i][digit];
//     for(int k=0;k<sizeof(out)/3;k++){
//         out[j][k]='A'
//     }
// }

int main(){

    string num;
    cin>>num;

    string arr[10]={
        "",
        "",
        "ABC",
        "DEF",
        "GHI",
        "JKL",
        "MNO",
        "PQRS",
        "TUV",
        "WXYZ"
    };

    char x[100];

    NumberPad(num,x,0,0,arr);

    return 0;
}
