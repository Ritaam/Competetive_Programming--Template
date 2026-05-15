#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define pb push_back
#define BIG 998244353
#define MOD 1e9
#define minHeap  priority_queue<int, vector<int>, greater<int>> 
#define RITAM ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define endl "\n"
#define setbits(x) __builtin_popcountll(x)
#define yes cout << "YES\n"
#define no cout << "NO\n"


void solve() {
    const int INF = 1e9;
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for(auto &x : h) cin >> x;
   // State Definition: Let dp[i] be the minimum total cost to reach stone i
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for(int  i = 0; i < n; i++) {
        // Try all possible jump lengths from 1 to K
        for(int j = 1; j <= k; j++) {
            if(i + j < n) {
                dp[i + j] = min(dp[i + j] , dp[i] + abs(h[i] - h[i + j]));
            }
        }
    }
    cout << dp[n - 1] << endl;

}

int main() {
    RITAM
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
    solve();
    return 0;
}