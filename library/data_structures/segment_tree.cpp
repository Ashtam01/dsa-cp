/*
 * Segment Tree (Point Update, Range Query)
 * 
 * Operations:
 *   build()  — O(n)
 *   update() — O(log n)  — point update
 *   query()  — O(log n)  — range query (sum/min/max)
 *
 * Usage:
 *   SegTree st(n);
 *   st.build(arr, 1, 0, n-1);
 *   st.update(1, 0, n-1, idx, val);
 *   st.query(1, 0, n-1, l, r);
 */

#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<long long> tree;

    SegTree(int _n) : n(_n), tree(4 * _n, 0) {}

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) +
               query(2 * node + 1, mid + 1, end, l, r);
    }
};
