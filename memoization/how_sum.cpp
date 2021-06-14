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

vector<ll> howSum(ll targetSum, vector<ll> numbers, unordered_map<ll, vector<ll>> &memo) {

    if (memo.find(targetSum) != memo.end()) return memo[targetSum];

    if (targetSum == 0) return {};
    if (targetSum < 0) return {-1};
    
    for (ll i = 0; i < numbers.size(); i++) {
        vector<ll> remainderResult = howSum(targetSum - numbers[i], numbers, memo);
        if (!remainderResult.empty()) {
            if (remainderResult[0] != -1) {
                remainderResult.push_back(numbers[i]);
                memo[targetSum] = remainderResult;
                return remainderResult;
            }
        } else {
            remainderResult.push_back(numbers[i]);
            return remainderResult;
        }
    }
    memo[targetSum] = {-1};
    return {-1};
}

int main() {

    unordered_map<ll, vector<ll>> memo;
    vector<ll> v;

    v = howSum(7, {2, 3}, memo);
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

    memo.clear();
    v = howSum(7, {5, 3, 4, 7}, memo);
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

    memo.clear();
    v = howSum(7, {2, 4}, memo);
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

    memo.clear();
    v = howSum(7, {2, 3, 5}, memo);
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

    memo.clear();
    v = howSum(300, {7, 14}, memo);
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