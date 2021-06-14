// Write numbers function 'bestSum(targetSum, numbers)' that takes in numbers
// targetSum and an array of numbers as arguments.

// The function should return an array containing the shortese
// combination of numbers that add up to exactly the targetSum.

// If there is numbers tie for the shortest combination, you may return any
// one of the shortest.

// Note: I have used {-1} to represent null as in C++ vectors can't be null.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> bestSum(ll targetSum, vector<ll> numbers, unordered_map<ll, vector<ll>> &memo) {
    
    if (memo.find(targetSum) != memo.end()) return memo[targetSum];
    
    if (targetSum == 0) return {};
    if (targetSum < 0) return {-1};

    vector<ll> shortestCombination = {-1};
    for (ll i = 0; i < numbers.size(); i++) {
        vector<ll> remainderCombination = bestSum(targetSum - numbers[i], numbers, memo);
        if (!remainderCombination.empty()) {
            if (remainderCombination[0] != -1) {
                remainderCombination.push_back(numbers[i]);
            }
        } else {
            remainderCombination.push_back(numbers[i]);
        }

        if (shortestCombination[0] == -1 || remainderCombination.size() < shortestCombination.size()) {
            shortestCombination = remainderCombination;
        }
    }
    memo[targetSum] = shortestCombination;
    return shortestCombination;
}

int main() {

    unordered_map<ll, vector<ll>> memo;
    vector<ll> v;

    v = bestSum(7, {5, 3, 7, 4}, memo);
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
    v = bestSum(8, {2, 3, 5}, memo);
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
    v = bestSum(100, {1, 2, 5, 25}, memo);
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