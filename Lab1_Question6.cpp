// Lab 1 Question 6

#include <iostream>
using namespace std;

int main() {
    int numero, reversed = 0;

    // take input from user
    cout << "Enter an integer: ";
    cin >> numero;

    // reverse the digits using a for loop
    for (; numero != 0; numero /= 10) {
        int vikaluku = numero % 10; // Extract the last digit
        reversed = reversed * 10 + vikaluku; // Append it to the reversed number
    }

    // print reversed number
    cout << "reversed number is: " << reversed << endl;

    // for executable file
    cout << "Press Enter to exit";
    cin.ignore();
    cin.get();
    return 0;
}