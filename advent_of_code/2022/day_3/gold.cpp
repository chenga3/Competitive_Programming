#include <bits/stdc++.h>

using namespace std;

int getNum(char c) { return c >= 'a' ? c - 'a' + 1 : c - 'A' + 27; }

int main() {
  string line1, line2, line3;
  int total = 0;
  while (getline(cin, line1)) {
    map<char, bool> seen;
    map<char, int> freq;
    for (char c : line1) {
      if (!seen[c]) {
        seen[c] = true;
        freq[c]++;
      }
    }
    seen.clear();
    getline(cin, line2);
    for (char c : line2) {
      if (!seen[c]) {
        seen[c] = true;
        freq[c]++;
      }
    }
    seen.clear();
    getline(cin, line3);
    for (char c : line3) {
      if (!seen[c]) {
        seen[c] = true;
        freq[c]++;
      }
    }
    for (auto [key, val] : freq) {
      if (val == 3) {
        total += getNum(key);
        break;
      }
    }
  }
  cout << total << '\n';
  return 0;
}