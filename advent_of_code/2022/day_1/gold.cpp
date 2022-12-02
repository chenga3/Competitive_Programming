#include <bits/stdc++.h>

using namespace std;

int main() {
  string line;
  int currSum = 0;
  vector<int> bestSums(3, -1);
  while (getline(cin, line)) {
    if (line.empty()) {
      int replace = -1;
      for (int i = 0; i < 3; i++) {
        if (currSum > bestSums[i]) {
          replace = i;
          break;
        }
      }
      if (replace > -1) {
        for (int i = 2; i > replace; i--) {
          bestSums[i] = bestSums[i - 1];
        }
        bestSums[replace] = currSum;
        printf("%d %d %d\n", bestSums[0], bestSums[1], bestSums[2]);
      }
      currSum = 0;
    } else {
      currSum += stoi(line);
    }
  }
  int totalSum = 0;
  for (int i = 0; i < 3; i++) {
    totalSum += bestSums[i];
  }
  cout << totalSum << '\n';
  return 0;
}