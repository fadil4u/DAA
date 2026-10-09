#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[20];

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void kruskal(Edge edges[], int n, int e) {
    for (int i = 0; i < n; i++)
        parent[i] = i;
    sort(edges, edges + e, compare);
    int total = 0, count = 0;
    cout << "\nMinimum Spanning Tree:" << endl;
    for (int i = 0; i < e && count < n - 1; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);
        if (a != b) {
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << endl;
            total += edges[i].w;
            parent[a] = b;
            count++;
        }
    }
    cout << "Total weight: " << total << endl;
}

int main() {
    int n, e;
    Edge edges[50];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    kruskal(edges, n, e);
    return 0;
}
