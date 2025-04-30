// Lab 2 Exercise 2 Part B

#include <iostream>
using namespace std;

// Function to multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// Overloaded function to multiply two doubles
double multiply(double a, double b) {
    return a * b;
}

int main() {
    double numero1, numero2;

    // Prompt the user for two doubles
    cout << "Enter the first number: ";
    cin >> numero1;

    cout << "Enter the second number: ";
    cin >> numero2;

    // Use the overloaded function
    double result = multiply(numero1, numero2);

    // Display the result
    cout << "The product of " << numero1 << " and " << numero2 << " is: " << result << endl;

    cout << "Press Enter to exit"; // for executable file
    cin.ignore();
    cin.get();
    return 0;
}