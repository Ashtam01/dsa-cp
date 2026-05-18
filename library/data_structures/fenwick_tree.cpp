/*
 * Fenwick Tree (Binary Indexed Tree)
 *
 * Operations:
 *   update() — O(log n)  — point add
 *   query()  — O(log n)  — prefix sum [1..idx]
 *   range()  — O(log n)  — range sum [l..r]
 *
 * Note: 1-indexed
 *
 * Usage:
 *   BIT bit(n);
 *   bit.update(idx, delta);
 *   bit.query(idx);          // prefix sum [1..idx]
 *   bit.range(l, r);         // sum [l..r]
 */

#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> tree;

    BIT(int _n) : n(_n), tree(_n + 1, 0) {}

    void update(int idx, long long delta) {
        for (; idx <= n; idx += idx & (-idx))
            tree[idx] += delta;
    }

    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & (-idx))
            sum += tree[idx];
        return sum;
    }

    long long range(int l, int r) {
        return query(r) - query(l - 1);
    }
};
