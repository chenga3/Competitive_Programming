#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;

void dfs(int i, vb& visited, vvi& graph) {
  visited[i] = true;
  for (int n : graph[i]) {
    if (!visited[n]) {
      dfs(n, visited, graph);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  int u, v;
  vvi graph(n, vi(0));
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u - 1].emplace_back(v - 1);
    graph[v - 1].emplace_back(u - 1);
  }
  vb visited(n);
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i, visited, graph);
      count++;
    }
  }
  cout << count - 1 << '\n';
}