#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi h(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    // Binary search for the solution.
    int maxH = *max_element(h.begin(), h.end());
    int minH = *min_element(h.begin(), h.end());
    int l = minH, r = maxH + 1;
    while (l < r - 1) {
      int x = l + (r - l) / 2;  // Try this value as a solution.
      bool possible = true;
      vi newH(h);
      for (int i = newH.size() - 1; i >= 2; i--) {
        if (newH[i] < x) {
          // We cannot achieve this minimum heap value, so try a lower number.
          possible = false;
          break;
        }
        int d = min(h[i], newH[i] - x) / 3;  // Make sure we aren't moving more
                                             // stones than we had originally.
        newH[i] -= 3 * d;
        newH[i - 1] += d;
        newH[i - 2] += 2 * d;
      }
      // Need to check first two heaps too.
      if (newH[0] < x || newH[1] < x) {
        possible = false;
      }
      if (possible) {
        l = x;
      } else {
        r = x;
      }
    }
    cout << l << '\n';
  }
}