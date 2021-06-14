// Write a function 'allConstruct(target, wordBank)' that accepts a
// target string and an array of strings.

// The function should return a 2D array containing all of the ways
// that the 'target' can be constructed by concatenating elements of
// the 'wordBank' array. Each element of the 2D array should represent
// one combination that constructs the 'target'.

// You may reuse elements of 'wordBank' as many times as needed.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

list<list<string>> allConstruct(string target, vector<string> wordBank, unordered_map<string, list<list<string>>> &memo) {

    if (memo.find(target) != memo.end()) return memo[target];

    if (target == "") return {{}};

    list<list<string>> result = {};
    for(ll i = 0; i < wordBank.size(); i++) {
        if (target.find(wordBank[i]) == 0) {
            string suffix = target.substr(wordBank[i].length());
            list<list<string>> suffixWays = allConstruct(suffix, wordBank, memo);
            list<list<string>> targetWays;
            for (auto way: suffixWays) {
                way.push_front(wordBank[i]);
                targetWays.push_back(way);
            }
            result.insert(result.end(), targetWays.begin(), targetWays.end());
        }
    }
    memo[target] = result;
    return result;
}

int main() {

    unordered_map<string, list<list<string>>> memo;
    list<list<string>> ret;

    ret = allConstruct("purple", {"purp", "p", "ur", "le", "purpl"}, memo);
    if (ret.empty()) {
        cout << "No solution!" << endl;
    } else {
        for (auto lis: ret) {
            for (auto li: lis) {
                cout << li << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    memo.clear();
    ret = allConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef", "c"}, memo);
    if (ret.empty()) {
        cout << "No solution!" << endl;
    } else {
        for (auto lis: ret) {
            for (auto li: lis) {
                cout << li << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    memo.clear();
    ret = allConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}, memo);
    if (ret.empty()) {
        cout << "No solution!" << endl;
    } else {
        for (auto lis: ret) {
            for (auto li: lis) {
                cout << li << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    memo.clear();
    ret = allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"ab", "abc", "cd", "def", "abcd"}, memo);
    if (ret.empty()) {
        cout << "No solution!" << endl;
    } else {
        for (auto lis: ret) {
            for (auto li: lis) {
                cout << li << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}