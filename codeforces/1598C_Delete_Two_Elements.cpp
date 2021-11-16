#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }

    ll twoK = 2 * sum / n;
    if (twoK * n != 2 * sum) {
      // We require the two integers to add up to 2*k. If this number is not an
      // integer, then no such pair of integers exists.
      cout << 0 << '\n';
    } else {
      // Idea: sort array in ascending order and have two pointers at the start
      // and end. Calculate the sum of the pair of integers at these locations.
      // If this sum exceeds 2*k, then we decrement the right pointer to reduce
      // the sum. Otherwise we increment the left pointer to increase the sum.
      // Stop when pointers meet.

      // Edge cases arise when there are duplicate numbers. We work around this
      // by filtering out duplicates, storing frequencies of numbers in a map,
      // and checking the map to detect when an edge case should be handled.

      // Count, sort and filter duplicates.
      map<ll, ll> freqs;
      for (int i = 0; i < n; i++) {
        freqs[a[i]]++;
      }
      sort(a.begin(), a.end());
      a.erase(unique(a.begin(), a.end()), a.end());
      // Apply two pointer method.
      ll l = 0, r = a.size() - 1, pairCount = 0, pairSum;
      bool left = a[l] + a[r] <= twoK;
      while (l < r) {
        pairSum = a[l] + a[r];
        if (pairSum == twoK) {
          pairCount += freqs[a[l]] * freqs[a[r]];
        } else if (left && pairSum > twoK || !left && pairSum < twoK) {
          left = !left;
        }
        if (left)
          l++;
        else
          r--;
      }
      // Handle edge case when k exists in the array.
      if (twoK % 2 == 0) {
        ll mid = twoK / 2;
        if (freqs[mid] > 0)
          pairCount += freqs[mid] * (freqs[mid] - 1) / 2;
      }
      cout << pairCount << '\n';
    }
  }

  return 0;
}
