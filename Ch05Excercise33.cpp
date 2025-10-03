#include <iostream>
using namespace std;

int main() {
    int MinPrepare;   // time for the first dish
    int NextDishTime; // time for each next dish
    int MinTotal;     // total available time
    int Dishes = 0;   // how many dishes Bianca can make
    int TimeUsed = 0; // running total of time spent

    // --- Get first dish time ---
    cout << "Enter time to prepare the first dish: ";
    cin >> MinPrepare;

    while (MinPrepare <= 0) { // re-try loop
        cout << "Invalid! Please enter a positive number: ";
        cin >> MinPrepare;
    }

    // --- Get total time ---
    cout << "Enter total time available: ";
    cin >> MinTotal;

    while (MinTotal <= 0) { // re-try loop
        cout << "Invalid! Please enter a positive number: ";
        cin >> MinTotal;
    }

    int CurrentDishTime = MinPrepare; // start with first dish

    // --- Loop until no time left ---
    while (TimeUsed + CurrentDishTime <= MinTotal) {
        TimeUsed += CurrentDishTime; // add the dish’s time
        Dishes++;                    // count the dishes

        cout << "You have " << MinTotal - TimeUsed << " minutes left available." << endl;

        // Get next dish time
        cout << "Enter time to prepare next dish: ";
        cin >> NextDishTime;

        while (NextDishTime <= 0) { // re-try loop
            cout << "Invalid! Please enter a positive number: ";
            cin >> NextDishTime;
        }

        CurrentDishTime = NextDishTime; // update for next round
    }

    // --- Final output ---
    cout << "Bianca can prepare " << Dishes << " dishes." << endl;

    return 0;
}