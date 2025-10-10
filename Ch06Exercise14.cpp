#include <iostream>
#include <iomanip> // <-- add this for formatting
using namespace std;

// --- Define Function ---
double calculateBilling(double rate, int minutes, bool lowIncome) {
    double billingAmount = 0.0;

    if (lowIncome && minutes <= 30) {
        billingAmount = 0.0;
    }
    else if (lowIncome && minutes > 30) {
        int extraMinutes = minutes - 30;
        billingAmount = rate * 0.40 * (extraMinutes / 60.0);
    }
    else if (!lowIncome && minutes <= 20) {
        billingAmount = 0.0;
    }
    else {
        int extraMinutes = minutes - 20;
        billingAmount = rate * 0.70 * (extraMinutes / 60.0);
    }

    return billingAmount;
}

int main() {
    double rate;
    int minutes;
    char incomeStatus;
    bool lowIncome;

    cout << "Enter your hourly rate: ";
    cin >> rate;

    cout << "Enter total consulting time in minutes: ";
    cin >> minutes;

    cout << "Do you believe you qualify for low income (y/n)? ";
    cin >> incomeStatus;

    lowIncome = (incomeStatus == 'y' || incomeStatus == 'Y');

    // --- Double-check income ---
    double yearlyIncome = rate * 40 * 52;

    cout << fixed << showpoint << setprecision(2); // 🔧 formatting fix

    if (lowIncome) {
        cout << "\nEstimated yearly income: $" << yearlyIncome << endl;
        if (yearlyIncome > 25000) {
            cout << "Based on your hourly rate, you may NOT qualify for low income assistance.\n";
            cout << "Would you still like to continue as low income (y/n)? ";
            cin >> incomeStatus;
            lowIncome = (incomeStatus == 'y' || incomeStatus == 'Y');
        }
    }

    double totalCharge = calculateBilling(rate, minutes, lowIncome);

    cout << "\n--- Billing Summary ---\n";
    cout << "Hourly rate: $" << rate << " per hour\n";
    cout << "Consulting time: " << minutes << " minutes\n";
    cout << "Total billing amount: $" << totalCharge << endl;

    if (lowIncome)
        cout << "(Low income discount applied at 40% rate)\n";
    else
        cout << "(Standard rate applied at 70%)\n";

    return 0;
}
