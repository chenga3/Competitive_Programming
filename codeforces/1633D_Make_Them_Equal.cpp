#include <limits.h>

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int solveCase(int n, int k, vi &b, vi &c, vi &d) {
  // Idea: We have a knapsack problem where weights are the minimum number of
  // turns to reach b_i. The maximum capacity is the minimum of k or 12*n
  // (highest number of turns to reach a number <= 1000 is 12). This constraint
  // on capacity helps the algorithm run in time.
  int cap = min(12 * n, k);
  vvi knap(n, vi(cap + 1, 0));
  for (int j = 0; j <= cap; j++) {
    knap[0][j] = (j >= d[b[0]] ? c[0] : 0);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= cap; j++) {
      if (j >= d[b[i]]) {
        knap[i][j] = max(knap[i - 1][j], knap[i - 1][j - d[b[i]]] + c[i]);
      } else {
        knap[i][j] = knap[i - 1][j];
      }
    }
  }
  return knap[n - 1][cap];
}

int main() {
  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    // Read in inputs
    int n, k;
    cin >> n >> k;
    vi b(n, 0), c(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    // Solve DP array for smallest turns to reach each integer up to 1000.
    vi d(1001, INT_MAX);
    d[1] = 0;
    for (int i = 2; i <= 1000; i++) {
      for (int j = (i + 1) / 2; j < i; j++) {
        if (j / (j / (i - j)) == i - j) {
          d[i] = min(d[i], d[j] + 1);
        }
      }
    }
    cout << solveCase(n, k, b, c, d) << '\n';
  }

  return 0;
}