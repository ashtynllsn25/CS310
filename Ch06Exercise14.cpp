// --- Ashtyn Ellison - Programming with C++ ---
// --- Chapter 6 Exercise 14 ---

#include <iostream> 
#include <iomanip>
using namespace std; 

// --- Define Function ---
// Calculate the billing amount base on variables given later ---
double calculateBilling(double rate, int minutes, bool lowIncome) {
    double billingAmount = 0.0;  // final charge

    if (lowIncome && minutes <= 30) {
        billingAmount = 0.0;    // Free under 30 minutes for low income
    }
    else if (lowIncome && minutes > 30) {
        int extraMinutes = minutes - 30;
        billingAmount = rate * 0.40 * (extraMinutes / 60.0);  // 40% rate for extra time
    }
    else if (!lowIncome && minutes <= 20) {
        billingAmount = 0.0;    // Free under 20 minutes for others 
    }
    else { 
        int extraMinutes = minutes - 20; 
        billingAmount = rate * 0.70 * (extraMinutes / 60.0);  // 70% rate for extra time
    }
    return billingAmount;
}

int main() {
    // --- Variables ---
    double rate;
    int minutes; 
    char incomeStatus;   // holds the answer temporarily
    bool lowIncome;      // stores true or false

    // --- User Input ---
    cout << "Enter the hourly rate: ";
    cin >> rate;
    
    cout << "Enter total consulting time in minutes: ";
    cin >> minutes;

    cout << "Does the person qualify for low income (y/n)? ";
    cin >> incomeStatus;    

    // --- Convert char to bool ---
    lowIncome = (incomeStatus == 'y' || incomeStatus == 'Y'); 

    // --- Verify income ---
    cout << "Low income status: " << boolalpha << lowIncome << endl;

    // --- Call function for calculation ---
    double totalCharge = calculateBilling(rate, minutes, lowIncome);
    
    // --- Show result ---
    cout << fixed;
    cout.precision(2);
    cout << "\nTotal billing amount: $" << totalCharge << endl;

    return 0;
}
