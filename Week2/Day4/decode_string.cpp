#include <iostream>
#include <stack>

using namespace std;

string decodeString(string s) {

    stack<int> counts;
    stack<string> result;

    string current = "";
    int k = 0;

    for(char c : s) {

        if(isdigit(c)) {

            k = k * 10 + (c - '0');
        }
        else if(c == '[') {

            counts.push(k);
            result.push(current);

            k = 0;
            current = "";
        }
        else if(c == ']') {

            string temp = current;

            current = result.top();
            result.pop();

            int repeat = counts.top();
            counts.pop();

            while(repeat--) {
                current += temp;
            }
        }
        else {

            current += c;
        }
    }

    return current;
}

int main() {

    string s = "3[a2[c]]";

    cout << decodeString(s);

    return 0;
}