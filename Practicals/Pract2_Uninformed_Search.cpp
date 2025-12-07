#include <iostream>
#include <queue>
using namespace std;

const int V = 5;

int g[V][V] = {
    {0,1,1,0,0},  
    {1,0,0,1,0},  
    {1,0,0,1,1},  
    {0,1,1,0,1},  
    {0,0,1,1,0}   
};

void BFS(int start) {
    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for (int v = 0; v < V; v++) {
            if (g[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void DFS(int u, bool visited[]) {
    visited[u] = true;
    cout << u << " ";

    for (int v = 0; v < V; v++) {
        if (g[u][v] == 1 && !visited[v]) {
            DFS(v, visited);
        }
    }
}

int main() {
    bool visited[V] = {false};
    cout<<"Traversing city graph\n";
    BFS(0);            
    cout << "DFS: ";
    DFS(0, visited);   

    return 0;
}
