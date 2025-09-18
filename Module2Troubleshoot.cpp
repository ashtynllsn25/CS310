#include <iostream>
using namespace std;

int main() {
    string petType;
    string petName;

    cout << "What kind of pet do you have? ";
    cin << petType; 
    
    cout << "What is your pet's name? ";
    cin >> namePet;

    cout << "You have a " << petType << " named " << petName << "!" << endl;

    return 0;
}