#include <bits/stdc++.h>

using namespace std;

char getMyShape(char theirShape, char outcome) {
  if (theirShape == 'A' && outcome == 'Y' ||
      theirShape == 'B' && outcome == 'X' ||
      theirShape == 'C' && outcome == 'Z') {
    return 'A';
  } else if (theirShape == 'A' && outcome == 'Z' ||
             theirShape == 'B' && outcome == 'Y' ||
             theirShape == 'C' && outcome == 'X') {
    return 'B';
  } else {
    return 'C';
  }
}

int main() {
  map<char, int> shapeScore = {{'A', 1}, {'B', 2}, {'C', 3}};
  map<char, int> outcomeScore = {{'X', 0}, {'Y', 3}, {'Z', 6}};
  string line;
  char myShape, theirShape, outcome;
  int totalScore = 0;
  while (getline(cin, line)) {
    theirShape = line[0];
    outcome = line[2];
    myShape = getMyShape(theirShape, outcome);
    totalScore += shapeScore[myShape] + outcomeScore[outcome];
  }
  cout << totalScore << '\n';
  return 0;
}