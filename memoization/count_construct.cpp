// Write a function 'countConstruct(target, wordBank)' that accepts a
// target string and an array of strings.

// The function should return the number of ways that the 'target' can
// be constructed by concatenating elements of the 'wordBank' array.

// You may reuse elements of 'wordBank' an many times a you needed.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll countConstruct(string target, vector<string> wordBank, unordered_map<string, ll> &memo) {

    if (memo.find(target) != memo.end()) return memo[target];
    if (target == "") return 1;
    
    ll count = 0;
    for (ll i = 0; i < wordBank.size(); i++) {
        ll pos = target.find(wordBank[i]);
        if (pos == 0) {
            count += countConstruct(target.substr(wordBank[i].length()), wordBank, memo);
        }    
    }
    memo[target] = count;
    return count;
}

int main() {

    unordered_map<string, ll> memo;

    cout << countConstruct("purple", {"purp", "p", "ur", "le", "purpl"}, memo) << endl;

    memo.clear();
    cout << countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}, memo) << endl;

    memo.clear();
    cout << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}, memo) << endl;

    memo.clear();
    cout << countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}, memo) << endl;

    memo.clear();
    cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"ab", "abc", "cd", "def", "abcd"}, memo) << endl;

    return 0;
}