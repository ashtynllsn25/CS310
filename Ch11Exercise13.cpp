// --- Ashtyn Ellison - Programming with C++ ---
// --- Chapter 11 Exercise 13 ---

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// --- Bank Account Class ---
class BankAccount {
protected:
    string HoldersName;    // --- Account holder's name ---
    int AccountNum;        // --- Unique account number ---
    double Balance;        // --- Current balance ---    
    static int nextAccountNum; // --- Static variable for auto account numbers ---

public:
    BankAccount(string name = "", double bal = 0.0) {
        HoldersName = name;                          
        Balance = bal;                           
        AccountNum = nextAccountNum; // --- Assign next available account number ---
        nextAccountNum++;            // --- Increment for next account ---
    }

    // --- Function for Deposits ---
    void deposit(double amount) {
        Balance += amount;           
        cout << "Deposited $" << amount << ". New balance: $" << Balance << endl;
    }

    // --- Function for Withdraws ---
    virtual void withdraw(double amount) {
        if (amount <= Balance) {     
            Balance -= amount;       
            cout << "Withdrew $" << amount << ". New balance: $" << Balance << endl;
        } else {
            cout << "Insufficient funds! Balance: $" << Balance << endl;
        }
    }

    // --- Function for Display ---
    virtual void displayAccountInfo() {
        cout << fixed << setprecision(2);
        cout << "\nAccount Holder: " << HoldersName << endl;
        cout << "Account Number: " << AccountNum << endl;
        cout << "Balance: $" << Balance << endl;
    }
};

// --- Initialize static variable ---
int BankAccount::nextAccountNum = 1000;

// --- Savings Account Class (inherits from BankAccount) ---
class SavingsAccount : public BankAccount {
private: 
    double interestRate; // --- Interest rate for savings ---

public:
    SavingsAccount(string name, double bal, double rate)
        : BankAccount(name, bal), interestRate(rate) {}

    // --- Add Interest ---
    void addInterest() {
        double interest = (Balance * interestRate) / 100;
        deposit(interest);
        cout << "Interest added: $" << interest << endl;
    }

    // --- Override Display ---
    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// --- Checking Account Class (inherits from BankAccount) ---
class CheckingAccount : public BankAccount {
private:
    double fee; // --- Transaction fee ---

public: 
    CheckingAccount(string name, double bal, double f)
        : BankAccount(name, bal), fee(f) {}

    // --- Override withdraw to include fee ---
    void withdraw(double amount) override {
        double total = amount + fee;
        if (total <= Balance) {
            Balance -= total;
            cout << "Withdrew $" << amount << " (Fee: $" << fee << "). New balance: $" << Balance << endl;
        } else {
            cout << "Insufficient funds (including fee)! Balance: $" << Balance << endl;
        }
    }

    // --- Override Display ---
    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Transaction Fee: $" << fee << endl;
    }
};

// --- Main Function ---
int main() {
	// --- Variables ---
	string name, type;
	double balance, rate, fee;
	
	cout << "Thanks for using Star Bank and Credit Union!" << endl;
	
	cout <<"\nEnter account holder's name: ";
	cin >> name;

	cout << "Enter account type (checking/savings): ";
	cin >> type;
	
	cout << "Enter your starting balance: ";
	cin >> balance;
	
	if (type == "checking" || type == "Checking") {
		cout << "Enter transaction fee: ";
		cin >> fee;
		CheckingAccount userAccount(name, balance, fee); //--- Create Checking Account ---
		cout << "\n--- Checking Account Created ---"; 
		userAccount.displayAccountInfo();
	}
	
	else if (type == "savings" || type == "Savings") {
		cout << "Enter interest rate: ";
		cin >> rate;
		SavingsAccount userAccount(name, balance, rate); //--- Create Savings Account ---
		cout << "\n--- Savings Account Created ---";
		userAccount.displayAccountInfo();
	}
	
	else {
		cout << "Invalid account type entered!" << endl;
	}
			
    // --- Create accounts ---
    BankAccount baseAccount("Alice", 500.0);
    SavingsAccount saveAccount("Bob", 1000.0, 3.5);
    CheckingAccount checkAccount("Charlie", 800.0, 2.0);

    // --- Demonstrate account functions ---
    baseAccount.deposit(100);           // --- Deposit $100 ---
    baseAccount.withdraw(50);           // --- Withdraw $50 ---
    baseAccount.displayAccountInfo();   // --- Show updated base account info ---

    cout << "\n--- Savings Account ---" << endl;
    saveAccount.addInterest();          // --- Add interest to savings ---
    saveAccount.displayAccountInfo();   // --- Display savings info ---

    cout << "\n--- Checking Account ---" << endl;
    checkAccount.withdraw(100);         // --- Withdraw with fee ---
    checkAccount.displayAccountInfo();  // --- Display checking info ---

    return 0;
}