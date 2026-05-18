/*
 * Sieve of Eratosthenes
 *
 * Complexity: O(n log log n)
 *
 * Usage:
 *   auto primes = sieve(1e6);
 *   // primes[i] == true means i is prime
 */

#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;

    return is_prime;
}

// Linear sieve — also computes smallest prime factor
vector<int> linear_sieve(int n) {
    vector<int> spf(n + 1, 0);
    vector<int> primes;

    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || (long long)i * p > n) break;
            spf[i * p] = p;
        }
    }
    return spf;  // spf[i] = smallest prime factor of i
}
