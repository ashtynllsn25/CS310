// ---- Ashtyn Ellison - Programming with C++ ---
// --- Module 5 Code Correction ---

#include <iostream>
// Removed global variable calculation
int calculateDifference(int a, int b) {
    return a - b;   // Fixed: missing semicolon
}

// Using the function instead of global 
int main() {
    int a = 497;    // Moved inside main for better scope
    int b = 496;

    std::cout << "We are coming back! " << calculateDifference(a, b) << std::endl;

    return 0;   // Fixed: missing semicolon
}
