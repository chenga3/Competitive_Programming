#include <math.h>

#include <iostream>

using namespace std;

int main() {
  cout.precision(17);
  int T;
  cin >> T;
  double PI = atan(1) * 4;
  for (int tc = 1; tc <= T; tc++) {
    int R, A, B;
    cin >> R >> A >> B;
    long radius = R;
    double area = PI * radius * radius;
    double sum = 0;
    bool left = false;
    do {
      sum += area;
      if (left) {
        radius /= B;
      } else {
        radius *= A;
      }
      left = !left;
      area = PI * radius * radius;
    } while (area > 0);
    cout << "Case #" << tc << ": " << sum << '\n';
  }
}