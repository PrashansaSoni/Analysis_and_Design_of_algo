#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Graph {
    int V;
    vector<vector<pii>> adjList;

public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adjList[u].push_back({w, v});
        adjList[v].push_back({w, u});
    }

    void primMST() {
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        
        vector<int> key(V, INT_MAX);

    
        vector<bool> inMST(V, false);

        
        vector<int> parent(V, -1);

        
        int start = 0;
        key[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            
            if (inMST[u]) continue;

        
            inMST[u] = true;

        
            for (auto &edge : adjList[u]) {
                int v = edge.second;
                int weight = edge.first;

                
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        
        cout << "Edges in the Minimum Spanning Tree:\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " -- " << i << " == " << key[i] << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    
    g.primMST();

    return 0;
}
