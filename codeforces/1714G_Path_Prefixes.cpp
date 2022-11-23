#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, p, a, b;
vector<vector<vector<int>>> adj;

vector<int> dfs(int i) {
  vector<int> visited(n + 1);
  vector<int> r(n + 1);
  stack<vector<int>> s({{i, 0, 0}});
  stack<ll> aSum;
  vector<ll> bSum;  // Stores cumulative sums.
  while (!s.empty()) {
    vector<int> top = s.top();
    int u = top[0], a = top[1], b = top[2];
    // printf("%d %d %d\n", u, a, b);
    if (visited[u] == 1) {
      visited[u] = 2;
      r[u] =
          upper_bound(bSum.begin(), bSum.end(), aSum.top()) - bSum.begin() - 1;
      s.pop();
      aSum.pop();
      bSum.pop_back();
    } else if (!visited[u]) {
      visited[u] = 1;
      if (aSum.empty()) {
        aSum.push(a);
      } else {
        aSum.push(aSum.top() + a);
      }
      if (bSum.size() == 0) {
        bSum.push_back(b);
      } else {
        bSum.push_back(bSum.back() + b);
      }
      for (vector<int> e : adj[u]) {
        if (!visited[e[0]]) {
          s.push(e);
        }
      }
    } else {
      s.pop();
    }
  }
  return r;
}

int main() {
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    cin >> n;
    adj.assign(n + 1, vector<vector<int>>());
    for (int i = 2; i <= n; i++) {
      cin >> p >> a >> b;
      adj[p].push_back(vector<int>{i, a, b});
    }
    vector<int> r = dfs(1);
    for (int i = 2; i <= n; i++) {
      cout << r[i] << ' ';
    }
    cout << '\n';
  }

  return 0;
}