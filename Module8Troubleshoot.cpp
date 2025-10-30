// ---- Ashtyn Ellison - Programming with C++ ---
// --- Module 8 Troubleshooting Discussion ---

#include <iostream>
using namespace std;

// enum for pet types
enum PetType { DOG, CAT, FISH, BIRD };

// Class #1: Pet
class Pet {
public:
    string name;
    PetType type;

    // set pet info
    void setPetInfo(string petName, PetType petType) {
        name = petName;
        type = petType;
    }

    // print pet info
    void displayPet() {
        cout << "Pet name: " << name << endl;
        cout << "Pet type: " << type << endl; 
    }
};

// Class #2: PetManager
class PetManager {
public:
    Pet storedPet; 

    void addPet() {
        string userPetName;
        int userTypeChoice;

        cout << "Enter your pet's name: ";
        cin >> userPetName;

        cout << "Pick your pet type (0=Dog, 1=Cat, 2=Fish, 3=Bird): ";
        cin >> userTypeChoice;

        storedPet.setPetInfo(userPetName, (PetType)userTypeChoice);
    }

    void showPet() {
        storedPet.displayPet();
    }
};

class WrongPlacement {
public:
int main() { 
    PetManager manager;
    
    manager.addPet();

    manager.showPet;
    
    return 0;
}

}; 
