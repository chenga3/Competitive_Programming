#include <bits/stdc++.h>

#define MAX_N 50
#define MAX_M 50

using namespace std;

int t, n, m;
char grid[MAX_N][MAX_M];

vector<int> getNeighbours(int i) {
  vector<int> dr = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
  vector<int> dc = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
  vector<int> nb;
  for (int j = 0; j < dr.size(); j++) {
    int r = (i / m) + dr[j];
    int c = (i % m) + dc[j];
    if (r >= 0 && r < n && c >= 0 && c < m) {
      nb.push_back(m * r + c);
    }
  }
  return nb;
}

char getNode(int i) { return grid[i / m][i % m]; }

vector<int> dfs(int i, vector<bool> &visited) {
  vector<int> nodes;
  if (getNode(i) == '.') {
    return nodes;
  }
  stack<int> s;
  s.push(i);
  while (!s.empty()) {
    int u = s.top();
    s.pop();
    if (visited[u]) {
      continue;
    }
    visited[u] = true;
    if (getNode(u) == '.') {
      continue;
    } else {
      nodes.push_back(u);
    }
    for (int nb : getNeighbours(u)) {
      if (!visited[nb]) {
        s.push(nb);
      }
    }
  }
  return nodes;
}

bool isValid(vector<int> &L) {
  vector<int> cols, rows;
  for (int i : L) {
    cols.push_back(i % m);
    rows.push_back(i / m);
  }
  sort(cols.begin(), cols.end());
  sort(rows.begin(), rows.end());
  return cols[2] - cols[0] == 1 && rows[2] - rows[0] == 1;
}

int main() {
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }
    vector<bool> visited(n * m);
    bool yes = true;
    for (int i = 0; i < n * m; i++) {
      if (!visited[i]) {
        vector<int> L = dfs(i, visited);
        if (L.size() > 0 && (L.size() != 3 || !isValid(L))) {
          cout << "NO\n";
          yes = false;
          break;
        }
      }
    }
    if (yes) {
      cout << "YES\n";
    }
  }
  return 0;
}