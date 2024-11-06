#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Constructor to initialize the disjoint set
    DisjointSet(int n) {
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
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
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

int main() {
    int n = 5;
    DisjointSet ds(n);

    ds.unionSets(0, 2);
    ds.unionSets(4, 2);
    ds.unionSets(3, 1);

     cout << "0 and 4 are connected: " << ds.isConnected(0, 4) <<endl; // True
    cout << "1 and 0 are connected: " << ds.isConnected(1, 0) <<endl; // False

    ds.unionSets(1, 4);

    cout << "1 and 0 are connected: " << ds.isConnected(1, 0) <<endl; // True

    return 0;
}
