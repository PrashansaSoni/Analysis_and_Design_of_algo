#include <bits/stdc++.h>
#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Constructor to initialize the disjoint set
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find function with path compression
    int find(int u) {
        if (parent[u] == u) {
        return parent[u];
        }
           return  parent[u] = find(parent[u]); // Path compression
    }

    // Union function by rank
    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    // Function to check if two elements are in the same set
    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }
};

class Graph { 
    vector<vector<int> > edgelist; 
    int V; 
  
public: 
    Graph(int V) { this->V = V; } 
  
    // Function to add edge in a graph 
    void addEdge(int x, int y, int w) 
    { 
        edgelist.push_back({ w, x, y }); 
    } 
  
    void kruskals_mst() 
    { 
        // Sort all edges 
        sort(edgelist.begin(), edgelist.end()); 
  
        // Initialize the DSU 
        DSU s(V); 
        int ans = 0; 
        cout << "Following are the edges in the "
                "constructed MST"
             << endl; 
        for (auto edge : edgelist) { 
            int w = edge[0]; 
            int x = edge[1]; 
            int y = edge[2]; 

              
  
            // Take this edge in MST if it does 
            // not forms a cycle 
            if (s.find(x) != s.find(y)) { 
                s.unionSets(x, y); 
                ans += w; 
                cout << x << " -- " << y << " == " << w 
                     << endl; 
            } 
        } 
        cout << "Minimum Cost Spanning Tree: " << ans; 
    } 
}; 
  
// Driver code 
int main() 
{ 
    Graph g(4); 
    g.addEdge(0, 1, 10); 
    g.addEdge(1, 3, 15); 
    g.addEdge(2, 3, 4); 
    g.addEdge(2, 0, 6); 
    g.addEdge(0, 3, 5); 
  
    // Function call 
    g.kruskals_mst(); 
  
    return 0; 
}
