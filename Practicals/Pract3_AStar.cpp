#include <iostream>
using namespace std;

const int N = 4;

// Graph (cost between nodes)
int g[N][N] = {
    {0, 1, 4, 0},   // 0
    {1, 0, 2, 5},   // 1
    {4, 2, 0, 1},   // 2
    {0, 5, 1, 0}    // 3
};

// Heuristic values to goal (node 3)
int h[N] = {7, 6, 2, 0};

int main() {
    bool open[N] = {false};
    bool closed[N] = {false};
    int gCost[N], parent[N];

    for(int i=0;i<N;i++){
        gCost[i] = 999;
        parent[i] = -1;
    }

    int start = 0, goal = 3;
    gCost[start] = 0;
    open[start] = true;

    while(true){
        int current = -1, bestF = 999;

        // pick node with lowest f = g + h
        for(int i=0;i<N;i++){
            if(open[i] && gCost[i] + h[i] < bestF){
                bestF = gCost[i] + h[i];
                current = i;
            }
        }

        if(current == -1) break;
        if(current == goal) break;

        open[current] = false;
        closed[current] = true;

        for(int v=0; v<N; v++){
            if(g[current][v] > 0 && !closed[v]){
                int newCost = gCost[current] + g[current][v];
                if(newCost < gCost[v]){
                    gCost[v] = newCost;
                    parent[v] = current;
                    open[v] = true;
                }
            }
        }
    }

    // Print Path
    cout<<"Shortest path finding in road network\n";
    cout << "A* Path: ";
    int path[N], cnt = 0;
    int node = goal;
    while(node != -1){
        path[cnt++] = node;
        node = parent[node];
    }

    for(int i = cnt-1; i >= 0; i--)
        cout << path[i] << " ";

    cout << "\nTotal Cost = " << gCost[goal];
    return 0;
}
