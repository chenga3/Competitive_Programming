#include <iostream>
#include <vector>

using namespace std;

int main() {
  int p, q;

  cin >> p >> q;

  vector<int> indexA;
  char card;

  for (int i = 0; i < 4; i++) {
    cin >> card;
    if (card == 'A') {
      indexA.push_back(i);
    }
  }

  vector<int> B;
  bool possible = true;
  if (indexA[0] > 0) {
    if (p == indexA[0] + 1) {
      for (int i = 0; i < indexA[0]; i++) {
        B.push_back(i + 1);
      }
    } else {
      possible = false;
    }
  }
  if (B.size() < 2 && possible && indexA[1] > indexA[0] + 1) {
    if (q - p == indexA[1] - indexA[0]) {
      for (int i = 0; i < q - p - 1; i++) {
        B.push_back(p + i + 1);
      }
    } else {
      possible = false;
    }
  }
  if (B.size() < 2 && possible && indexA[1] < 3) {
    if (q == indexA[1] + 6) {
      for (int i = 0; i < 3 - indexA[1]; i++) {
        B.push_back(q + i + 1);
      }
    } else {
      possible = false;
    }
  }
  if (!possible) {
    cout << -1 << '\n';
  } else {
    cout << B[0] << ' ' << B[1] << '\n';
  }

  return 0;
}