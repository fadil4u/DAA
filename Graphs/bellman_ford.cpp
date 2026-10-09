#include <iostream>
using namespace std;

const int INF = 9999;

struct Edge {
    int u, v, w;
};

void bellmanFord(Edge edges[], int n, int e, int src) {
    int dist[20];
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[src] = 0;
    // relax all edges n-1 times
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    // one more pass to detect a negative cycle
    for (int j = 0; j < e; j++) {
        int u = edges[j].u, v = edges[j].v, w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "\nNegative weight cycle found" << endl;
            return;
        }
    }
    cout << "\nShortest distances from vertex " << src << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << src << " -> " << i << " : ";
        if (dist[i] == INF)
            cout << "Unreachable" << endl;
        else
            cout << dist[i] << endl;
    }
}

int main() {
    int n, e, src;
    Edge edges[50];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter directed edges (u v weight):" << endl;
    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    cout << "Enter source vertex: ";
    cin >> src;
    bellmanFord(edges, n, e, src);
    return 0;
}
