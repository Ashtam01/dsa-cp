/*
 * Topological Sort (Kahn's BFS-based)
 *
 * Complexity: O(V + E)
 * Returns: topological order (empty if cycle exists)
 *
 * Usage:
 *   vector<vector<int>> adj(n);
 *   vector<int> indegree(n, 0);
 *   auto order = topo_sort(adj, indegree);
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> topo_sort(vector<vector<int>>& adj, vector<int>& indegree) {
    int n = adj.size();
    queue<int> q;
    vector<int> order;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    if ((int)order.size() != n) return {};  // cycle detected
    return order;
}
