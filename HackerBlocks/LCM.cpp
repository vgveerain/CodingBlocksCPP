#include<bits/stdc++.h>

using namespace std;

int main(){

    int x,y;
    cin>>x>>y;
    int z=min(x,y);

    while(!(z%x == 0 && z%y == 0)){
        z++;
    }

    cout<<z;

    return 0;
}
