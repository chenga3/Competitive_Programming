#include <bits/stdc++.h>

using namespace std;

using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  int h, p;
  vpi options(k);
  for (int i = 0; i < k; i++) {
    cin >> h >> p;
    options[i] = {h, p};
  }
  sort(options.begin(), options.end());
  int maxH = options[options.size() - 1].first;
  vector<int> dp(n + maxH, INT_MAX);
  dp[0] = 0;
  for (int i = 0; i < n + maxH; i++) {
    for (auto [h, p] : options) {
      if (i >= h && dp[i - h] < INT_MAX) {
        dp[i] = min(dp[i], dp[i - h] + p);
      }
    }
  }
  int ans = INT_MAX;
  for (int i = n; i < n + maxH; i++) {
    ans = min(ans, dp[i]);
  }
  cout << ans << '\n';
}