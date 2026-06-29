/*
 * KMP (Knuth-Morris-Pratt) Pattern Matching
 *
 * Complexity: O(n + m) where n = text length, m = pattern length
 *
 * Usage:
 * string text = "ABABDABACDABABCABAB";
 * string pattern = "ABABCABAB";
 * vector<int> matches = kmp_search(text, pattern);
 * // matches = list of starting indices where pattern occurs
 *
 * Note: The internal pi() function computes the Longest Prefix Suffix (LPS) array.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> pi(const string &s) {
	int n = (int)s.size();
	vector<int> pi_s(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[j] != s[i]) { j = pi_s[j - 1]; }
		if (s[i] == s[j]) { j++; }
		pi_s[i] = j;
	}
	return pi_s;
}

vector<int> kmp_search(const string &text, const string &pattern) {
    vector<int> matches;
    if (pattern.empty()) return matches;


    vector<int> pi_s = pi(pattern);
    
    int n = (int)text.size();
    int m = (int)pattern.size();

    for (int i = 0, j = 0; i < n; i++) {
        
        
        while (j > 0 && text[i] != pattern[j]) {
            j = pi_s[j - 1];
        }
        
        if (text[i] == pattern[j]) {
            j++;
        }
        
      
        if (j == m) {

            matches.push_back(i - m + 1);
            j = pi_s[j - 1]; 
        }
    }
    
    return matches;
}