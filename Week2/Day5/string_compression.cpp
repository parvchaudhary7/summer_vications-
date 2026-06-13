#include <iostream>
#include <vector>

using namespace std;

int compress(vector<char>& chars) {

    int index = 0;
    int i = 0;

    while(i < chars.size()) {

        char current = chars[i];
        int count = 0;

        while(i < chars.size() && chars[i] == current) {
            count++;
            i++;
        }

        chars[index++] = current;

        if(count > 1) {

            string cnt = to_string(count);

            for(char c : cnt)
                chars[index++] = c;
        }
    }

    return index;
}

int main() {

    vector<char> chars = {'a','a','b','b','c','c','c'};

    int len = compress(chars);

    cout << len;

    return 0;
}