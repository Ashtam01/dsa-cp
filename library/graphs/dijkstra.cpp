/*
 * Dijkstra's Shortest Path (Adjacency List)
 *
 * Complexity: O((V + E) log V)
 *
 * Usage:
 *   vector<vector<pii>> adj(n);  // adj[u] = {v, weight}
 *   auto dist = dijkstra(adj, source);
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pli;

vector<long long> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    int n = adj.size();
    vector<long long> dist(n, LLONG_MAX);
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
