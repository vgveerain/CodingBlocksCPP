#include<bits/stdc++.h>
#include<map>
#include<list>
#include<climits>
#include<set>

using namespace std;

template<typename T>
class Graph{
    map<T, list<pair<T, int>>> adjlist;
public:
    void addEdge(T u, T v, int d, bool bidir=true){
        adjlist[u].push_back(make_pair(v,d));
        if(bidir){
            adjlist[v].push_back(make_pair(u,d));
        }
    }

    void print(){
        for(auto obj:adjlist){
            cout<<obj.first<<"-->";
            for(auto childrenOfObj:obj.second){
                cout<<"("<<childrenOfObj.first<<"-"<<childrenOfObj.second<<"),";
            }
            cout<<endl;
        }
    }

    void SSSP(T src, T dst){
        //this doesn't work!!!!!!!!
        set<pair<int, T>> s;
        map<T, int> d;

        for(auto node:adjlist){
            d[node.first] = INT_MAX;
        }

        d[src] = 0;
        s.insert(make_pair(0, src));

        while(!s.empty()){
            auto f = *(s.begin());
            s.erase(s.begin());

            int parentDist = f.first;
            T parentNode = f.second;

            for(auto children:adjlist[parentNode]){
                if(d[children.first] > parentDist+children.second){
                    auto p = s.find(make_pair(d[children.first], children.first));
                    if(p!=s.end()){
                        //found, as iterator not at end
                        s.erase(p);
                        s.insert(make_pair(parentDist+children.second, children.first));
                        d[children.first] = parentDist+children.second;
                    }
                }
            }
        }
        for(auto node:adjlist){
            cout<<"distance of "<<node.first<<" from "<<src<<" : "<<d[node.first]<<endl;
        }
    }
};

int main(){
    Graph<string> g;
    g.addEdge("Agra", "Bhopal", 2, true);
    g.addEdge("Agra", "Amritsar", 1, true);
    g.addEdge("Agra", "Delhi", 1, true);
    g.addEdge("Amritsar", "jaipur", 4, true);
    g.addEdge("Delhi", "Agra" , 1, true);
    g.addEdge("Bhopal", "Agra", 2, true);
    g.print();

    g.SSSP("Agra", "Bhopal");
    return 0;
}
