#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

//define V as a global variable
int V;

//Find the minimum key value
int minEdge(bool included[V], int key[V]) {
    int min = INT_MAX, minI;

    for (int i = 0; i < V; ++i) {
        if (min > key[i] && !included[i]) minI = i, min = key[i];
    }

    return minI;
}


void print(int mst[V]) {
    for (int i = 0; i < V; ++i) {
        cout << mst[i] << " " ;
        if (i != V - 1) cout << "-> " ;
    }
    cout << endl;
}



int prims (int graph[][6], int start) {
    bool verticeIn[V];
    int key[V], mst[V], cost = 0;

    //Initialize the keys to infinite and included state to false
    for (int i = 0; i < V; ++i) verticeIn[i] = false, key[i] = INT_MAX;

    //initialize the key of starting vertex to 0
    key[start] = 0;

    for (int i = 0; i < V; ++i) {
        int u = minEdge(verticeIn, key);
        verticeIn[u] = true;
        mst[i] = u, cost += key[u];

        //Search for all the adjacent vertices and assign keys
        //choosing the vertices to update key values
        //graph[u][v] --> there should be an edge (no edge --> 0)
        //verticeIn[v] should not be in the mst
        //current key is greater than the weight in the graph
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !verticeIn[v] && (key[v] > graph[u][v])) key[v] = graph[u][v];
        }
    }

    print(mst);
    return cost;
}


int main() {
    cout << "Enter the number of vertices in the graph : ";
    cin >> V;

    int graph[][6] = {{0, 3, 0, 0, 0, 1},
                      {3, 0, 2, 1, 10, 0},
                      {0, 2, 0, 3, 0, 5},
                      {0, 1, 3, 0, 5, 0},
                      {0, 10,0, 5, 0, 4},
                      {1, 0, 5, 0, 4, 0}};

    int cost = prims(graph, 0);
    cout << "Cost of the MST : " << cost << endl;
    return 0;
}






