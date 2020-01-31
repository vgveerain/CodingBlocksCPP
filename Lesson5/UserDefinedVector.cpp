#include<bits/stdc++.h>
#include<vector>

using namespace std;

class VectorMe{
public:
    int *a;
    int currentSize;
    int maxSize;

    VectorMe(int size=4){
        a = new int[size];
        currentSize = 0;
        maxSize = size;
    }

    void push_back(int x){
        if(currentSize == maxSize){
            int *oldLocation = a;
            int oldMaxSize = maxSize;
            a = new int[maxSize*2];
            maxSize *= 2;
            for(int i=0;i<oldMaxSize;i++){
                a[i] = oldLocation[i];
            }
            delete []oldLocation;
        }
        a[currentSize] = x;
        currentSize++;
    }

    void pop_back(){
        if(!currentSize>0){
            cout<<"Vector empty!"<<endl;
            return;
        }
        if(currentSize < maxSize/2){
            int *oldLocation = a;
            int oldCurrentSize = currentSize;

            maxSize /= 2;
            a = new int[maxSize];

            for(int i=0;i<currentSize-1;i++){
                a[i] = oldLocation[i];
            }
            currentSize--;
            delete []oldLocation;
        }
    }

    int size(){
        return currentSize;
    }

    int capacity(){
        return maxSize;
    }

    int operator [](int i){
        if(i<currentSize-1){
            return a[i];
        }else{
            return -999;
        }
    }
};

int main(){
    VectorMe v(10);
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

    return 0;
}
