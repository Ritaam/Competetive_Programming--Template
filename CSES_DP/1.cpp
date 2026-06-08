//Your task is to count the number of ways to construct sum n by throwing a dice one or more times. 
//Each throw produces an outcome between 1 and  6.

//For example, if n=3, there are 4 ways:

//1+1+1
//1+2
//2+1
//3

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll>ways(n+1);
    ways[0] = 1;

    for(int i=1; i <= n; i++) {
        ways[i] = 0;
        for(int v = 1; v <= 6; v++) {
            if(i - v >= 0) {
                ways[i] += ways[i - v];
            }
        }
        ways[i] = ways[i] % M;
    }
    cout << ways[n] << "\n";
}