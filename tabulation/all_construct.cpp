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

vector<vector<string>> allConstruct(string target, vector<string> numbers) {
    ll n = target.length();
    vector<vector<vector<string>>> table(n+1);
    table[0] = {{}};
    for (ll i = 0; i <= n; i++) {
        if (!table[i].empty()) {
            for (ll j = 0; j < numbers.size(); j++) {
                ll next_index = i + numbers[j].length();
                if (target.substr(i, numbers[j].length()).compare(numbers[j]) == 0 && next_index <= n) {
                    vector<vector<string>> temp = table[i];
                    for (ll k = 0; k < temp.size(); k++) {
                        temp[k].push_back(numbers[j]);
                        table[next_index].push_back(temp[k]);
                    }
                }
            }
        }
    }
    return table[n];
}

int main() {
    
    vector<vector<string>> ret;

    ret = allConstruct("purple", {"purp", "p", "ur", "le", "purpl"});
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

    ret = allConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef", "c"});
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

    ret = allConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"});
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

    ret = allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"ab", "abc", "cd", "def", "abcd"});
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