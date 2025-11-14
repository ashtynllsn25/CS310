// ---- Ashtyn Ellison - Programming with C++ ---
// --- Module 10 Troubleshooting Discussion ---

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    string name;

    void setName(string n) {
        name = n;
    }

    virtual void speak() {
        cout << "I am just a basic animal..." << endl;
    }
};

// Child class 1
class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof! I'm " << name << endl;
    }
};

// Child class 2
class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow! I'm " << name << endl;
    }
};

void printPetInfo(Animal* a) {  
    cout << "Pet info: ";
    a->speak();
}

int main() {

    Dog* dPtr = new Dog();
    Cat* cPtr = new Cat();

    string dName, cName;

    cout << "Enter your dog's name: ";
    cin >> dName;
    dPtr->setName(dName);

    cout << "Enter your cat's name: ";
    cin >> cName;
    cPtr->setName(cName);

    Animal* randomPet;  

    printPetInfo(randomPet);  

    delete dPtr;
    delete cPtr;

    return 0;

}
