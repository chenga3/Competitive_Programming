#include <iostream>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int num;
  map<int, int> marbles;
  for (int i = 0; i < n; i++) {
    cin >> num;
    marbles[num]++;
  }

  for (int i = 0; i < n; i++) {
    cin >> num;
    marbles[num]--;
  }
  map<int, int>::iterator it;
  for (it = marbles.begin(); it != marbles.end(); it++) {
    if (it->second != 0) {
      cout << "error";
      return 0;
    }
  }
  cout << "marvelous";

  return 0;
}