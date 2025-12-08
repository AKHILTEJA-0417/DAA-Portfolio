#include <bits/stdc++.h>
using namespace std;

// Structure to store edges
struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int src, vector<Edge> &edges) {
    const int INF = 1e9;

    vector<int> dist(n, INF);
    dist[src] = 0;

    
    for (int i = 1; i <= n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

   
    for (auto &e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            cout << "⚠ Negative weight cycle detected!\n";
            return;
        }
    }

    
    cout << "\nBellman–Ford Shortest Distances from Source (" << src << "):\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            cout << "Node " << i << ": INF\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int n = 5; // Number of vertices

    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    bellmanFord(n, 0, edges);

    return 0;
}
