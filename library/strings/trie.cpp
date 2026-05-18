/*
 * Trie (Prefix Tree)
 *
 * Operations:
 *   insert() — O(|word|)
 *   search() — O(|word|)
 *   startsWith() — O(|prefix|)
 *
 * Usage:
 *   Trie trie;
 *   trie.insert("hello");
 *   trie.search("hello");       // true
 *   trie.startsWith("hel");     // true
 */

#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        int children[26];
        bool is_end;
        Node() : is_end(false) { memset(children, -1, sizeof(children)); }
    };

    vector<Node> nodes;

    Trie() { nodes.emplace_back(); }

    void insert(const string& word) {
        int cur = 0;
        for (char c : word) {
            int idx = c - 'a';
            if (nodes[cur].children[idx] == -1) {
                nodes[cur].children[idx] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].children[idx];
        }
        nodes[cur].is_end = true;
    }

    bool search(const string& word) {
        int cur = 0;
        for (char c : word) {
            int idx = c - 'a';
            if (nodes[cur].children[idx] == -1) return false;
            cur = nodes[cur].children[idx];
        }
        return nodes[cur].is_end;
    }

    bool startsWith(const string& prefix) {
        int cur = 0;
        for (char c : prefix) {
            int idx = c - 'a';
            if (nodes[cur].children[idx] == -1) return false;
            cur = nodes[cur].children[idx];
        }
        return true;
    }
};
