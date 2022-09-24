#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

const int MOD = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;
  vi coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  vi dp(x + 1);
  dp[0] = 1;
  vi lastCoin(x + 1);
  for (int i = 1; i <= x; i++) {
    for (int c : coins) {
      if (c <= i && c >= lastCoin[i - c]) {
        dp[i] += dp[]
      }
    }
  }
}