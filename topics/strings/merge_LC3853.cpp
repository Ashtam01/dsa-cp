/*
 * Problem: Merge close characters
 * Platform: Leetcode
 * Tags: Strings
 * Time Complexity: O(N^2)
 * Space Complexity: O(26)
 * Date: 1/06/2026
 *
 * Approach:
 *   when any character is merged all the character's index ahead it get decreased by one
 *   it can be seen other way as to increase the index of elements before it by one
 * 
 * 
 */


class Solution {
public:
    string mergeCharacters(string s, int k) {
        vector<int> vec(26,-1);
        string ans;
        int n = s.size();
        for(int i=0 ; i < n ; i++){
            int id = s[i]-'a';
            if(vec[id] == -1){
                ans.push_back(s[i]);
                vec[id] = i;
            }
            else{
                if(vec[id] + k >= (i)){
                    for(int j=0;j<26;j++){
                        if(vec[j] < i && vec[j] != -1) vec[j]++;
                    }
                }else{
                    ans.push_back(s[i]);
                    vec[id] = i;
                }
            }
            
        }

        return ans;

        
    }
};