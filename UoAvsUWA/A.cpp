#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int gear = 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'U' && gear < 5) {
      gear++;
    } else if (s[i] == 'D' && gear > 1) {
      gear--;
    }
  }
  cout << gear << '\n';
}