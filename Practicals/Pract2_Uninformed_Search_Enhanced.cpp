#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) : V(vertices)
    {
        adj.resize(vertices);
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    // Breadth First Search
    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> queue;

        visited[start] = true;
        queue.push(start);

        cout << "BFS starting from vertex " << start << ": ";
        while (!queue.empty())
        {
            start = queue.front();
            cout << start << " ";
            queue.pop();

            for (int adjacent : adj[start])
            {
                if (!visited[adjacent])
                {
                    visited[adjacent] = true;
                    queue.push(adjacent);
                }
            }
        }
        cout << endl;
    }

    // Depth First Search (Recursive)
    void DFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";

        for (int adjacent : adj[v])
        {
            if (!visited[adjacent])
                DFSUtil(adjacent, visited);
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);
        cout << "DFS starting from vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // Depth Limited Search
    bool DLSUtil(int v, int target, int limit, vector<bool> &visited)
    {
        if (v == target)
            return true;

        if (limit <= 0)
            return false;

        visited[v] = true;
        for (int adjacent : adj[v])
        {
            if (!visited[adjacent])
            {
                if (DLSUtil(adjacent, target, limit - 1, visited))
                    return true;
            }
        }
        visited[v] = false;
        return false;
    }

    bool DLS(int start, int target, int limit)
    {
        vector<bool> visited(V, false);
        return DLSUtil(start, target, limit, visited);
    }

    // Iterative Deepening DFS
    bool IDDFS(int start, int target, int max_depth)
    {
        cout << "IDDFS from " << start << " to " << target << " with max depth " << max_depth << ":\n";
        for (int i = 0; i <= max_depth; i++)
        {
            cout << "Trying depth " << i << ": ";
            if (DLS(start, target, i))
            {
                cout << "Found target at depth " << i << endl;
                return true;
            }
            cout << "Not found\n";
        }
        return false;
    }
};

int main()
{
    // Create a sample graph
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    // Demonstrate BFS
    g.BFS(0);

    // Demonstrate DFS
    g.DFS(0);

    // Demonstrate Iterative Deepening DFS
    int start = 0, target = 6, max_depth = 4;
    cout << "\nTrying to find path from " << start << " to " << target << " using IDDFS:\n";
    if (g.IDDFS(start, target, max_depth))
    {
        cout << "Path exists within max depth " << max_depth << endl;
    }
    else
    {
        cout << "Path does not exist within max depth " << max_depth << endl;
    }

    return 0;
}