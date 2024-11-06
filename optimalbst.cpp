#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Items {
public:
    vector<int> keys;
    vector<int> frequencies;

    Items(int n) {
        keys.resize(n);
        frequencies.resize(n);
    }
};

class OptimalBST {
private:
    Items items;
    vector<vector<int>> cost; // Cost table
    vector<vector<int>> root; // Root table for reconstruction
    int n;

public:
    OptimalBST(Items& items) : items(items), n(items.keys.size()) {
        // Resize cost and root matrices to be of size (n+1) x (n+1)
        cost.resize(n + 1, vector<int>(n + 1, 0));
        root.resize(n + 1, vector<int>(n + 1, 0));
        calculateOptimalBST();
    }

    void calculateOptimalBST() {
        // Initialize the diagonal elements of the cost matrix to 0
        for (int i = 0; i <= n; ++i) {
            cost[i][i] = 0;  // Diagonal is initialized to 0
        }

        // Fill the first upper diagonal directly with the frequencies
        for (int i = 0; i < n; ++i) {
            cost[i][i + 1] = items.frequencies[i];  // Upper diagonal initialized with frequencies
            root[i][i + 1] = i + 1;  // Root for single node is the node itself (1-based index)
        }

        // Now, calculate the cost and root for the remaining upper diagonal elements
        for (int len = 2; len <= n; ++len) { // len is the chain length
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len; // Set j based on the chain length
                cost[i][j] = numeric_limits<int>::max(); // Initialize to a high cost
                
                // Calculate the sum of frequencies for the range i+1 to j
                int sumFreq = 0;
                for (int m = i + 1; m <= j; ++m) {
                    sumFreq += items.frequencies[m-1];
                }

                // Try all roots k from i+1 to j
                for (int k = i + 1; k <= j; ++k) {
                    int c = cost[i][k - 1] + cost[k][j] + sumFreq;
                    if (c < cost[i][j]) {
                        cost[i][j] = c;  // Store the minimum cost
                        root[i][j] = k;  // Store the root where the minimum cost was found
                    }
                }
            }
        }
    }

    void printCost() {
        cout << "Cost Table:\n";
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i <= j) {
                    cout << (cost[i][j] == numeric_limits<int>::max() ? 0 : cost[i][j]) << "\t";
                } else {
                    cout << "-\t"; // Do not print lower diagonal
                }
            }
            cout << endl;
        }
    }

    void printRoot() {
        cout << "Root Table:\n";
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i <= j) {
                    cout << root[i][j] << "\t";
                } else {
                    cout << "-\t"; // Do not print lower diagonal
                }
            }
            cout << endl;
        }
    }
};

class Graph {
public:
    Graph() {}

    void optimalBSTFromAdjMatrix(vector<vector<int>>& adjMatrix) {
        int n = adjMatrix.size(); // Number of keys

        Items items(n);

        // Set keys and frequencies from the adjacency matrix
        for (int i = 0; i < n; ++i) {
            items.keys[i] = adjMatrix[i][0]; // First column as keys
            items.frequencies[i] = adjMatrix[i][1]; // Second column as frequencies
        }

        OptimalBST optimalBST(items);
        optimalBST.printCost();
        optimalBST.printRoot();
    }
};

int main() {
    // Example adjacency matrix input:
    // [key, frequency]
    vector<vector<int>> adjMatrix = {
        {10, 4},
        {20, 2},
        {30, 6},
        {40,3}
    };

    Graph graph;
    graph.optimalBSTFromAdjMatrix(adjMatrix);

    return 0;
}