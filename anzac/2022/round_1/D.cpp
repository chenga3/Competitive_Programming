#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  vector<vector<int> > land(r, vector<int>(c, 0));

  int count0 = 0, count1 = 0, count2 = 0;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> land[i][j];
      if (land[i][j] == 0) {
        count0++;
      } else if (land[i][j] == 2) {
        count2++;
      } else {
        count1++;
      }
    }
  }

  if (count0 > 2) {
    cout << 0;
  } else if (count0 == 1) {
    if (count1 == 0) {
      cout << 2;
    } else {
      if (r == 1 || c == 1) {
            }
    }
  } else {
    if (count2 % 2 == 0) {
      cout << 0;
    } else {
      cout << pow(2, count2 / 2);
    }
  }

  return 0;
}