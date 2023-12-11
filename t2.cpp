#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize the adjacency matrix with INF values
    vector<vector<int>> d(n, vector<int>(n, INF));

    // Read input and update the matrix with edge weights
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u - 1][v - 1] = w;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] < INF && d[k][j] < INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    // Output the result
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][j] == INF) {
                cout << -1 << " ";
            } else {
                cout << d[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
