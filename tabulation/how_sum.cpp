// Write a function 'howSum(targetSum, numbers)' that takes in a
// targetSum and an array of numbers as arguments.

// The function should return an array containing any combination of
// elements that adds up tp exactly the targetSum. If there is no
// combination that adds up to the targetSum, then return null.

// If there are multiple combinations possible, you may return any
// single one.

// Note: I have used {-1} to represent null as in C++ vectors can't be null.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fileio freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define mod 1000000007

vector<ll> howSum(ll targetSum, vector<ll> numbers) {
    vector<vector<ll>> table(targetSum+1);
    for (ll i = 0; i <= targetSum; i++) {
        table[i].push_back({-1});
    }
    table[0] = {};
    for (ll i = 0; i <= targetSum; i++) {
        if (table[i].empty() || table[i][0] != -1) {
            for (ll j = 0; j < numbers.size(); j++) {
                if (i + numbers[j] <= targetSum) {
                    table[i+numbers[j]] = table[i];
                    table[i+numbers[j]].push_back(numbers[j]);
                }
            }
        }
    }
    return table[targetSum];
}

int main() {

    vector<ll> v;

    v = howSum(7, {2, 3});
    if (v.empty())
        cout << "[]" << endl;
    else if (v[0] == -1)
        cout << "No solution" << endl;
    else {
        for (ll i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
    }
    cout << endl;

    v = howSum(7, {5, 3, 4, 7});
    if (v.empty())
        cout << "[]" << endl;
    else if (v[0] == -1)
        cout << "No solution" << endl;
    else {
        for (ll i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    v = howSum(7, {2, 4});
    if (v.empty())
        cout << "[]" << endl;
    else if (v[0] == -1)
        cout << "No solution" << endl;
    else {
        for (ll i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    v = howSum(7, {2, 3, 5});
    if (v.empty())
        cout << "[]" << endl;
    else if (v[0] == -1)
        cout << "No solution" << endl;
    else {
        for (ll i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    v = howSum(300, {7, 14});
    if (v.empty())
        cout << "[]" << endl;
    else if (v[0] == -1)
        cout << "No solution" << endl;
    else {
        for (ll i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}