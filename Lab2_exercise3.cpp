// Lab 2 Exercise 3

#include <iostream>
using namespace std;

int main() {
    double numero1, numero2; // operands
    char O; // operator

    // ask user for input
    cout << "Enter first number: ";
    cin >> numero1;
    cout << "Enter second number: ";
    cin >> numero2;
    cout << "Enter operator (+, -, *, /): ";
    cin >> O;

    // Perform calculation
    switch(O) {
        case '+':
            cout << "the summation is ";
            cout << (numero1 + numero2);
            break;
        case '-':
            cout << "the subtraction is ";
            cout << (numero1 - numero2);
            break;
        case '*':
            cout << "the multiplication is ";
            cout << (numero1 * numero2);
            break;
        case '/':
            cout << "the division is ";
            cout << (numero1 / numero2);
            break;
    }
    
    cout << "\npress Enter to exit"; // for executable file
    cin.ignore();    
    cin.get();
    return 0;      

}