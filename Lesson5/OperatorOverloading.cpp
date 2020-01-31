#include<bits/stdc++.h>

using namespace std;

class Pair{
public:
    int x;
    int y;

    bool operator > (Pair b){
        if(x>b.x && y>b.y){
            return true;
        }else{
            return false;
        }
    }

    bool operator < (Pair b){
        if(x<b.x && y<b.y){
            return true;
        }else{
            return false;
        }
    }

    bool operator = (Pair b){
        if(x==b.x && y==b.y){
            return true;
        }else{
            return false;
        }
    }

    Pair(int q, int v){
        x=q;
        y=v;
    }
};

int main(){
    Pair a(1,2);
    Pair b(3,4);

    if(b<a){
        cout<<"AWESOME, IT WORKS!"<<endl;
    }else{
        cout<<"IT STILL WORKS, BUT DIFFERENTLY"<<endl;
    }
}
