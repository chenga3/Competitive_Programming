#include <bits/stdc++.h>

using namespace std;

using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;

void print(vvc v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[0].size(); j++) {
      cout << v[i][j];
    }
    cout << '\n';
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vvc picture(n, vc(m));
  string row;
  for (int i = 0; i < n; i++) {
    cin >> row;
    for (int j = 0; j < m; j++) {
      picture[i][j] = row[j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (picture[i][j] == 'X') {
        if (i > 0 && picture[i - 1][j] == '.') {
          picture[i - 1][j] = 'R';
        }
        if (i < n - 1 && picture[i + 1][j] == '.') {
          picture[i + 1][j] = 'R';
        }
        if (j > 0 && picture[i][j - 1] == '.') {
          picture[i][j - 1] = 'R';
        }
        if (j < m - 1 && picture[i][j + 1] == '.') {
          picture[i][j + 1] = 'R';
        }
        if (i > 0 && j > 0 && picture[i - 1][j - 1] == '.') {
          picture[i - 1][j - 1] = 'R';
        }
        if (i < n - 1 && j > 0 && picture[i + 1][j - 1] == '.') {
          picture[i + 1][j - 1] = 'R';
        }
        if (i > 0 && j < m - 1 && picture[i - 1][j + 1] == '.') {
          picture[i - 1][j + 1] = 'R';
        }
        if (i < n - 1 && j < m - 1 && picture[i + 1][j + 1] == '.') {
          picture[i + 1][j + 1] = 'R';
        }
      }
    }
  }
  print(picture);
}