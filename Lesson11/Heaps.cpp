#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *left, *right;

    Node(int d):data(d), left(NULL), right(NULL){}
};

// Heaps
/*  every level is filled fully before inserting the next node in the next level.
    the min or max element is supposed to be.

    * To search the position for insertion the time taken is O(N) and to heapify the min element if the heap is distorted, the time taken is O(Lg N).
    * To remove a node, the element is swapped by the max in the left subtree, which mantains the heap property
        and thus the node which gets swapped is then deleted.

*/

class Minheap{
    vector<int> v;
    void heapify(int index){
        int min_index = index;
        int left = 2*index;
        int right = left+1;

        if(left<v.size() && v[min_index]>v[left]){
            min_index = left;
        }
        if(right<v.size() && v[min_index]>v[right]){
            min_index = right;
        }

        if(index!=min_index){
            swap(v[index], v[min_index]);
            heapify(min_index);
        }
    }
public:
    Minheap(){
        v.push_back(-1);
    }

    void push(int data){
        v.push_back(data);
        int index = v.size()-1;
        int parent = index/2;

        while(v[parent]>v[index]){
            swap(v[parent], v[index]);
            index = parent;
            parent = parent/2;
        }
    }

    int search(){
        return v[1];
    }

    void pop(){
        int index = v.size()-1;
        swap(v[index], v[1]);
        v.pop_back();

        heapify(1);
    }

    bool empty(){
        return v.size()==1;
    }
};


int main(){
    Minheap h;
    int a[] = {5,7,34,12,89,43,0,9,6};
    int n=sizeof(a)/sizeof(int);

    for(int i=0;i<n;i++){
        h.push(a[i]);
    }

    while(!h.empty()){
        cout<<h.search()<<" ";
        h.pop();
    }

    return 0;
}
