#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int main() {
  int h, w, d;
  cin >> h >> w >> d;
  vi lengths{h, w, d};
  sort(lengths.begin(), lengths.end());
  if (lengths[0] + lengths[1] < lengths[2]) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    cout << "0 0\n";
    cout << h << ' ' << 0 << '\n';
    double cosA = ((double)d * d + (double)h * h - (double)w * w) / (2 * d * h);
    double sinA = sqrt(1 - cosA * cosA);
    cout << setprecision(12) << d * cosA << ' ' << d * sinA << '\n';
  }
}