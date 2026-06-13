#include <iostream>

using namespace std;

// Interface
class Playable {
public:
    virtual void play() = 0;
};

// Veena Class
class Veena : public Playable {
public:
    void play() override {
        cout << "Veena is playing" << endl;
    }
};

// Saxophone Class
class Saxophone : public Playable {
public:
    void play() override {
        cout << "Saxophone is playing" << endl;
    }
};

int main() {

    Veena v;
    Saxophone s;

    v.play();
    s.play();

    return 0;
}