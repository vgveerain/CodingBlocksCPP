#include<bits/stdc++.h>
#include "HashTable.h"
#include<unordered_map>

using namespace std;

int main(){
    HashTable<int> h;
    h.insert("mango", 100);
    h.insert("tango", 200);
    h.insert("django", 300);
    h.insert("dead", 400);
    h.insert(":o", 600);

    h.print();

    int *k = h.search("mango");
    if(k){
        cout<<*k;
    }


    //--------STL--------//
    unordered_map<string,int> myMap;
    //                                         Insert in 3 ways
    myMap["Mango"] = 100;                                   //1
    
    myMap.insert(make_pair("Apple", 120));                  //2

    pair<string, int> p("Guava", 130);                      //3
    myMap.insert(p);

    //Print
    for(auto node:myMap){
        cout<<node.first<<", "<<node.second<<endl;
    }

    for(int i=0;i<myMap.bucket_count();i++){
        cout<<"bucket "<<i<<endl;
        for(auto it = myMap.begin(i);it!=myMap.end(i);it++){
            cout<<it->first<<", "<<it->second<<endl;
        }
        cout<<endl;
    }

    cout<<myMap.count("Apple");
    myMap.erase("Apple");

    return 0;
}
