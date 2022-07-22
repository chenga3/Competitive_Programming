#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, s;
  cin >> n >> s;
  int left = s;
  string str;
  int ounces, refills = 0;
  for (int i = 0; i < n; i++) {
    cin >> str;
    if (str[str.length() - 1] == 'L') {
      ounces = stoi(str.substr(0, str.length() - 1)) + 1;
    } else {
      ounces = stoi(str);
    }
    if (ounces > left) {
      refills++;
      left = s - ounces;
    } else {
      left -= ounces;
    }
  }

  cout << refills << '\n';

  return 0;
}