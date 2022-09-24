#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int main() {
  int n, x;
  cin >> n >> x;
  vi c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vi dp(x + 1, -1);
  dp[0] = 0;
  for (int i = 1; i <= x; i++) {
    for (int coin : c) {
      if (i >= coin && dp[i - coin] != -1) {
        if (dp[i] == -1) {
          dp[i] = dp[i - coin] + 1;
        } else {
          dp[i] = min(dp[i], dp[i - coin] + 1);
        }
      }
    }
  }
  cout << dp[x] << '\n';
}