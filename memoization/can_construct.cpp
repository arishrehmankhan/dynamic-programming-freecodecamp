// Write a functin 'canConstruct(target, wordBank)' that accepts a
// target string and an array of string.

// The function should return a boolean indicating whether or not the
// 'target' can be constructed by concatenating elements of the
// 'wordBank' array.

// You may reuse elements of 'wordBank' as many times as needed.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool canConstruct(string target, vector<string> wordBank, unordered_map<string, int> &memo) {

    if (memo[target] == 1)
        return true;
    if (memo[target] == 2)
        return false;

    if (target == "") return true;
    
    for (ll i = 0; i < wordBank.size(); i++) {
        ll pos = target.find(wordBank[i]);
        if (pos == 0) {
            if(canConstruct(target.substr(wordBank[i].length()), wordBank, memo)) {
                memo[target] = 1;
                return true;
            }
        }    
    }
    memo[target] = 2;
    return false;
}

int main() {

    unordered_map<string, int> memo;

    cout << canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}, memo) << endl;

    memo.clear();
    cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}, memo) << endl;

    memo.clear();
    cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}, memo) << endl;

    memo.clear();
    cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"ab", "abc", "cd", "def", "abcd"}, memo) << endl;

    return 0;
}