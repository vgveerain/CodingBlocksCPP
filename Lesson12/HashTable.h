#include<iostream>
#include<string>

using namespace std;

template<typename T>
class Node{
public:
    string key;
    T value;
    Node<T> *next;

    Node(string key, T value):value(value), key(key), next(NULL){}

    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

template<typename T>
class HashTable{
    int currentSize;
    int tableSize;
    Node<T> **buckets;

    int hashFn(string key){
        int L = key.length();
        int ans = 0;
        int p=1;

        for(int i=0;i<L;i++){
            ans += key[L-i-1]*p;
            p=p*37;
            p%=tableSize;
            ans%=tableSize;
        }
        return ans;
    }

    void rehash(){
        Node<T> **oldBuckets = buckets;
        int oldTableSize = tableSize;
        tableSize = tableSize*2;
        currentSize = 0;
        buckets = new Node<T>*[tableSize];
        for(int i=0;i<tableSize;i++){
            buckets[i] = NULL;
        }

        for(int i=0;i<oldTableSize;i++){
            Node<T>*temp = oldBuckets[i];
            if(temp!=NULL){
                while(temp!=NULL){
                    insert(temp->key, temp->value);
                    temp = temp->next;
                }
                delete oldBuckets[i];
            }
        }

        delete []oldBuckets;
    }

public:
    HashTable(int ds=7){
        currentSize = 0;
        tableSize = ds;
        buckets = new Node<T>*[tableSize];
        ///make all addresses zero
        for(int i=0;i<ds;i++){
            buckets[i] = NULL;
        }
    }

    void insert(string key, T value){
        int i = hashFn(key);
        Node<T>*n = new Node<T>(key, value);
        n->next = buckets[i];
        buckets[i] = n;
        currentSize++;
        float loadFactor = (float) currentSize/tableSize;
        if(loadFactor > 0.7){
            cout<<"LoadFactor exceeded 0.7, Rehashing ...."<<endl;
            rehash();
        }
    }

    void print(){
        for(int i=0;i<tableSize;i++){
            Node<T> *temp = buckets[i];
            cout<<"Bucket "<<i<<" -> ";
            while (temp!=NULL) {
                cout<<temp->key<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    T* search(string key){
        int ans = hashFn(key);
        Node<T>*n = buckets[ans];
        while(n!=NULL){
            if(n->key == key){
                return &(n->value);
            }
            // cout<<n->key<<" ";
            n = n->next;
        }
        return NULL;
        // cout<<endl;
        // return *n;
    }

    T& operator [] (string key){
        T* temp = search(key);
        if(temp == NULL){
            T garbage;
            insert(key, garbage);

            T* value = search(key);
            return *value;
        }else{
            return temp;
        }
    }

    // void delete(string key){
    //     int ans = hashFn(key);
    //     Node<T>*n = buckets[ans];
    //     while(n->next!=NULL){
    //         if(n->next->key == key){
    //
    //         }
    //     }
    // }


};
