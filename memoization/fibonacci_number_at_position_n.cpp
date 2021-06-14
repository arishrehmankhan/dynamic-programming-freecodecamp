// Write a function 'fib(n)' that takes a number as a argument.
// The function should return the nth number of the Fibonacci sequence.

#include<bits/stdc++.h>
using namespace std;

long long int fib(int n, unordered_map<int, long long int> &memo) {
    if (memo.find(n) != memo.end()) return memo[n];
    if (n <= 2) return 1;
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

int main() {

    unordered_map<int, long long int> memo;
    cout << "fib(6) -> " << fib(6, memo) << endl;
    cout << "fib(7) -> " << fib(7, memo) << endl;
    cout << "fib(8) -> " << fib(8, memo) << endl;
    cout << "fib(50) -> " << fib(50, memo) << endl;

    return 0;
}