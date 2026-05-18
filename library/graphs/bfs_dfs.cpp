/*
 * BFS & DFS Templates
 *
 * BFS — O(V + E) — shortest path in unweighted graphs
 * DFS — O(V + E) — traversal, cycle detection, components
 *
 * Usage:
 *   vector<vector<int>> adj(n);
 *   auto dist = bfs(adj, source);
 *   vector<bool> visited(n, false);
 *   dfs(adj, source, visited);
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>& adj, int src) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

void dfs(vector<vector<int>>& adj, int u, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(adj, v, visited);
        }
    }
}
