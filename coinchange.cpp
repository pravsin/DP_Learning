#include<bits/stdc++.h>

using namespace std;

long long countWays(const vector<int> &coins, int m, int n) {
    vector<long long> dp(n+1,0);
    dp[0]=1;
    for (int i = 0; i < m; ++i) {
        for (int j = coins[i]; j <= n; ++j) {
            dp[j]+=dp[j-coins[i]];
        }
    }
    return dp[n];
}

int maincc() {
    int n, m;
    cin>>n>>m;
    vector<int> coins(m);
    for (int i = 0; i < m; ++i) {
        cin >> coins[i];
    }
    cout << countWays(coins, coins.size(), n);
    return 0;
}
