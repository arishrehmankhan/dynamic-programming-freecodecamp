// Write a function 'canSum(targetSum, numbers)' that takes in a
// targetSum and an array of numbers an arguments.

// The function should return a boolean indicatin whether or not it
// is possible to generate the targetSum using numbers from the array.

// You may use an element of the array as many times as needed.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool canSum (ll targetSum, vector<ll> numbers, unordered_map<ll, ll>& dp) {
    if (dp[targetSum] == 1) return true;
    else if (dp[targetSum] == 2) return false;
    if (targetSum == 0) return true;
    if (targetSum < 0) return false;
    for (ll i = 0; i < numbers.size(); i++) {
        if (canSum(targetSum - numbers[i], numbers, dp)){
            dp[targetSum] = 1;
            return true;
        }
    }
    dp[targetSum] = 2;
    return false;
}

int main() {

    unordered_map<ll, ll> dp;
    cout << canSum(7, {2, 3}, dp) << endl;

    dp.clear();
    cout << canSum(7, {5, 3, 4, 7}, dp) << endl;

    dp.clear();
    cout << canSum(7, {2, 4}, dp) << endl;

    dp.clear();
    cout << canSum(7, {2, 3, 5}, dp) << endl;

    dp.clear();
    cout << canSum(300, {7, 14}, dp) << endl;
    
    return 0;
}