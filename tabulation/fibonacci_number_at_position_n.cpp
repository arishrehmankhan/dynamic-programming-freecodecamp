// Write a function 'fib(n)' that takes a number as a argument.
// The function should return the nth number of the Fibonacci sequence.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll fib(ll n) {
    ll table[n+1] = {0};
    table[1] = 1;
    for (ll i = 0; i <= n; i++) {
        table[i + 1] += table[i];
        if (i + 1 < n)
            table[i+2] += table[i];
    }
    return table[n];
}

int main() {

    cout << fib(6)  << endl;
    cout << fib(7)  << endl;
    cout << fib(8)  << endl;
    cout << fib(50)  << endl;

    return 0;
}