#include <iostream>
using namespace std;

const int INF = 9999;

int main() {
    int n, d[20][20];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter weight matrix (0 = no edge):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
            if (i != j && d[i][j] == 0)
                d[i][j] = INF;
        }
    }
    // try every vertex k as an intermediate
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
    cout << "\nAll pairs shortest distances:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] == INF)
                cout << "INF\t";
            else
                cout << d[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
