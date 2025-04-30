// Lab 2 Exercise 1 part C

#include <iostream>
#include <cmath> // For ceil and floor functions
using namespace std;

// Function to multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// Overloaded function to multiply two doubles
double multiply(double a, double b) {
    return a * b;
}

// Overloaded function to multiply an integer and a double with a flag
double multiply(int a, double b, bool flag) {
    double result = a * b;
    // check flag status
    if (flag) {
        // round down to integer based on flag
        return floor(result);
    }
    return result;
}

int main() {
    double numero1;
    int numero2;
    bool flag;

    // Prompt user input
    cout << "Enter the first number (double): ";
    cin >> numero1;

    cout << "Enter the second number (integer): ";
    cin >> numero2;

    cout << "Enter the flag value (0 for false, 1 for true): ";
    cin >> flag;

    // Use the overloaded function
    double result = multiply(numero2, numero1, flag);

    // Display the result
    cout << "The result of the multiplication is: " << result << endl;

    cout << "Press Enter to exit"; // for executable file
    cin.ignore();
    cin.get();
    return 0;
}