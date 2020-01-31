#include<bits/stdc++.h>
#include<queue>
#include<functional> //probably for the greater<int>

using namespace std;

//a priority queue by default acts like a MaxHeap

class comparator{
public:
    bool operator()(int a, int b){
        return a>b;
    }
};

int main(){

    // priority_queue<int> h;
    // to convert it to a Minheap
    // priority_queue<int, vector<int>, comparator> h;  //find more about this.
    priority_queue<int, vector<int>, greater<int>> h; //  < <type of data>, <how to store the priority queue>, <comaprator> >
    // the greater works as comparator class and returns true or false based on the objects.
    int a[] = {5,7,34,12,89,43,0,9,6};
    int n=sizeof(a)/sizeof(int);

    for(int i=0;i<n;i++){
        h.push(a[i]);
    }

    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }

    return 0;
}
