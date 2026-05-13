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
    int n;
    cin >> n;
    vi h(n);
    for (auto &x : h) cin >> x;
    vector<int> dp(n, INT_MAX);

    // base case
    dp[0] = 0;

    if (n > 1)
        dp[1] = abs(h[1] - h[0]);

    for (int i = 2; i < n; i++) {
        dp[i] = min(
            dp[i - 1] + abs(h[i] - h[i - 1]),
            dp[i - 2] + abs(h[i] - h[i - 2])

        );
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