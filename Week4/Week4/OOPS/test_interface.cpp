#include <iostream>

using namespace std;

class Test {
public:
    virtual void square(int x) = 0;
};

class Arithmetic : public Test {
public:
    void square(int x) override {
        cout << "Square = " << x * x << endl;
    }
};

int main() {

    Arithmetic obj;

    obj.square(5);

    return 0;
}