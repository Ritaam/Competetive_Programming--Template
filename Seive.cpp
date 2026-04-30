#include <bits/stdc++.h>
using namespace std;


vector<int> sieveOfEratosthenes(int n) {
    
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; 

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            // Mark multiples of p as false
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// int main() {
//     int n;
//     cout << "Enter the value of n: ";
//     cin >> n;

//     // Get all prime numbers up to n
//     vector<int> primes = sieveOfEratosthenes(n);

//     // Print the prime numbers
//     cout << "Prime numbers up to " << n << " are:" << endl;
//     for (int prime : primes) {
//         cout << prime << " ";
//     }
//     cout << endl;

//     return 0;
// }
