#include <iostream>

using namespace std;

class Outer {

public:

    class Inner {

    public:

        void display() {

            cout << "Inside Inner Class" << endl;
        }
    };

    void show() {

        cout << "Inside Outer Class" << endl;
    }
};

int main() {

    Outer obj;

    obj.show();

    Outer::Inner in;

    in.display();

    return 0;
}