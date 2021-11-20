#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const int MOD = 998244353;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vll a(n, 0), b(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  // For each number in the array, calculate how many intervals include it.
  for (int i = 0; i < n; i++) {
    // At index i, (i+1) possible starts of interval, (n-i) possible ends of
    // interval.
    a[i] *= (n - i) * (i + 1);
  }

  // Pair largest with smallest, 2nd largest with 2nd smallest, etc.
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());

  ll sum = 0;

  for (int i = 0; i < n; i++) {
    // a[i] is up to 10^16, b[i] is up to 10^6. So take mod to prevent overflow.
    sum += (a[i] % MOD) * b[i];
    sum %= MOD;
  }

  cout << sum << '\n';

  return 0;
}
