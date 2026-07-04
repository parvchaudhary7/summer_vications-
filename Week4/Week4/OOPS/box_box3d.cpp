#include <iostream>

using namespace std;

class Box {

protected:

    int length;
    int breadth;
    int height;

public:

    Box(int l,int b,int h) {

        length = l;
        breadth = b;
        height = h;
    }

    int volume() {

        return length * breadth * height;
    }
};

class Box3D : public Box {

public:

    Box3D(int l,int b,int h) : Box(l,b,h) {}

    void display() {

        cout << "Volume = " << volume() << endl;
    }
};

int main() {

    Box3D obj(5,4,3);

    obj.display();

    return 0;
}