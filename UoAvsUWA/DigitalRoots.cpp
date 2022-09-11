#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s = to_string(n);
  while (s.length() > 1) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
      sum += s[i] - '0';
    }
    s = to_string(sum);
  }
  cout << s << '\n';
}