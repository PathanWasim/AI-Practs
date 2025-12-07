#include <iostream>
using namespace std;

const int N = 4;      // 4 regions
int g[N][N] = {      // Adjacency matrix
    {0,1,1,0},
    {1,0,1,1},
    {1,1,0,1},
    {0,1,1,0}
};

int color[N];        // color of each region
int C = 3;           // number of colors

bool safe(int v, int c) {
    for(int i=0;i<N;i++)
        if(g[v][i] && color[i]==c)
            return false;
    return true;
}

bool solve(int v) {
    if(v==N) return true;

    for(int c=1;c<=C;c++){
        if(safe(v,c)){
            color[v]=c;
            if(solve(v+1)) return true;
            color[v]=0;   // backtrack
        }
    }
    return false;
}

int main() {
    for(int i=0;i<N;i++) color[i]=0;

    if(solve(0)){
        cout<<"Graph Coloring Solution:\n";
        for(int i=0;i<N;i++)
            cout<<"Region "<<i<<" -> Color "<<color[i]<<endl;
    }
    else
        cout<<"No solution";

    return 0;
}
