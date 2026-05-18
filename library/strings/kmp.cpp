/*
 * KMP (Knuth-Morris-Pratt) Pattern Matching
 *
 * Complexity: O(n + m) where n = text length, m = pattern length
 *
 * Usage:
 *   auto lps = build_lps(pattern);
 *   auto matches = kmp_search(text, pattern, lps);
 *   // matches = list of starting indices where pattern occurs
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> build_lps(string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

vector<int> kmp_search(string& text, string& pattern, vector<int>& lps) {
    int n = text.size(), m = pattern.size();
    vector<int> matches;
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
            if (j == m) {
                matches.push_back(i - j);
                j = lps[j - 1];
            }
        } else if (j) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    return matches;
}
