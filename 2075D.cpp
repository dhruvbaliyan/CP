// https://codeforces.com/problemset/problem/2075/D
//Applying the concept of pick and non pick

#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[64][64][64];

int dpp(int a, int b, int k) {
    if (k == 0 || a < 0 || b < 0)  
        return (a || b) ? (1LL << 61) : 0;

    // int &ret = dp[a][b][k];
    if (dp[a][b][k] != -1) return dp[a][b][k];

    int pick1 = dpp(a - k, b, k - 1) + (1LL << k);
    int pick2 = dpp(a, b - k, k - 1) + (1LL << k);
    int npick = dpp(a, b, k - 1);

    return dp[a][b][k] = min({pick1, pick2, npick});
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        int ans = 1LL << 62;  // Prevent overflow

        for (int i = 0; i <= 60; i++) {
            for (int j = 0; j <= 60; j++) {
                if ((x >> i) == (y >> j)) {
                    ans = min(ans, dpp(i, j, max(i, j)));
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
