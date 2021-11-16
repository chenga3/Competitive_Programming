#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // Idea: root node has 6 colouring options while every other has 4 colouring
  // options. Iterating through every node to multiply all numbers together is
  // far too slow (up to 2 ^ 60 operations). Instead use a bottom up approach to
  // calculate the product of increasing sized sub-trees, making use of squaring
  // to avoid unnecessary repeated calculations.

  // Edge case: k = 1.

  int k;
  cin >> k;

  if (k == 1) {
    cout << 6 << '\n';
  } else {
    ll ans = 4;
    // 10^9 ^ 2 * 6 < 9 * 10^18 so no risk of overflowing long long.
    for (int i = 0; i < k - 2; i++) {
      ans = ans * ans * 4 % ((int)1e9 + 7);
    }
    ans = ans * ans * 6 % ((int)1e9 + 7);
    cout << ans << '\n';
  }
}
