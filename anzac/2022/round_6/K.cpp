#include <bits/stdc++.h>

using namespace std;

using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int n, m;
  cin >> n >> m;

  vvi adjList(n + 1);
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  // cout << adjList[1][0] << '\n';
  // for (vi vec : adjList) {
  //   for (int v : vec) {
  //     cout << v << ' ';
  //   }
  //   cout << '\n';
  // }

  vb visited(n + 1);
  vi dist(n + 1);
  queue<int> bfs;
  bfs.push(1);
  dist[1] = 0;
  while (!bfs.empty()) {
    u = bfs.front();
    visited[u] = true;
    bfs.pop();
    for (int v : adjList[u]) {
      if (!visited[v]) {
        bfs.push(v);
        visited[v] = true;
        dist[v] = dist[u] + 1;
      }
    }
  }
  cout << dist[n] - 1 << '\n';
  return 0;
}