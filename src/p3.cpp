#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

#define MAXT 101
#define MAXN 201

int type[MAXN][MAXN];
int cost[MAXN][MAXN];
int penalty[MAXT][MAXT];
// programare dinamica, dist[i][j] = distanta pana la nodul i cu ultima muchie de tipul j
long long dist[MAXN][MAXT];
bool inQueue[MAXN];
int n, m, T;

void bellman() {
    const long long INF = 1000000000LL * 201LL;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= T; ++j) {
            dist[i][j] = 1000000000LL * 201LL;
        }
    }

    queue<int> Q;
    Q.push(1);
    inQueue[1] = true;

    while (!Q.empty()) {
        int u = Q.front();
        inQueue[u] = false;
        Q.pop();
        for (int v = 1; v <= n; ++v) {
            if (cost[u][v] > 0) {
                int t1 = type[u][v];
                for (int t2 = 1; t2 <= T; ++t2) {
                    if (dist[v][t1] > dist[u][t2] + cost[u][v] + penalty[t2][t1]) {
                        dist[v][t1] = dist[u][t2] + cost[u][v] + penalty[t2][t1];
                        if (!inQueue[v]) {
                            inQueue[v] = true;
                            Q.push(v);
                        }
                    }
                }
            }
        }
    }

    long long result = INF;
    for (int t = 1; t <= T; ++t) {
        result = min(result, dist[n][t]);
    }

    freopen("p3.out", "w", stdout);

    if (result == INF) {
        cout << "-1\n";
    } else {
        cout << result << "\n";
    }
}

int main() {
    freopen("p3.in", "r", stdin);
    cin >> n >> m >> T;
    int u, v, c, t;
    while (m--) {
        cin >> u >> v >> c >> t;
        cost[u][v] = cost[v][u] = c;
        type[u][v] = type[v][u] = t;
    }
    for (int i = 1; i <= T; ++i) {
        for (int j = 1; j <= T; ++j) {
            cin >> c;
            penalty[i][j] = penalty[j][i] = c;
        }
    }
    
    bellman();
}