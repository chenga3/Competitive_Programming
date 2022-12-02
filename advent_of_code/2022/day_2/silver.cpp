#include <bits/stdc++.h>

using namespace std;

char getOutcome(char theirShape, char myShape) {
  if (theirShape == 'A' && myShape == 'Y' ||
      theirShape == 'B' && myShape == 'Z' ||
      theirShape == 'C' && myShape == 'X') {
    return 'W';
  } else if (theirShape == 'A' && myShape == 'X' ||
             theirShape == 'B' && myShape == 'Y' ||
             theirShape == 'C' && myShape == 'Z') {
    return 'D';
  } else {
    return 'L';
  }
}

int main() {
  map<char, int> shapeScore = {{'X', 1}, {'Y', 2}, {'Z', 3}};
  map<char, int> outcomeScore = {{'L', 0}, {'D', 3}, {'W', 6}};
  string line;
  char myShape, theirShape, outcome;
  int totalScore = 0;
  while (getline(cin, line)) {
    theirShape = line[0];
    myShape = line[2];
    outcome = getOutcome(theirShape, myShape);
    totalScore += shapeScore[myShape] + outcomeScore[outcome];
  }
  cout << totalScore << '\n';
  return 0;
}