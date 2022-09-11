#include <bits/stdc++.h>

using namespace std;

int main() {
  string token;
  int a;
  int c;
  string sign1, sign2;
  cin >> token;  // x
  cin >> token;  // squared
  cin >> token;  // -
  sign1 = token;
  cin >> token;  // ax
  a = stoi(token.substr(0, token.length() - 1));
  cin >> token;  // +
  sign2 = token;
  cin >> token;  // c
  c = stoi(token);
  cout << a << ' ' << c << '\n';

  // Find factors.
  int f1, f2;
  for (int i = 1; i * i <= c; i++) {
    if (c % i == 0) {
      f1 = i;
      f2 = c / i;
    }
  }

  return 0;
}