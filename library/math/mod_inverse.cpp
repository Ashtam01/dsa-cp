/*
 * Modular Arithmetic Utilities
 *
 * - power(base, exp, mod)    — O(log exp) — fast exponentiation
 * - mod_inverse(a, mod)      — O(log mod) — using Fermat's little theorem (mod must be prime)
 * - nCr with precomputed factorials
 *
 * Usage:
 *   long long inv = mod_inverse(a, MOD);
 *   Combo combo(n, MOD);
 *   long long ans = combo.nCr(n, r);
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

long long mod_inverse(long long a, long long mod) {
    return power(a, mod - 2, mod);  // Fermat's: a^(p-2) mod p
}

struct Combo {
    vector<long long> fact, inv_fact;
    int mod;

    Combo(int n, int _mod) : mod(_mod) {
        fact.resize(n + 1);
        inv_fact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % mod;
        inv_fact[n] = power(fact[n], mod - 2, mod);
        for (int i = n - 1; i >= 0; i--)
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] % mod * inv_fact[r] % mod * inv_fact[n - r] % mod;
    }
};
