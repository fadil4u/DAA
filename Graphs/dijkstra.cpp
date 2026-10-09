#include <iostream>
using namespace std;

const int INF = 9999;
int cost[20][20];

void dijkstra(int n, int src) {
    int dist[20];
    bool done[20];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        done[i] = false;
    }
    dist[src] = 0;
    for (int c = 0; c < n; c++) {
        // pick the closest unfinished vertex
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!done[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        if (dist[u] == INF)
            break;
        done[u] = true;
        for (int v = 0; v < n; v++) {
            if (cost[u][v] && !done[v] && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
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
    int n, e, u, v, w, src;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        cost[u][v] = cost[v][u] = w;
    }
    cout << "Enter source vertex: ";
    cin >> src;
    dijkstra(n, src);
    return 0;
}
