#include <iostream>
#include <cmath>
using namespace std;

const int N = 5;
int grid[N][N] = {0};

struct Node
{
    int x, y;
};

int heuristic(int x, int y, int gx, int gy)
{
    return abs(x - gx) + abs(y - gy);
}

void greedyBestFirst(int sx, int sy, int gx, int gy)
{
    bool visited[N][N] = {false};
    Node openList[100];
    int openSize = 0;

    openList[openSize++] = {sx, sy};
    visited[sx][sy] = true;

    cout << "Path: ";

    while (openSize > 0)
    {
        int bestIndex = 0;
        int bestH = heuristic(openList[0].x, openList[0].y, gx, gy);

        for (int i = 1; i < openSize; i++)
        {
            int h = heuristic(openList[i].x, openList[i].y, gx, gy);
            if (h < bestH)
            {
                bestH = h;
                bestIndex = i;
            }
        }

        Node current = openList[bestIndex];
        cout << "(" << current.x << "," << current.y << ") ";

        for (int i = bestIndex; i < openSize - 1; i++)
        {
            openList[i] = openList[i + 1];
        }
        openSize--;

        if (current.x == gx && current.y == gy)
        {
            cout << "\nGoal reached!";
            return;
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++)
        {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                openList[openSize++] = {nx, ny};
            }
        }
    }
    cout << "\nNo path found!";
}

int main()
{
    greedyBestFirst(0, 0, 4, 4);
    return 0;
}
