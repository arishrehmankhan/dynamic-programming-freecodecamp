// Say that you are a teaveler on a 2D grid. You begin in the
// top left corner and your goal is to travel to the bottom-right
// corner. You may only move down or right.

// In how many way scan you travel to the goal on a grid with
// dimensions m * n ?

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll gridTraveller(ll m, ll n) {
    
    vector<vector<ll>> table(m+1, vector<ll>(n+1, 0));

    table[1][1] = 1;

    for (ll i = 0; i <= m; i++) {
        for (ll j = 0; j <= n; j++) {
            if (j < n)
                table[i][j+1] += table[i][j];
            if (i < m)
                table[i+1][j] += table[i][j];
        }
    }

    return table[m][n];
}

int main() {

    cout << gridTraveller(1, 1) << endl;
    cout << gridTraveller(2, 3) << endl;
    cout << gridTraveller(3, 2) << endl;
    cout << gridTraveller(3, 3) << endl;
    cout << gridTraveller(18, 18) << endl;

    return 0;
}