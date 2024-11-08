#include<bits/stdc++.h>
using namespace std;

class Graph {

    int V;
    vector<vector<int>> adjList;

public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    
friend class GraphColoring;
};   



class GraphColoring{
  Graph gr;
  vector<int>color;
  int max;

  public:
  GraphColoring(Graph& g , int m ) : gr(g) , max(m){

    color.resize(gr.V,-1);
  }

 bool isSafe(int v, int c) {
        for (int i : gr.adjList[v]) { 
            if(color[i] == c) {
                return false;
            }
        }
        return true;
    }

bool colorGraphUtil(int v) {
        // If all vertices are assigned a color, return true
        if (v == gr.V) {
            return true;
        }

        // Try assigning each color from 0 to m-1
        for (int c = 0; c < max; c++) {
            if (isSafe(v, c)) {
                color[v] = c;  // Assign color c to vertex v

                // Recursively assign colors to the remaining vertices
                if (colorGraphUtil(v + 1)) {
                    return true;
                }

                // If assigning color c doesn't lead to a solution, remove it (backtrack)
                color[v] = -1;
            }
        }
        return false;  // If no color can be assigned to this vertex, return false
    }

    bool colorGraph() {
        if (colorGraphUtil(0)) {
            // Display the colors assigned to each vertex if coloring is successful
            for (int v = 0; v < gr.V; ++v) {
                cout << "Vertex " << v << " --->  Color " << color[v] << endl;
            }
            return true;
        } else {
            cout << "Solution does not exist with " << max << " colors." << endl;
            return false;
        }
    }


   
  

};


int main(){
int vertices = 5;
    Graph g(vertices);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);



    std::cout << "Coloring of the graph:\n"; 

     GraphColoring Gc(g,3);
     Gc.colorGraph();

    return 0;
}