// ---- Ashtyn Ellison - Programming with C++ ---
// --- Module 5 Troubleshooting Discussion ---

#include <iostream>
using namespace std;

void askPetInfo() {
    string petType;
    string petName;

    cout << "What kind of pet do you have? ";
    cin >> petType;

    cout << "What is your pet's name? ";
    cin >> petName;

    cout << "You have a " << petType << " named " << petName << "!" endl;
}

int main() {
    char morePets = 'y';

    if (morePets == 'y') {
        void askPetInfo();  

    cout << "Thanks for sharing your pets!" << endl;
    return 0;
}