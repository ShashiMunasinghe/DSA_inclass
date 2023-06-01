#include <iostream>
#include <limits.h>
#include <vector>
#include <numeric>

using namespace std;

//find the minimum time city
int minTime(vector <int> time, vector <bool> visited) {
    int min = INT_MAX, minI;
    for (int i = 0;i < time.size(); ++i) {
        if (!visited[i] && time[i] < min) {
            min = time[i];
            minI = i;
        }
    }

    return minI;
}


vector <int> dijkstras(vector <vector <int> > graph, int source)
{
    //initialize the values in the time vector to infinite and time of source to 0
    vector <int> time(graph.size(), INT_MAX);
    time[source] = 0;
    vector <bool> visited(graph.size(), false);     //get a vector to record the visited cities


    //get the minimum weighted node
    //do the relaxation if following conditions satisfy
    for (int i = 0; i < graph.size() - 1; ++i) {
        int minTimeCity = minTime(time, visited);
        visited[minTimeCity] = true;

        for(int j = 0; j < graph.size(); j++){
            if (!visited[j] && graph[minTimeCity][j] && time[j] > time[minTimeCity] + graph[minTimeCity][j]) {
                time[j] = time[minTimeCity] + graph[minTimeCity][j];
            }
        }
    }

    return time;
}

//print the time to each city from the source
void print(vector <int> time, int source) {
    for (int i = 0; i < time.size(); ++i) {
        if (i != source) cout << "City " << source << " -> City " << i << " : " << time[i] << endl;
    }
    cout << endl;
}

int main() {
    vector <vector <int>> graph;
    graph = {{0, 10, 0, 0, 15, 5},
             {10, 0, 10, 30, 0, 0},
             {0, 10, 0, 12, 5, 0},
             {0, 30, 12, 0, 0, 20},
             {15, 0, 5, 0, 0, 0},
             {5, 0, 0, 20, 0, 0}};

    vector <int> time = dijkstras(graph, 5);
    print(time, 5);

    return 0;
}