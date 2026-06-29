/*
 * Problem: Number of Strings That Appear as Substrings in Word
 * Platform: Leetcode
 * Tags: Strings
 * Time Complexity: O(N*M)
 * Space Complexity: O(argmax Patterns[i])
 * Date: 29/06/2026
 *
 * Approach:
 *   KMP algorithm applied, the main concept is that i must never backtrack.
 *   Build Pi_s vector then apply the search for each pattern text.
 * 
 */



class Solution {
public:
    vector<int> pi_s(string& w){
        int n = w.size();
        vector<int> pi(n);
        for(int i=1,j=0;i<n;i++){
            while(j>0 && w[i]!=w[j]) j = pi[j-1];
            if(w[i] == w[j]) j++;
            pi[i] = j;
        }
        return pi;

    }

    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        int n = word.size();
        for(string& s : patterns){
            vector<int> pi = pi_s(s);
            int m = s.size();
            for(int i=0,j=0;i<n;i++){
                while(j>0 && word[i] != s[j]) j = pi[j-1];
                if(word[i] == s[j]) j++;
                if(j == m){
                    ans++;
                    break;
                }
            }

        }
        return ans;
        
        
    }
};