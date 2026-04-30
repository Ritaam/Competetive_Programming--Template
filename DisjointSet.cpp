#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int>parent, rank, size;

    public:
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);

        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }

    }

    int findUpar(int  node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};


// int main() {
//     DisjointSet ds(7);
//     ds.unionByRank(1, 2);
//     ds.unionByRank(2, 3);
//     ds.unionByRank(4, 5);
//     ds.unionByRank(6, 7);
//     ds.unionByRank(5, 6);

//     if(ds.findUpar(3) == ds.findUpar(7)) {
//         cout << "Same\n";
//     }
//     else {
//         cout << "Not Same\n";
//     }

//      if(ds.findUpar(1) == ds.findUpar(3)) {
//         cout << "Same\n";
//     }
//     else {
//         cout << "Not Same\n";
//     }

//      if(ds.findUpar(4) == ds.findUpar(7)) {
//         cout << "Same\n";
//     }
//     else {
//         cout << "Not Same\n";
//     }

//      if(ds.findUpar(5) == ds.findUpar(7)) {
//         cout << "Same\n";
//     }
//     else {
//         cout << "Not Same\n";
//     }

//      if(ds.findUpar(6) == ds.findUpar(7)) {
//         cout << "Same\n";
//     }
//     else {
//         cout << "Not Same\n";
//     }

//      if(ds.findUpar(1) == ds.findUpar(7)) {
//         cout << "Same\n";
//     }
//     else {
//         cout << "Not Same\n";
//     }
// }