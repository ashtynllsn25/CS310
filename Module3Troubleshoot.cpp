// Ashtyn Ellison - Programming with C++
// Module 3 Troubleshooting Discussion 

#include <iostream>

using namespace std;

int main() {
    string ifPet;
    string petType;
    string petName;
    
    // Ask if the user has a pet
    cout << "Do you have a pet? (Please enter Y or N): ";
    cin >> ifPet;
    
    // Check if the user said no
    if (ifPet == N || ifPet == n) {  // ERROR: N and n should be in quotes
        cout << "You don't have a pet!" << endl;
    } else  // If the user said yes
        // Ask what kind of pet
        cout << "What kind of pet do you have? "; 
        cin >> petType; 
        
        // Ask for the pet's name
        cout << "What is your pet's name? ";
        cin >> petName;

        // Display pet info
        cout << "You have a " << petType << " named " << petName << "!" << endl;

    return 0;
}