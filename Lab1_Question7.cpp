// Lab 1 Question 7

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MIN_LENGTH 8 // Macro for minimum password length

int main() {
    string password;
    cout << "Enter your password: ";
    cin >> password;

    // Initialize flags for each condition
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    // Check password length
    if (password.length() < MIN_LENGTH) {
        cout << "Weak Password: Password must be at least " << MIN_LENGTH << " characters long." << endl;
        cout << "Press Enter to exit";
        cin.ignore();
        cin.get();
        return 0;
    }

    // Iterate through the password to check character types
    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        else if (islower(ch)) hasLower = true;
        else if (isdigit(ch)) hasDigit = true;
        else if (ispunct(ch)) hasSpecial = true;
    }

    // Check if all conditions are met
    if (hasUpper && hasLower && hasDigit && hasSpecial) {
        cout << "Strong Password" << endl;
    } else {
        cout << "Weak Password: Missing criteria - ";
        if (!hasUpper) cout << "uppercase letter, ";
        if (!hasLower) cout << "lowercase letter, ";
        if (!hasDigit) cout << "digit, ";
        if (!hasSpecial) cout << "special character, ";
        cout << endl;
    }
    
    // for executable file
    cout << "Press Enter to exit";
    cin.ignore();
    cin.get();
    return 0;
}

