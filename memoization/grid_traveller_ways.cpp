// Say that you are a teaveler on a 2D grid. You begin in the
// top left corner and your goal is to travel to the bottom-right
// corner. You may only move down or right.

// In how many way scan you travel to the goal on a grid with
// dimensions m * n ?

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll gridTraveler(ll m, ll n, unordered_map<string, ll> &memo) {
    const string key = to_string(m) + "," + to_string(n);

    if (memo[key] != 0) return memo[key];
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;

    memo[key] = memo[key] = gridTraveler(m - 1, n, memo) + gridTraveler(m, n - 1, memo);
    return memo[key];
}

int main() {

    unordered_map<string , ll> memo;
    cout << gridTraveler(1, 1, memo) << endl;
    cout << gridTraveler(2, 3, memo) << endl;
    cout << gridTraveler(3, 2, memo) << endl;
    cout << gridTraveler(3, 3, memo) << endl;
    cout << gridTraveler(18, 18, memo) << endl;

    return 0;
}