#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 1e9;
int n;
int dist[20][20];
int dp[1 << 20][20];

int tsp(int mask, int pos) {
    // If all cities are visited, return distance to starting city
    if(mask == (1 << n) - 1)
        return dist[pos][0];

    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    for(int city = 0; city < n; city++) {
        if((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] +
                         tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    n = 4;  // Number of cities

    int temp[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Copy to global array
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dist[i][j] = temp[i][j];

    memset(dp, -1, sizeof(dp));

    cout << "Minimum travelling cost: " << tsp(1, 0);

    return 0;
}