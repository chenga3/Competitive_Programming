#include <bits/stdc++.h>

#define MAX_M 200000
#define MAX_LOG 18

using namespace std;

typedef long long ll;
typedef int64_t i64;

int n, m, q;
int xs, ys, xf, yf, k;
int a[MAX_M + 1];
int lookup[MAX_M + 1][MAX_LOG + 1];

int log_int(int a) { return sizeof(a) * CHAR_BIT - 1 - __builtin_clz(a); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  // Fill sparse table.
  for (int i = 1; i <= m; i++) {
    lookup[i][0] = a[i];
  }
  for (int j = 1; j <= log_int(m); j++) {
    for (int i = 1; i <= m - (1 << j) + 1; i++) {
      lookup[i][j] = max(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
    }
  }
  cin >> q;
  for (int _ = 0; _ < q; _++) {
    cin >> xs >> ys >> xf >> yf >> k;
    if (yf == ys) {
      if (xs >= a[ys] && xf >= a[ys] && (xf - xs) % k == 0 || xs == xf) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
      continue;
    }
    if (abs(xf - xs) % k != 0 || abs(yf - ys) % k != 0) {
      cout << "NO\n";
      continue;
    }
    if (yf < ys) {
      swap(yf, ys);
      swap(xf, xs);
    }
    if (yf - ys == 1) {
      cout << "YES\n";
      continue;
    }
    int j = log_int(yf - ys - 1);
    int maxA = max(lookup[ys + 1][j], lookup[yf - (1 << j)][j]);
    ll xp = maxA >= xs ? (ll)(((maxA - xs) / k) + 1) * k + xs : xs;
    if (xp > n) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}