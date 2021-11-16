#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vvi grid(n, vi(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  int c;
  for (int i = 0; i < k; i++) {
    cin >> c;
    int x = 0, y = c - 1;
    while (x < n) {
      if (grid[x][y] == 1) {
        grid[x][y] = 2;
        y++;
      } else if (grid[x][y] == 2) {
        x++;
      } else if (grid[x][y] == 3) {
        grid[x][y] = 2;
        y--;
      }
    }
    cout << y + 1 << ' ';
  }
  cout << '\n';
  return 0;
}
