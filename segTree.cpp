#include<bits/stdc++.h>
using namespace std;

class SGTree {
    vector<int> seg;
    int n;

public:
    SGTree(int n) {
        this->n = n;
        seg.resize(4 * n);
    }

    void build(int idx, int low, int high, vector<int> &arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2*idx+1, low, mid, arr);
        build(2*idx+2, mid+1, high, arr);

        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }

    int query(int idx, int low, int high, int l, int r) {
        //no overlap
        //(high low) (l,r) ||  (l,r) (high, low);
        if (r < low || high < l) return INT_MAX;

        //complete overlap
        //[l low,high, r]
        if (low >= l && high <= r) return seg[idx];

        int mid = low + (high - low) / 2;
        int left = query(2*idx+1, low, mid, l, r);
        int right = query(2*idx+2, mid+1, high, l, r);

        return min(left, right);
    }

    int query(int l, int r) {
        return query(0, 0, n-1, l, r);
    }

    void update(int idx, int low, int high, int i, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2*idx+1, low, mid, i, val);
        else
            update(2*idx+2, mid+1, high, i, val);

        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }

    void update(int i, int val) {
        update(0, 0, n-1, i, val);
    }
};



// void solve() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     int seg[4 * n];
//     build(0, 0, n - 1, arr);
//     int q;
//     cin >> q;
//     while(q--) {
//         int type;
//         cin >> type;
//         if(type == 1) {
//             int l,r;
//             cin >> l >> r;
//             cout << query(0,0,n-1,l,r) << endl;
//         } else {
//             int i,val;
//             cin >> i >> val;
//             update(0, 0, n - 1, i, val);
//             arr[i] = val;
//         }
//     }
// }

// int main() {
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r",stdin);
//         freopen("output.txt","w",stdout);
//     #endif
//     solve();

// }