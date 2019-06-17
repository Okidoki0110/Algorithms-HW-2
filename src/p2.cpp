#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 100

int n, m, K;
int a[MAXN][MAXN];
bool seen[MAXN][MAXN];
int maxArea = 0, currentArea;

int xx[4] = {-1, 0, 1, 0};
int yy[4] = {0, 1, 0, -1};

void dfs(int i, int j, int minim) {
    if (a[i][j] < minim || a[i][j] - minim > K) {
        return;
    }
    if (seen[i][j]) {
        return;
    }
    ++currentArea;
    seen[i][j] = true;

    for (int k = 0; k < 4; ++k) {
        int x = i + xx[k];
        int y = j + yy[k];
        if (x >= 0 && x < n && y >= 0 && y < m && !seen[x][y]) {
            dfs(x, y, minim);
        }
    }

}

void solve() {
    int i, j;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            memset(seen, 0, sizeof(seen));
            currentArea = 0;
            dfs(i, j, a[i][j]);
            maxArea = max(maxArea, currentArea);
        }
    }

    freopen("p2.out", "w", stdout);
    cout << maxArea << "\n";
}


int main() {
    freopen("p2.in", "r", stdin);
    cin >> n >> m >> K;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    solve();
}