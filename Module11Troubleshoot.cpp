// ---- Ashtyn Ellison - Programming with C++ ---
// --- Module 11 Troubleshooting Discussion ---

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Animal {
private:
    string name;

public:
    void setName(const string& n) {
        if (n.empty()) {
            throw invalid_argument("Name cannot be empty!");
        }
        name = n;
    }

    string getName() const {
        return name;
    }

    // Overloaded + operator combines names
    Animal operator+(const Animal& other) {
        Animal combined;
        combined.name = this->name + "-" + other.name;
        return combined;
    }
};

template <typename T>
class PetBox {
private:
    vector<T> items;

public:
    void add(const T& item) {
        items.push_back(item);
    }

    void listItems() {
        for (const auto& i : items) {
            cout << i.getName() << endl;
        }
    }
};

int main() {
    Animal pet1, pet2;

    string name1, name2;

    cout << "Enter the first pet's name: ";
    cin >> name1;

    cout << "Enter the second pet's name: ";
    cin >> name2;

    try {
        pet1.setName(name1);
        pet2.setName(name2);
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }

    Animal combinedPet = pet1 + pet2;
    cout << "Combined pet name: " << combinedPet.getName() << endl;

    PetBox<Animal> box;
    box.add(pet1);
    box.add(pet2);
    box.add(combinedPet);

    cout << "\nPets stored in the box:\n";
    box.listItems();

    return 0;
}
