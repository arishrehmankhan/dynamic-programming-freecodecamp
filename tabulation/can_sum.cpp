// Write a function 'canSum(targetSum, numbers)' that takes in a
// targetSum and an array of numbers an arguments.

// The function should return a boolean indicatin whether or not it
// is possible to generate the targetSum using numbers from the array.

// You may use an element of the array as many times as needed.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool canSum(ll target, vector<ll> numbers) {

    bool table[target+1] = {false};
    table[0] = true;

    for (ll i = 0; i <= target; i++) {
        if (table[i]) {
            for (ll j = 0; j < numbers.size(); j++) {
                if (i + numbers[j] <= target)
                    table[i + numbers[j]] = true;
            }
        }
    }

    return table[target];
}

int main() {

    cout << canSum(7, {2, 3}) << endl;
    cout << canSum(7, {5, 3, 4, 7}) << endl;
    cout << canSum(7, {2, 4}) << endl;
    cout << canSum(7, {2, 3, 5}) << endl;
    cout << canSum(300, {7, 14}) << endl;

    return 0;
}