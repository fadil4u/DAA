#include <iostream>
using namespace std;

int adj[20][20], visited[20];

void dfs(int u, int n) {
    visited[u] = 1;
    cout << u << " ";
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !visited[v])
            dfs(v, n);
    }
}

int main() {
    int n, e, u, v, start;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    cout << "Enter starting vertex: ";
    cin >> start;
    cout << "DFS Traversal: ";
    dfs(start, n);
    cout << endl;
    return 0;
}
