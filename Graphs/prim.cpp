#include <iostream>
using namespace std;

const int INF = 9999;
int cost[20][20];

void prim(int n) {
    int key[20], parent[20];
    bool inTree[20];
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
        inTree[i] = false;
    }
    key[0] = 0;
    for (int c = 0; c < n; c++) {
        // pick the cheapest vertex not yet in the tree
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!inTree[i] && (u == -1 || key[i] < key[u]))
                u = i;
        inTree[u] = true;
        for (int v = 0; v < n; v++) {
            if (cost[u][v] && !inTree[v] && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }
    int total = 0;
    cout << "\nMinimum Spanning Tree:" << endl;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << cost[i][parent[i]] << endl;
        total += cost[i][parent[i]];
    }
    cout << "Total weight: " << total << endl;
}

int main() {
    int n, e, u, v, w;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        cost[u][v] = cost[v][u] = w;
    }
    prim(n);
    return 0;
}
