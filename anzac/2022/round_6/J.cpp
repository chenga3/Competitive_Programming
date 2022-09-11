#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

int MOD = 998244353;

int main() {
  int n, k;
  cin >> n >> k;

  vi points(n);
  for (int i = 0; i < n; i++) {
    cin >> points[i];
  }

  // count freqs of points
  map<int, int> freqs;
  for (int i = 0; i < n; i++) {
    freqs[points[i]]++;
  }

  // store unique point values in ascending order
  vi unique_points;
  int count = 0;
  for (auto [point, freq] : freqs) {
    unique_points.push_back(point);
    count++;
  }

  // DP!!
  vvi dp(count, vector<int>(k + 1));
  dp[0][1] = freqs[unique_points[0]];
  for (int i = 1; i < unique_points.size(); i++) {
    for (int w = 1; w <= min(i + 1, k); w++) {
      if (w == 1) {
        dp[i][w] = (dp[i - 1][w] + freqs[unique_points[i]]) % MOD;
      } else {
        dp[i][w] = ((dp[i - 1][w - 1] * freqs[unique_points[i]]) % MOD +
                    dp[i - 1][w]) %
                   MOD;
      }
    }
  }

  cout << dp[unique_points.size() - 1][k] % MOD << '\n';

  return 0;
}