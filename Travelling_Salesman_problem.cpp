#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
#include<map>

using namespace std;


class Graph {
private:
    int numCities;
    vector<vector<int>> adjMatrix;

public:

    Graph(int cities) : numCities(cities), adjMatrix(cities, vector<int>(cities, 0)) {}

    
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; 
    }

    
    int getDistance(int u, int v) const {
        return adjMatrix[u][v];
    }

    
    int getNumCities() {
        return numCities;
    }
};


class TSP {
private:
     Graph graph;
   
    int numCities;

    
    int tspHelper(int currentCity, set<int>& visited) {

        if (visited.size() == numCities) {
            return graph.getDistance(currentCity, 0);
        }

        
     int minCost = INT_MAX;

        
        for (int city = 0; city < numCities; city++) {
            if (visited.find(city)== visited.end()) {
                visited.insert(city); 
                int current_cost = graph.getDistance(currentCity, city) + tspHelper(city, visited);
                minCost = min(minCost, current_cost);
                visited.erase(city); 
            }
        }

        
       
        return minCost;
    }

public:
   
    TSP( Graph g) : graph(g), numCities(g.getNumCities()) {}


    int solve() {
        set<int> visited;
        visited.insert(0); 
        return tspHelper(0, visited);
    }
};

int main() {
    int numCities = 4;
    Graph graph(numCities);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 20);
    graph.addEdge(1, 2, 35);
    graph.addEdge(1, 3, 25);
    graph.addEdge(2, 3, 30);

   
    TSP tsp(graph);

    
    int minCost = tsp.solve();
    cout << "Minimum cost: " << minCost << endl;

    return 0;
}
