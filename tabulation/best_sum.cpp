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

vector<ll> bestSum(ll targetSum, vector<ll> numbers) {
    vector<vector<ll>> table(targetSum+1);
    for (ll i = 0; i <= targetSum; i++) {
        table[i].push_back({-1});
    }
    table[0] = {};
    for (ll i = 0; i <= targetSum; i++) {
        if (table[i].empty() || table[i][0] != -1) {
            for (ll j = 0; j < numbers.size(); j++) {
                if (i + numbers[j] <= targetSum) {

                    vector<ll> temp = table[i];
                    temp.push_back(numbers[j]);

                    if (table[i+numbers[j]][0] == -1 || temp.size() <= table[i+numbers[j]].size())
                        table[i+numbers[j]] = temp;

                }
            }
        }
    }
    return table[targetSum];
}

int main() {

    vector<ll> v;

    v = bestSum(7, {5, 3, 7, 4});
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

    v = bestSum(8, {2, 3, 5});
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
    
    v = bestSum(100, {1, 2, 5, 25});
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