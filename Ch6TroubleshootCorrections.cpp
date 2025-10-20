// ---- Ashtyn Ellison - Programming with C++ ---
// --- Module 6 Code Correction ---

#include <iostream>
using namespace std;

// Define zodiac signs using enum
enum Zodiac {Aries, Taurus, Gemini, Cancer, Leo, Virgo, Libra, Scorpio, Sagittarius, Capricorn, Aquarius, Pisces};

int main() {
    Zodiac mySign = Leo; // Fixed: use a valid enumerator

    if (mySign == Leo) { // Fixed: compare enum to enum, not string
        cout << "You are bold and creative!" << endl;
    }

    Zodiac friendSign = Pisces;
    cout << "Your friend's sign is: " << friendSign << endl;

    return 0;
}
