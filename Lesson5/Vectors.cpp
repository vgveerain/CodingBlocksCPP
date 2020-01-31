#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main(){

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    cout<<v.size()<<endl;
    cout<<v[3]<<endl;

    v.pop_back();
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    v.push_back(60);
    v.push_back(70);
    cout<<v.capacity()<<endl;
    v.push_back(90);
    v.push_back(100);
    cout<<v.capacity()<<endl;
    v.push_back(110);
    cout<<v.capacity()<<endl;
    //the vectors follow a hash table pattern for capacity, i.e. they double the size when they're full.

    return 0;
}
