/*
 * Problem: EvenOddPhoto
 * Platform: USACO
 * Tags: Greedy/Math
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * Date: 25/05/2026
 *
 * Approach:
 *   - Even + Even = Even
 *   - Odd + Odd = Even
 *   So, if num of odd > num of even 
 *   then odds can be merged 
 *   when (odd-even)%3 == 1 then merge all
 * 
 */

#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    int odd = 0, even = 0;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        if(vec[i]&1) odd++;
        else even++;
    }
    if(even > odd){
        cout<<(2*odd)+1<<endl;
        return;
    }
    int ans = 0;
    ans += 2*even;
    int rem = (odd-even);
    ans += (rem/3)*2;
    rem = rem%3;
    if(rem == 1){
        ans--;

    }
    if(rem == 2){
        ans++;
    }
    cout<<ans<<endl;
    


}

int main() {
	int t = 1;
    while(t--){
        solve();
    }
}
