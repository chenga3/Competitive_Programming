#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int dfs(int i, int j, vvb &visited, vvi &walls) {
  visited[i][j] = true;
  int count = 1;
  if (!(walls[i][j] & (1 << 3))) {
    if (!visited[i - 1][j]) {
      count += dfs(i - 1, j, visited, walls);
    }
  }
  if (!(walls[i][j] & (1 << 2))) {
    if (!visited[i][j + 1]) {
      count += dfs(i, j + 1, visited, walls);
    }
  }
  if (!(walls[i][j] & (1 << 1))) {
    if (!visited[i + 1][j]) {
      count += dfs(i + 1, j, visited, walls);
    }
  }
  if (!(walls[i][j] & (1 << 0))) {
    if (!visited[i][j - 1]) {
      count += dfs(i, j - 1, visited, walls);
    }
  }
  return count;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  vvi walls(N, vi(M, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> walls[i][j];
    }
  }
  vvb visited(N, vb(M, false));
  vi sizes;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!visited[i][j])
        sizes.push_back(dfs(i, j, visited, walls));
    }
  }
  sort(sizes.rbegin(), sizes.rend());
  for (int i = 0; i < sizes.size(); i++) {
    cout << sizes[i] << ' ';
  }
}
