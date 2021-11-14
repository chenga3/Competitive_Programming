#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int tc = 0; tc < t; tc++) {
    int n;
    cin >> n;
    vi a(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // Finding minimum via linear scan and updating all elements is too slow -
    // quadratic.
    sort(a.begin(), a.end());

    int maxmin = a[0];
    for (int i = 1; i < n; i++) {
      // Key idea: subtractions of earlier minima are cancelled out - only the
      // the original value of the previous minimum influences the current
      // minimum.
      maxmin = max(maxmin, a[i] - a[i - 1]);
    }
    cout << maxmin << '\n';
  }

  return 0;
}
