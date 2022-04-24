#include <iostream>
#include <vector>

using namespace std;

typedef vector<long> vl;
typedef vector<long> vi;
typedef vector<vector<long>> vvi;

// Returns min number of rotations to get from n1 to n2 or vice versa.
long minDist(long n1, long n2, long D) {
  return min(abs(n2 - n1), D - abs(n2 - n1));
}

int main() {
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    // Read in inputs.
    long N, D;
    cin >> N >> D;
    vl V(N, 0);
    for (int i = 0; i < N; i++) {
      cin >> V[i];
    }
    // Erase consecutive duplicates. It is always sub-optimal to rotate
    // consecutive duplicates separately, so we may as well ignore the duplicate
    // copies.
    long prev = -1;
    long curr = -1;
    vl V2;
    for (int i = 0; i < N; i++) {
      curr = V[i];
      if (curr != prev) {
        V2.push_back(curr);
      }
      prev = curr;
    }
    // Dynamic Programming !!!.
    N = V2.size();
    vvi minL(N, vi(N, -1));  // Min operations to get to num on LHS of subarray.
    vvi minR(N, vi(N, -1));  // Min operations to get to num on RHS of subarray.
    // Base case: subarrays of size 1.
    for (int i = 0; i < N; i++) {
      minL[i][i] = 0;
      minR[i][i] = 0;
    }
    for (int size = 2; size <= N; size++) {
      for (int i = 0; i < N - (size - 1); i++) {
        // Extend the subarray of size one less skewed to the right. Take min of
        // two cases: the subarray has all dials matching number on LHS, or RHS.
        minL[i][i + size - 1] = min(
            minL[i + 1][i + size - 1] + minDist(V2[i], V2[i + 1], D),
            minR[i + 1][i + size - 1] + minDist(V2[i], V2[i + size - 1], D));
        // Extend the subarray of size one less skewed to the left. Take min of
        // two cases: the subarray has all dials matching number on LHS, or RHS.
        minR[i][i + size - 1] =
            min(minL[i][i + size - 2] + minDist(V2[i], V2[i + size - 1], D),
                minR[i][i + size - 2] +
                    minDist(V2[i + size - 2], V2[i + size - 1], D));
      }
    }
    // Make final rotations to ensure all dials are set to 0. Take min of two
    // cases: dials were matching number of LHS of array, or RHS.
    cout << "Case #" << tc << ": "
         << min(minL[0][N - 1] + minDist(V2[0], 0, D),
                minR[0][N - 1] + minDist(V2[N - 1], 0, D))
         << "\n";
  }
}