#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> dist;

void read() {
    ifstream f("p1.in");
    f >> n;
    dist.resize(n);
    int d;
    for (int i = 0; i < n; ++i) {
        f >> d;
        dist[d].push_back(i + 1);
    }
    f.close();
}

void solve() {
    freopen("p1.out", "w", stdout);
    vector<pair<int, int>> result;

    for (int d = 1; d < n; ++d) {
        if (dist[d - 1].size() == 0) {
            continue;
        }
        for (int u : dist[d]) {
            result.push_back({dist[d - 1][0], u});
        }
    }

    if (result.size() != n - 1) {
        cout << "-1\n";
    } else {
        cout << result.size() << "\n";
        for (auto edge: result) {
            cout << edge.first << " " << edge.second << "\n";
        }
    }
}

int main() {
    read();
    solve();
}