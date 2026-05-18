/*
 * Lowest Common Ancestor (Binary Lifting)
 *
 * Preprocessing: O(n log n)
 * Query:         O(log n)
 *
 * Usage:
 *   LCA lca(adj, root);
 *   int ancestor = lca.query(u, v);
 */

#include <bits/stdc++.h>
using namespace std;

struct LCA {
    int n, LOG;
    vector<vector<int>>& adj;
    vector<vector<int>> up;
    vector<int> depth;

    LCA(vector<vector<int>>& _adj, int root) : adj(_adj) {
        n = adj.size();
        LOG = __lg(n) + 1;
        up.assign(LOG, vector<int>(n, -1));
        depth.assign(n, 0);
        dfs(root, -1, 0);

        for (int k = 1; k < LOG; k++)
            for (int v = 0; v < n; v++)
                if (up[k - 1][v] != -1)
                    up[k][v] = up[k - 1][up[k - 1][v]];
    }

    void dfs(int u, int p, int d) {
        up[0][u] = p;
        depth[u] = d;
        for (int v : adj[u])
            if (v != p) dfs(v, u, d + 1);
    }

    int query(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++)
            if ((diff >> k) & 1)
                u = up[k][u];

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--)
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }

        return up[0][u];
    }
};
