#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int dist[4][4], int n, int start) {
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    dp[1 << start][start] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;

            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;

                if (dp[mask][u] != -1) {
                    int next_mask = mask | (1 << v);
                    int next_dist = dp[mask][u] + dist[u][v];
                    if (dp[next_mask][v] == -1 || next_dist < dp[next_mask][v]) {
                        dp[next_mask][v] = next_dist;
                    }
                }
            }
        }
    }
    int min_cost = INT_MAX;
    for (int u = 0; u < n; u++) {
        if (dp[(1 << n) - 1][u] != -1) {
            min_cost = min(min_cost, dp[(1 << n) - 1][u] + dist[u][start]);
        }
    }

    return min_cost;
}

int main() {
    return 0;
}
