/*
 * Sparse Table (Range Minimum/Maximum Query)
 *
 * Operations:
 *   build()  — O(n log n)
 *   query()  — O(1)  — range min/max (idempotent operations only)
 *
 * Usage:
 *   SparseTable st(arr);
 *   st.query(l, r);  // returns min in [l, r]
 */

#include <bits/stdc++.h>
using namespace std;

struct SparseTable {
    vector<vector<int>> table;
    vector<int> lg;
    int n;

    SparseTable(vector<int>& arr) {
        n = arr.size();
        int k = __lg(n) + 1;
        table.assign(k, vector<int>(n));
        lg.resize(n + 1);

        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        table[0] = arr;
        for (int j = 1; j < k; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                table[j][i] = min(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
    }

    int query(int l, int r) {
        int k = lg[r - l + 1];
        return min(table[k][l], table[k][r - (1 << k) + 1]);
    }
};
