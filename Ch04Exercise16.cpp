\\ --- Ashtyn Ellison - Programming with C++ ---
\\ --- Chapter 4 Excercise 16 --- 

#include <iostream>
#include <iomanip>

using namespace std;

int main() { 

    double netPrice;
    int estimatedSales;

    // --- 1st Option Constants ---
    const double DELIVERY_PAYMENT = 5000.0;
    const double PUBLISH_PAYMENT = 20000.0;

    // --- 2nd Option Constants ---
    const double OPTION_2_RATE = 0.125; 

    // --- 3rd Option Constants --- 
    const double OPTION_3_BELOW = 0.10;
    const double OPTION_3_ABOVE = 0.14;
    const int SALES_4000 = 4000;

    cout << "Enter the net price for a copy: ";
    cin >> netPrice;

    cout << "Enter the estimate for number of copies that will be sold: ";
    cin >> estimatedSales;

    // --- Royalty Math ---
    double money1 = DELIVERY_PAYMENT + PUBLISH_PAYMENT;
    double money2 = (netPrice * estimatedSales) * OPTION_2_RATE;

    double money3;
    if (estimatedSales <= SALES_4000) {
        money3 = (netPrice * estimatedSales) * OPTION_3_BELOW;
    } else {
        double salesBelow = netPrice * SALES_4000 * OPTION_3_BELOW;
        double salesAbove = netPrice * (estimatedSales - SALES_4000) * OPTION_3_ABOVE; 
        money3 = salesBelow + salesAbove;
    }

    // Set output to show two decimal places for currency
    cout << fixed << setprecision(2);

    cout << "\n--- Estimated Royalties ---" << endl;
    cout << "Option 1: $" << money1 << endl;
    cout << "Option 2: $" << money2 << endl;
    cout << "Option 3: $" << money3 << endl;

    cout << "\n--- Best Option ---" << endl; 
    if (money1 >= money2 && money1 >= money3) {
        cout << "Option 1 is the best option!" << endl;
    } else if (money2 >= money1 && money2 >= money3) {
        cout << "Option 2 is the best option!" << endl;
    } else {
        cout << "Option 3 is the best option!" << endl;
    }

    return 0;

}
