#include <iostream>

using namespace std;

bool repeatedSubstringPattern(string s) {

    string doubled = s + s;

    return doubled.substr(1, doubled.size() - 2).find(s) != string::npos;
}

int main() {

    string s = "abab";

    cout << repeatedSubstringPattern(s);

    return 0;
}