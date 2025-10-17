// --- Ashtyn Ellison - Programming with C++ ---
// --- Chapter 7 Exercise 4 ---

#include <iostream>
#include <iomanip>
#include <string>
using namespace std; 

// --- Define Function ---

// --- Identify if there are vowels ---
bool isVowel(char ch){
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' || 
		ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y') {
		return true;
	}
	else {
		return false;
	}
}

// --- Remove vowels if isVowel is true ---
string removeVowel(string str){
	string noVowels = ""; // to store characters that aren't a vowel
	
	for (int i = 0; i < str.length(); i++){
		if (!isVowel(str[i])) { // only add to noVowels if NOT a vowel
			noVowels += str[i];
		}
	}
		
		return noVowels; // send the new string back
}

int main(){
	// --- Variables ---
	string Word;
	string VowelsRemoved;

	// --- User Input ---
	cout << "Thanks for using the vowel removal tool!" << endl;
	cout << "Please enter in the word you would like to use: ";
	cin >> Word;

	// --- Check string data has been entered ---
	for (char c : Word) {
	    if (isdigit(c)) {
        	cout << "Please enter letters only, not numbers." << endl;
        		return 0;
    		}
	}

	// --- Call function to remove vowels ---
	VowelsRemoved = removeVowel(Word);

	// --- Show result ---
	cout << "Your word without vowels is: " << VowelsRemoved << endl;

	return 0;
}