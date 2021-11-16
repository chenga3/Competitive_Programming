#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool steadyState(map<int, int> freqs) {
  for (auto const &pair : freqs) {
    if (pair.first != pair.second) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, n, q;
  cin >> t;

  for (int tc = 0; tc < t; tc++) {
    cin >> n;
    vi a(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cin >> q;
    vi x(q, 0), k(q, 0);
    int maxK = 0;
    for (int i = 0; i < q; i++) {
      cin >> x[i] >> k[i];
      maxK = max(k[i], maxK);
    }

    // Simulate and store iterations up to maxK or steady state.
    vvi arrs;
    vi prev, curr(n, 0);
    arrs.push_back(a);
    map<int, int> prevFreqs, currFreqs;
    for (int i = 0; i < n; i++) {
      if (currFreqs.count(a[i]) == 0) {
        currFreqs[a[i]] = 1;
      } else {
        currFreqs[a[i]]++;
      }
    }
    if (!steadyState(currFreqs)) {
      while (arrs.size() <= maxK) {
        prev = arrs.back();
        prevFreqs = currFreqs;
        currFreqs.clear();
        for (int i = 0; i < n; i++) {
          curr[i] = prevFreqs[prev[i]];
          if (currFreqs.count(curr[i]) == 0) {
            currFreqs[curr[i]] = 1;
          } else {
            currFreqs[curr[i]]++;
          }
        }
        arrs.push_back(curr);
        if (steadyState(currFreqs))
          break;
      }
    }

    // Process all queries.
    for (int i = 0; i < q; i++) {
      cout << arrs[min(k[i], (int)arrs.size() - 1)][x[i] - 1] << '\n';
    }
  }

  return 0;
}
