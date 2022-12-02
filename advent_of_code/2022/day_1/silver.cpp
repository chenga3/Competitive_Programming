#include <bits/stdc++.h>

using namespace std;

int main() {
  string line;
  int currSum = 0;
  int maxSum = -1;
  while (getline(cin, line)) {
    if (line.empty()) {
      maxSum = max(maxSum, currSum);
      currSum = 0;
    } else {
      currSum += stoi(line);
    }
  }
  cout << maxSum << '\n';
  return 0;
}