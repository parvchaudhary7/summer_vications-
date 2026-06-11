#include <iostream>
#include <string>

using namespace std;

// Interface
class LibraryUser {
public:
    virtual void registerAccount() = 0;
    virtual void requestBook() = 0;
};

// KidUser Class
class KidUser : public LibraryUser {
private:
    int age;
    string bookType;

public:
    KidUser(int age, string bookType) {
        this->age = age;
        this->bookType = bookType;
    }

    void registerAccount() override {
        if (age < 12) {
            cout << "You have successfully registered under a Kids Account" << endl;
        } else {
            cout << "Sorry, Age must be less than 12 to register as a kid" << endl;
        }
    }

    void requestBook() override {
        if (bookType == "Kids") {
            cout << "Book Issued successfully, please return the book within 10 days" << endl;
        } else {
            cout << "Oops, you are allowed to take only kids books" << endl;
        }
    }
};

// AdultUser Class
class AdultUser : public LibraryUser {
private:
    int age;
    string bookType;

public:
    AdultUser(int age, string bookType) {
        this->age = age;
        this->bookType = bookType;
    }

    void registerAccount() override {
        if (age > 12) {
            cout << "You have successfully registered under an Adult Account" << endl;
        } else {
            cout << "Sorry, Age must be greater than 12 to register as an adult" << endl;
        }
    }

    void requestBook() override {
        if (bookType == "Fiction") {
            cout << "Book Issued successfully, please return the book within 7 days" << endl;
        } else {
            cout << "Oops, you are allowed to take only adult fiction books" << endl;
        }
    }
};

int main() {

    KidUser kid(10, "Kids");
    KidUser kid2(18, "Fiction");

    kid.registerAccount();
    kid.requestBook();

    cout << endl;

    kid2.registerAccount();
    kid2.requestBook();

    cout << endl;

    AdultUser adult(5, "Kids");
    AdultUser adult2(25, "Fiction");

    adult.registerAccount();
    adult.requestBook();

    cout << endl;

    adult2.registerAccount();
    adult2.requestBook();

    return 0;
}