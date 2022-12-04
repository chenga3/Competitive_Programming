#include <bits/stdc++.h>

using namespace std;

int getNum(char c) { return c >= 'a' ? c - 'a' + 1 : c - 'A' + 27; }

int main() {
  string line;
  int total = 0;
  while (getline(cin, line)) {
    map<char, int> freqs;
    for (int i = 0; i < line.length() / 2; i++) {
      freqs[line[i]] = 1;
    }
    for (int i = line.length() / 2; i < line.length(); i++) {
      if (freqs[line[i]] == 1) {
        freqs[line[i]] = 0;
        total += getNum(line[i]);
      }
    }
  }
  cout << total << '\n';
  return 0;
}