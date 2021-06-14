// Write a functin 'canConstruct(target, wordBank)' that accepts a
// target string and an array of string.

// The function should return a boolean indicating whether or not the
// 'target' can be constructed by concatenating elements of the
// 'wordBank' array.

// You may reuse elements of 'wordBank' as many times as needed.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fileio freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define mod 1000000007

bool canConstruct(string target, vector<string> numbers) {
    
    ll n = target.length() + 1;
    vector<bool> table(n);
    table[0] = true;
    for (ll i = 0; i < n; i++) {
        if (table[i]) {
            for (ll j = 0; j < numbers.size(); j++) {
                if (target.substr(i, numbers[j].length()).compare(numbers[j]) == 0) {
                    table[i + numbers[j].length()] = true;
                }
            }
        }
    }
    return table[target.length()];

}

int main() {

    cout << canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << endl;
    cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;
    cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl;
    cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"ab", "abc", "cd", "def", "abcd"}) << endl;

    return 0;
}