#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;

class Graph{

    int v;
    list<pii>*adj;

    public:
    Graph(int s){
        this->v = s;
        adj = new list<pii>[s];
    }


    void addEdge(int u ,int v, int w){
        adj[u].push_back(make_pair(w,v));
        adj[v].push_back(make_pair(w,u));
    }

    void shortestPath(int src){
        priority_queue<pii,vector<pii>,greater<pii>>pq;
       

       vector<int>dis(v,INT_MAX);

       pq.push(make_pair(0,src));
       dis[src]=0;

       while(!pq.empty()){
         int u=pq.top().second;
         pq.pop();

         for(auto &neighbor:adj[u]){
            int v=neighbor.second;
            int w=neighbor.first;

            if(dis[v]>dis[u]+w){
                dis[v] = dis[u] + w;
                pq.push(make_pair(dis[v],v));
            }
         }
       }

       for(int i=0 ; i<v;++i){
        cout<<i<<"   "<<dis[i]<<endl;

       }


    }

};


int main(){
 
    Graph g(9);

    g.addEdge(0,1,4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

     g.shortestPath(0);

    return 0;

    return 0;
}