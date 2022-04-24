#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef vector<long> vi;
typedef vector<pair<long, long> > vii;
typedef map<long, long> mii;

// Generates a list of factors based off a numbers prime factorisation.
vi getFactors(vii pFactors, int i) {
  if (i >= pFactors.size()) {
    return vi(1, 1);
  }
  vi factors;
  for (long f : getFactors(pFactors, i + 1)) {
    factors.push_back(f);
    long newFactor = f;
    for (int j = 1; j <= pFactors[i].second; j++) {
      newFactor *= pFactors[i].first;
      factors.push_back(newFactor);
    }
  }
  return factors;
}

// Returns a list of primes less than or equal to n.
vi getPrimes(int n) {
  vi primes;
  for (int i = 2; i <= n; i++) {
    bool prime = true;
    for (int j = 0; j < primes.size(); j++) {
      if (i % primes[j] == 0) {
        prime = false;
        break;
      }
    }
    if (prime) {
      primes.push_back(i);
    }
  }
  return primes;
}

// Checks if a number is a palindrome.
bool isPalindrome(long num) {
  string s = to_string(num);
  string rev = to_string(num);
  reverse(rev.begin(), rev.end());
  return s == rev;
}

int main() {
  int T;
  cin >> T;
  // Find primes up until sqrt(10^10) = 10^5
  vi primes = getPrimes(100000);

  for (int tc = 1; tc <= T; tc++) {
    long A;
    cin >> A;
    // Find prime factorisation.
    long res = A;
    int i = 0;
    mii m;
    while (res > 1) {
      while (i < primes.size() && res % primes[i] != 0) {
        i++;
      }
      if (i >= primes.size()) {
        // Edge case where we have a prime factor larger than sqrt(10^10).
        m[res]++;
        break;
      }
      m[primes[i]]++;
      res /= primes[i];
    }
    vii pFactors;
    // Store prime factors + freqs in vector of pairs for easy iteration.
    for (auto x : m) {
      pFactors.push_back(make_pair(x.first, x.second));
    }
    // Generate factors.
    vi factors = getFactors(pFactors, 0);
    // Count palindromes.
    long count = 0;
    for (long f : factors) {
      if (isPalindrome(f)) {
        count++;
      }
    }
    cout << "Case #" << tc << ": " << count << '\n';
  }
  return 0;
}