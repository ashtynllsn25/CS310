// --- Ashtyn Ellison - Programming with C++ ---
// --- Chapter 12 Exercise 3 ---

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int numCandidates;

    // ask how many candidates there are
    cout << "Enter the number of candidates: ";
    cin >> numCandidates;

    // create dynamic arrays for names and votes
    string* names = new string[numCandidates];
    int* votes = new int[numCandidates];

    // read each candidate's name and vote count
    for (int i = 0; i < numCandidates; i++) {
        cout << "Candidate " << i + 1 << " name: ";
        cin >> names[i];
        cout << "Votes: ";
        cin >> votes[i];
    }

    // calculate total votes
    int totalVotes = 0;
    for (int i = 0; i < numCandidates; i++)
        totalVotes += votes[i];

    // print header for results
    cout << fixed << showpoint << setprecision(2);
    cout << "\nResults:\n";
    cout << left << setw(15) << "Name"
         << right << setw(10) << "Votes"
         << right << setw(14) << "Percent\n";

    // print each candidate's votes and percentage
    for (int i = 0; i < numCandidates; i++) {
        double percent = (double)votes[i] / totalVotes * 100;
        cout << left << setw(15) << names[i]
             << right << setw(10) << votes[i]
             << right << setw(13) << percent << "%\n";
    }

    // find which candidate has the most votes
    int maxIndex = 0;
    for (int i = 1; i < numCandidates; i++) {
        if (votes[i] > votes[maxIndex])
            maxIndex = i;
    }

    // print the winner
    cout << "\nWinner: " << names[maxIndex] << endl;

    // free the dynamic memory
    delete[] names;
    delete[] votes;

    return 0;
}