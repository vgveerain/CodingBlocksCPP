#include<bits/stdc++.h>

using namespace std;

void Permutations(char *a, int i){
    //base case
    if(a[i]=='\0'){
        cout<<a<<endl;
        return;
    }

    //recursive case
    for(int j=i;a[j]!='\0';j++){
        swap(a[i],a[j]);
        Permutations(a,i+1);//the Permutations required after swap would've been printed by now, thus we swap back to continue this recursive call.
        swap(a[i],a[j]); //Backtracking...read further on it
    }
}

int main(){
    char a[100];
    cin>>a;

    Permutations(a,0);

    return 0;
}
