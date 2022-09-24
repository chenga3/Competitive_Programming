#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  vector<int> dp(x + 1);
  dp[0] = 1;
  for (int i = 1; i <= x; i++) {
    for (int c : coins) {
      if (c <= i) {
        dp[i] = (dp[i] + dp[i - c]) % MOD;
      }
    }
  }
  cout << dp[x] << '\n';
}