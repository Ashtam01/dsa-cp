/* Ashtam Pati Tiwari*/
#include "bits/stdc++.h"
#include <iomanip>


using namespace std;

// Common type definitions
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// Macros for convenience
#define pyes cout<<"YES"<<endl;
#define pno cout<<"NO"<<endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define endl '\n'
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define f(i, a, b) for (ll i = (a); i < (b); ++i)
#define rf(i, a, b) for (int i = (a); i >=(b); --i)
#define trav(x, a) for (auto &x : a)

// Debugging (remove in production)
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const double PI = acos(-1.0);

// Fast I/O
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Template functions
template<typename T> void print_vector(const vector<T>& v) {
    for (const auto& x : v) cout << x << " ";
    cout << endl;
}

template<typename T> void inp(vector<T>& v) {
    f(i,0,v.size()){
        cin>>v[i];
    }
    
}

template<typename T> T mod_add(T a, T b, T m = MOD) {
    a %= m; b %= m;
    return (a + b) % m;
}

template<typename T> T mod_mul(T a, T b, T m = MOD) {
    a %= m; b %= m;
    return (a * b) % m;
}

template<typename T> T mod_pow(T base, T exp, T m = MOD) {
    T res = 1;
    while (exp > 0) {
        if (exp & 1) res = mod_mul(res, base, m);
        base = mod_mul(base, base, m);
        exp >>= 1;
    }
    return res;
}



ll GCD(ll a, ll b) {
    
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll allFactors(long long n) {
    vector<long long> factors;
    

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {

            factors.push_back(i);

            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    

    sort(factors.begin(), factors.end());
    
    return factors.size();
}
  

 ll MEX(set<int> &s){
     int ans = 0;
     while(s.count(ans)){
         ans++;
     }
     return ans;
 }

 ll LCM(ll a, ll b){
     return (1LL*a * b) / GCD(a, b);
 }
 

// Solve function for each test case
ll n,c,d,x,y,z,h,k,l,s,m,p,q,r,a,t,b;



void solve()
{
    
}
// Main function
int main() {
    fast_io();
    //cout<<fixed<<setprecision(10);
    ll Tt=1;
    cin >> Tt;
    
    while(Tt--) {
        solve();
    }
    
    return 0;

    
}