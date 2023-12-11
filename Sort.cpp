#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int cost, destination, remaining_distance;
};

int min_cost(int n, int m, vector<pair<int, int>>& costs, vector<pair<int, int>>& routes) {
    vector<vector<Edge>> graph(n + 1);

    for (int i = 1; i <= n; ++i) {
        graph[0].push_back({costs[i].first, i, 0});
    }

    for (int i = 0; i < m; ++i) {
        int u = routes[i].first;
        int v = routes[i].second;
        graph[u].push_back({0, v, 0});
        graph[v].push_back({0, u, 0});
    }

    vector<int> dist(n + 1, INT_MAX);
    dist[0] = 0;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 0});  // (cost, node, remaining_distance)

    while (!pq.empty()) {
        auto [cost, node, remaining_distance] = pq.top();
        pq.pop();

        if (dist[node] < remaining_distance) {
            continue;
        }

        for (const auto& edge : graph[node]) {
            int neighbor_cost = edge.cost;
            int neighbor = edge.destination;
            int neighbor_distance = edge.remaining_distance;

            int new_cost = cost + neighbor_cost;
            int new_distance = remaining_distance - 1;

            if (new_cost < dist[neighbor] && new_distance >= 0) {
                dist[neighbor] = new_cost;
                pq.push({new_cost, neighbor, new_distance});
            }
        }
    }

    return dist[n];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> costs(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> costs[i].first >> costs[i].second;
    }

    vector<pair<int, int>> routes(m);
    for (int i = 0; i < m; ++i) {
        cin >> routes[i].first >> routes[i].second;
    }

    int result = min_cost(n, m, costs, routes);
    cout << result << endl;

    return 0;
}
