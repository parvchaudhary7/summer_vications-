#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Abstract Class
class Compartment {
public:
    virtual string notice() = 0;
};

// First Class
class FirstClass : public Compartment {
public:
    string notice() override {
        return "First Class Compartment";
    }
};

// Ladies
class Ladies : public Compartment {
public:
    string notice() override {
        return "Ladies Compartment";
    }
};

// General
class General : public Compartment {
public:
    string notice() override {
        return "General Compartment";
    }
};

// Luggage
class Luggage : public Compartment {
public:
    string notice() override {
        return "Luggage Compartment";
    }
};

int main() {

    srand(time(0));

    Compartment* train[10];

    for(int i = 0; i < 10; i++) {

        int choice = rand() % 4 + 1;

        switch(choice) {

            case 1:
                train[i] = new FirstClass();
                break;

            case 2:
                train[i] = new Ladies();
                break;

            case 3:
                train[i] = new General();
                break;

            case 4:
                train[i] = new Luggage();
                break;
        }
    }

    cout << "Railway Compartments:\n\n";

    for(int i = 0; i < 10; i++) {
        cout << "Compartment " << i + 1 << " : "
             << train[i]->notice() << endl;
    }

    for(int i = 0; i < 10; i++)
        delete train[i];

    return 0;
}