#include <iostream>
#include <vector>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {

    vector<int> count(26, 0);

    for(char c : magazine) {
        count[c - 'a']++;
    }

    for(char c : ransomNote) {

        int idx = c - 'a';

        if(count[idx] == 0) {
            return false;
        }

        count[idx]--;
    }

    return true;
}

int main() {

    string ransomNote = "aa";
    string magazine = "aab";

    if(canConstruct(ransomNote, magazine))
        cout << "True";
    else
        cout << "False";

    return 0;
}