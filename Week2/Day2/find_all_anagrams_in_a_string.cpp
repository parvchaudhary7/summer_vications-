#include <iostream>
#include <vector>

using namespace std;

vector<int> findAnagrams(string s, string p) {

    vector<int> result;

    vector<int> pCount(26,0);
    vector<int> sCount(26,0);

    for(char c : p)
        pCount[c-'a']++;

    int k = p.size();

    for(int i=0;i<s.size();i++){

        sCount[s[i]-'a']++;

        if(i >= k)
            sCount[s[i-k]-'a']--;

        if(sCount == pCount)
            result.push_back(i-k+1);
    }

    return result;
}

int main() {

    string s = "cbaebabacd";
    string p = "abc";

    vector<int> ans = findAnagrams(s,p);

    for(int x : ans)
        cout << x << " ";

    return 0;
}