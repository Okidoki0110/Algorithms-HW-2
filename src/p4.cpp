#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

#define MAXT 101
#define MAXN 201

int type[MAXN][MAXN];
int cost[MAXN][MAXN];
int penalty[MAXT];
// programare dinamica, dist[i][conf] = distanta pana la nodul i 
// cu drumul parcurs avand tipurile de muchii descrise sub forma binara in conf
long long dist[MAXN][128];
bool inQueue[MAXN];
int n, m, T;

void bellman() {
    const long long INF = 1000000000LL * 201LL;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 128; ++j) {
            dist[i][j] = 1000000000LL * 201LL;
        }
    }
    dist[1][0] = 0;

    queue<int> Q;
    Q.push(1);
    inQueue[1] = true;


    while (!Q.empty()) {
        int u = Q.front();
        //cout << u << "\n";
        inQueue[u] = false;
        Q.pop();
        for (int v = 1; v <= n; ++v) {
            if (cost[u][v] > 0) {
                int t1 = type[u][v];
                for (int conf = 0; conf < 128; ++conf) {
                    if (conf & (1 << (t1 - 1))) {
                        int oldConf = conf ^ (1 << (t1 - 1));
                        // cazul cand e prima oara cand adaugam tipul muchiei in drum
                        if (dist[v][conf] > dist[u][oldConf] + cost[u][v] + penalty[t1]) {
                            dist[v][conf] = dist[u][oldConf] + cost[u][v] + penalty[t1];
                            if (!inQueue[v]) {
                                inQueue[v] = true;
                                Q.push(v);
                            }
                        }

                        // cazul cand am mai adaugat tipul muchiei in drum, deci nu mai adaugam penalty
                        if (dist[v][conf] > dist[u][conf] + cost[u][v]) {
                            dist[v][conf] = dist[u][conf] + cost[u][v];
                            if (!inQueue[v]) {
                                inQueue[v] = true;
                                Q.push(v);
                            }
                        }
                    }
                }
            }
        }
    }

    long long result = INF;
    for (int t = 0; t < 128; ++t) {
        result = min(result, dist[n][t]);
    }

    freopen("p4.out", "w", stdout);

    if (result == INF) {
        cout << "-1\n";
    } else {
        cout << result << "\n";
    }
}

int main() {
    freopen("p4.in", "r", stdin);
    cin >> n >> m >> T;
    int u, v, c, t;
    while (m--) {
        cin >> u >> v >> c >> t;
        cost[u][v] = cost[v][u] = c;
        type[u][v] = type[v][u] = t;
    }
    for (int i = 1; i <= T; ++i) {
        cin >> penalty[i];
    }
    
    bellman();
}