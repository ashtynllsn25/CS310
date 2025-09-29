\\ --- Ashtyn Ellison - Programming with C++ ---
\\ --- Module 3 Code Correction --- 

#include <iostream>
using namespace std;

int main() {
    int playerHealth = 50;
    int bossHealth = 100;

    cout << "Battle Start! Player HP: " << playerHealth << " | Boss HP: " << bossHealth << endl;

    if (playerHealth > bossHealth) {
        cout << "Player is stronger and wins easily!" << endl;
    }
    else if (playerHealth == bossHealth) {   // Fixed: corrected case from playerhealth → playerHealth
        cout << "It’s a tie, sudden death mode begins!" << endl;
    }
    else {   // Added braces for clarity and best practice
        cout << "Boss overpowers the player!" << endl;
    }

    return 0;   // Added return statement for completeness
}