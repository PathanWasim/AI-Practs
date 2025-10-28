#include <iostream>
using namespace std;

const int MAX = 5;
int graph[MAX][MAX] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 0, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 1, 0}};

bool visited[MAX];

void dfs(int node)
{
    cout << node << " ";
    visited[node] = true;
    for (int i = 0; i < MAX; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

void bfs(int start)
{
    bool visited[MAX] = {false};
    int queue[MAX], front = 0, rear = 0;
    visited[start] = true;
    queue[rear++] = start;

    while (front < rear)
    {
        int node = queue[front++];
        cout << node << " ";
        for (int i = 0; i < MAX; i++)
        {
            if (graph[node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < MAX; i++)
        visited[i] = false;
    cout << "DFS starting from node 0: ";
    dfs(0);

    cout << "\nBFS starting from node 0: ";
    bfs(0);

    return 0;
}
