#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  getline(cin, s);

  bool team0 = s[0] == '0';
  int count = 1;
  for (int i = 1; i < s.size(); i++) {
    if (team0 && s[i] == '0' || !team0 && s[i] == '1') {
      count++;
      if (count >= 7) {
        cout << "YES\n";
        break;
      }
    } else {
      team0 = !team0;
      count = 1;
    }
  }
  if (count < 7)
    cout << "NO\n";
}
