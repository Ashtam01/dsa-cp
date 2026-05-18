/*
 * Disjoint Set Union (Union-Find)
 *
 * Operations:
 *   find()      — O(α(n)) amortized  — path compression (iterative)
 *   unite()     — O(α(n)) amortized  — union by size
 *   connected() — O(α(n)) amortized
 *   size()      — O(α(n)) amortized
 *
 * Usage:
 *   DSU dsu(n);
 *   dsu.unite(a, b);
 *   if (dsu.connected(a, b)) { ... }
 *   int sz = dsu.size(a);
 */

#include <vector>
#include <numeric>
#include <cassert>

using namespace std;

class DSU {
  private:
    vector<int> parents;
    vector<int> sizes;

  public:
    DSU(int n) : parents(n), sizes(n, 1) {
        assert(n > 0);
        iota(parents.begin(), parents.end(), 0);
    }

    /** @return the representative of x's component — O(α(n)) amortized */
    int find(int x) {
        assert(x >= 0 && x < (int)parents.size());
        int root = x;
        while (parents[root] != root) root = parents[root];
        while (parents[x] != root) {   // two-pass path compression
            int next = parents[x];
            parents[x] = root;
            x = next;
        }
        return root;
    }

    /** @return whether the merge changed connectivity */
    bool unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return false;

        if (sizes[rx] < sizes[ry]) swap(rx, ry);  // rx = larger root
        sizes[rx] += sizes[ry];
        parents[ry] = rx;
        return true;
    }

    /** @return whether x and y are in the same component */
    bool connected(int x, int y) { return find(x) == find(y); }

    /** @return number of nodes in x's component */
    int size(int x) { return sizes[find(x)]; }
};