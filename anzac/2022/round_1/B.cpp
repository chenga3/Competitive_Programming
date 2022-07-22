#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string time;

  cin >> time;
  vector<vector<char> > display(4, vector<char>(4, '.'));

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int digit = time[j] - '0';
      int bit = ((digit >> (3 - i)) & 1);
      display[i][j] = bit ? '*' : '.';
    }
  }

  for (int i = 0; i < 4; i++) {
    cout << display[i][0] << ' ' << display[i][1] << "  " << display[i][2]
         << ' ' << display[i][3] << '\n';
  }

  return 0;
}