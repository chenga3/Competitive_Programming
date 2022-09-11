#include <bits/stdc++.h>

using namespace std;

const vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

int main() {
  string s;
  cin >> s;
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    for (int j = i; j < s.length(); j++) {
      bool next = false;
      for (int k = i; k <= j; k++) {
        for (char v : vowels) {
          if (s[k] == v) {
            count++;
            next = true;
            break;
          }
        }
        if (next) {
          break;
        }
      }
    }
  }
  cout << count << '\n';
}