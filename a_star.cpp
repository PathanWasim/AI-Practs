#include <iostream>
#include <cmath>
using namespace std;

const int N = 5;

struct Node {
    int x, y, g, f;
};

int heuristic(int x, int y, int gx, int gy) {
    return abs(x - gx) + abs(y - gy);
}

void aStar(int sx, int sy, int gx, int gy) {
    bool visited[N][N] = {false};
    Node openList[100];
    int openSize = 0;
    int parentX[N][N], parentY[N][N];

    openList[openSize++] = {sx, sy, 0, heuristic(sx, sy, gx, gy)};
    visited[sx][sy] = true;
    parentX[sx][sy] = -1;
    parentY[sx][sy] = -1;

    while(openSize > 0) {
        int bestIndex = 0;
        int bestF = openList[0].f;
        for(int i=1; i<openSize; i++) {
            if(openList[i].f < bestF) {
                bestF = openList[i].f;
                bestIndex = i;
            }
        }

        Node current = openList[bestIndex];

        for(int i=bestIndex; i<openSize-1; i++)
            openList[i] = openList[i+1];
        openSize--;

        if(current.x == gx && current.y == gy) {
            cout << "Goal reached!\nPath: ";
            int pathX[100], pathY[100], idx = 0;
            int cx = gx, cy = gy;
            while(cx != -1 && cy != -1) {
                pathX[idx] = cx;
                pathY[idx] = cy;
                int px = parentX[cx][cy];
                int py = parentY[cx][cy];
                cx = px;
                cy = py;
                idx++;
            }
            for(int i=idx-1; i>=0; i--)
                cout << "(" << pathX[i] << "," << pathY[i] << ") ";
            cout << endl;
            return;
        }

        visited[current.x][current.y] = true;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int i=0; i<4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if(nx>=0 && ny>=0 && nx<N && ny<N && !visited[nx][ny]) {
                int g = current.g + 1;
                int h = heuristic(nx, ny, gx, gy);
                int f = g + h;
                openList[openSize++] = {nx, ny, g, f};
                visited[nx][ny] = true;
                parentX[nx][ny] = current.x;
                parentY[nx][ny] = current.y;
            }
        }
    }

    cout << "No path found!\n";
}

int main() {
    aStar(0, 0, 4, 4);
    return 0;
}
