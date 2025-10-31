// --- Ashtyn Ellison - Programming with C++ ---
// --- Chapter 10 Exercise 21 ---

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// --- Bank Account Class ---
class BankAccount {
private:
    string HoldersName;    // --- Account holder's name ---
    int AccountNum;        // --- Unique account number ---
    string Type;           // --- Account type: checking or saving ---
    double Balance;        // --- Current balance ---
    double Interest;       // --- Interest rate as decimal ---
    
    static int nextAccountNum; // --- Static variable for auto account numbers ---

public:
    // --- Constructor ---
    BankAccount(string name = "", string type = "", double bal = 0.0, double rate = 0.0) {
        HoldersName = name;          
        Type = type;                 
        Balance = bal;               
        Interest = rate;             
        AccountNum = nextAccountNum; // --- Assign next available account number ---
        nextAccountNum++;            // --- Increment for next account ---
    }

    // --- Function for Deposits ---
    void deposit(double amount) {
        Balance += amount;           
        cout << "Deposited $" << amount << ". New balance: $" << Balance << endl;
    }

    // --- Function for Withdraws ---
    void withdraw(double amount) {
        if (amount <= Balance) {     
            Balance -= amount;       
            cout << "Withdrew $" << amount << ". New balance: $" << Balance << endl;
        } else {
            cout << "Insufficient funds! Balance: $" << Balance << endl;
        }
    }

    // --- Function for Interest ---
    void applyInterest() {
        Balance += Balance * Interest;
        cout << "Interest applied. New balance: $" << Balance << endl;
    }

    // --- Function for Display ---
    void displayAccountInfo() {
        cout << fixed << setprecision(2);
        cout << "\nAccount Holder: " << HoldersName << endl;
        cout << "Account Number: " << AccountNum << endl;
        cout << "Account Type: " << Type << endl;
        cout << "Balance: $" << Balance << endl;
        cout << "Interest Rate: " << Interest << endl;
    }
};

// --- Initialize static variable ---
int BankAccount::nextAccountNum = 1000;

int main() {
    BankAccount accounts[10];   // --- Array to store up to 10 accounts ---
    int customerCount = 0;      // --- Tracks how many accounts have been created ---

    // --- Variables for user input ---
    string name, type;
    double balance, interest;

    // --- Prompt for new account info ---
    cout << "Thanks for using Star Bank and Credit Union!" << endl;
    cout << "What is the user's name? ";
    cin >> name;

    cout << "Account type (checking/saving): ";
    cin >> type;

    cout << "Starting balance: ";
    cin >> balance;

    cout << "Interest rate (decimal): ";
    cin >> interest;

    // --- Create the first account and store in array ---
    accounts[customerCount++] = BankAccount(name, type, balance, interest);

    // --- Demonstrate account functions ---
    accounts[0].displayAccountInfo();  // --- Show account info ---
    accounts[0].deposit(100);          // --- Deposit $100 ---
    accounts[0].withdraw(50);          // --- Withdraw $50 ---
    accounts[0].applyInterest();       // --- Apply interest ---
    accounts[0].displayAccountInfo();  // --- Show updated account info ---

    return 0;
}