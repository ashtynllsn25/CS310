// ---- Ashtyn Ellison - Programming with C++ ---
// --- Module 9 Troubleshooting Discussion ---

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    string name;

    void setName(string n) {
        name = n;
    }

    void speak() {
        cout << "I am just an animal..." << endl;
    }
};

// Child class #1
class Dog : public Animal {
public:
    void speak() {
        cout << "Woof! My name is " << name << endl;
    }
};

// Child class #2
class Cat : public Animal {
public:
    void speak() {
        cout << "Meow! My name is " << name << endl;
    }
};

int main() {
    Dog myDog;
    Cat myCat;

    string dogName;
    string catName;

    cout << "Enter your dog's name: ";
    cin >> dogName;
    myDog.setName(dogName);

    cout << "Enter your cat's name: ";
    cin >> catName;
    myCat.setName(catName);

    // myDog.speak();
    // myCat.speak();

    dogName.speak();  

    Doggo extraDog;  

    return 0;
}