#include <iostream>
#include <iomanip>  // for manipulators
#include <fstream>  // for file streams
#include <locale>
using namespace std;


int main() {
    // --- Variables ---
    double netBalance, payment, monthlyInterestRate;
    int d1, d2;


    // --- File output setup ---
    ofstream outFile("monthly_interest.txt"); // write results to a file
    if (!outFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }


    // --- Input starting balance---
    cout << "Enter starting balance: ";
    cin >> netBalance; // read balance
    if (cin.fail()) {
        cout << "Invalid input. Program will end." << endl;
        return 1;
    }


    // --- Input payment ---
    cout << "Enter amount paid: ";
    cin >> payment;
    if (cin.fail()) {          // fail state check
        cout << "Invalid input. Program will end." << endl;
        return 1;
    }
        
    // --- Input interest rate ---
    cout << "Enter monthly interest rate (e.g. 0.0152 for 1.52%): ";
    cin >> monthlyInterestRate;
    if (cin.fail()) {
        cout << "Invalid input. Program will end." << endl;
        return 1;
    }


    // --- Input days of the month ---
    cout << "Enter how many days of the month: ";
    cin >> d1;
    if (cin.fail()) {
        cout << "Invalid input. Program will end." << endl;
        return 1;
    }


        
    // --- Input days left after payment ---
    cout << "Enter how many days are left of the month: ";
    cin >> d2;
    if (cin.fail()) {
        cout << "Invalid input. Program will end." << endl;
        return 1;
    }


    // --- Calculate average daily balance & interest ---
    double averageDailyBalance = (netBalance * d1 - payment * d2) / d1;
    double interest = averageDailyBalance * monthlyInterestRate;


    // --- Set locale for thousands separator ---
    cout.imbue(locale(""));
    outFile.imbue(locale(""));


    // --- Output to console ---
    cout << fixed << setprecision(2); // setting the decimal place
    cout << right << setw(15) << "Balance"
         << setw(15) << "Payment"
         << setw(15) << "Days in month"
         << setw(20) << "Days left of month"
         << setw(15) << "Interest" << endl;


    cout << right << setw(15) << netBalance
         << setw(15) << payment
         << setw(15) << d1
         << setw(20) << d2
         << setw(15) << interest << endl;
         
    // --- Output to file ---
    outFile << fixed << setprecision(2);
    outFile << right << setw(15) << "Balance"
            << setw(15) << "Payment"
            << setw(15) << "Days in month"
            << setw(20) << "Days left of month"
            << setw(15) << "Interest" << endl;
    
    outFile << right << setw(15) << netBalance
            << setw(15) << payment
            << setw(15) << d1
            << setw(20) << d2
            << setw(15) << interest << endl;


    outFile.close();
    cout << "Monthly interest data saved to monthly_interest.txt" << endl;


    return 0;
}