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
typedef long long int lli;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define endl "\n"
#define setbits(x) __builtin_popcountll(x)
#define yes cout << "YES\n"
#define no cout << "NO\n"

const ll INF = 1e18;

void solve() {
   ll n,m;
   cin >> n >> m;

   vi a(m);
   for(auto &x : a) cin >> x;

   sort(all(a));

   // find the maximum internal gaps b/w adjacent clouds
   ll sumMin = 0;
   for(int i = 0; i < m - 1; i++) {
    sumMin = max(sumMin, a[i + 1] - a[i] - 1);
   }

   // calculate  the left and right boudary  gaps
   ll  L = a[0] - 1;
   ll  R = max(0LL, n - a[m - 1]);

   // case 1 : Mandatory boundary moves are enough to cover all internal gaps
   if(sumMin <= L + R) {
    cout << min(2*L + R, 2 * R + L) << "\n";
    return;
   }

   // case 2: Mandatory moves are not enough  to cover all internal gaps
   ll dif = sumMin - (L + R);
   ll ans = INF;

    ll l = L;
    ll r = R + dif;
    ans = min(ans, 2 * l + r);
    ans = min(ans, 2 * r + l);

   cout << ans << "\n";

}

int main() {
    RITAM
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}