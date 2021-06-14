// Write a function 'countConstruct(target, wordBank)' that accepts a
// target string and an array of strings.

// The function should return the number of ways that the 'target' can
// be constructed by concatenating elements of the 'wordBank' array.

// You may reuse elements of 'wordBank' an many times a you needed.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fileio freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define mod 1000000007

ll countConstruct(string target, vector<string> numbers) {
    ll n = target.length() + 1;
    vector<ll> table(n, 0);
    table[0] = 1;
    for (ll i = 0; i < n; i++) {
        if (table[i] != 0) {
            for (ll j = 0; j < numbers.size(); j++) {
                if (target.substr(i, numbers[j].length()).compare(numbers[j]) == 0 && i + numbers[j].length() < n) {
                    table[i+numbers[j].length()] += table[i];
                }
            }
        }
    }
    return table[target.length()];
}

int main() {

    cout << countConstruct("purple", {"purp", "p", "ur", "le", "purpl"}) << endl;
    cout << countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << endl;
    cout << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;
    cout << countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl;
    cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"ab", "abc", "cd", "def", "abcd"}) << endl;

    return 0;
}