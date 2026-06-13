#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> mp;

    for(string s : strs) {

        string key = s;
        sort(key.begin(), key.end());

        mp[key].push_back(s);
    }

    vector<vector<string>> result;

    for(auto &it : mp)
        result.push_back(it.second);

    return result;
}

int main() {

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = groupAnagrams(strs);

    for(auto group : ans) {
        for(string word : group)
            cout << word << " ";
        cout << endl;
    }

    return 0;
}