/*
 * Z-Function (Z-Array)
 *
 * z[i] = length of longest substring starting at i
 *        that is also a prefix of the string
 *
 * Complexity: O(n)
 *
 * Usage:
 *   auto z = z_function(s);
 *   // Pattern matching: z_function(pattern + "$" + text)
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
