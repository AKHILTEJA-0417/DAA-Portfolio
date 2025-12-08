#include <iostream>
using namespace std;

#define MAXN 100
#define INF 999

int main() {
    int n;
    cout << "Enter the number of Vertices\n";
    cin >> n;

    int cost[MAXN][MAXN];

    cout << "Enter the cost matrix: (Enter 999 for Infinity)\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int source;
    cout << "Enter the source\n";
    cin >> source;

    int dist[MAXN], path[MAXN], visited[MAXN];

    for (int i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        path[i] = source;
        visited[i] = 0;
    }
    visited[source] = 1;

    for (int iter = 0; iter < n - 1; iter++) {
        int u = -1;
        int min = INF + 1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != INF) {
                if (dist[u] + cost[u][v] < dist[v]) {
                    dist[v] = dist[u] + cost[u][v];
                    path[v] = u;
                }
            }
        }
    }

    cout << "\nVertex   Dist   Path\n";
    for (int i = 0; i < n; i++) {
        cout << i << "   " << dist[i] << "   " << path[i] << "\n";
    }

    return 0;
}
