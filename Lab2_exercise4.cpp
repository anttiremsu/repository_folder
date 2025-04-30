// Lab 2 Exercise 4

#include <iostream>
using namespace std;

int main() {
    signed int number;
    while(true) {

        cout << "\nEnter number: ";
        cin >> number;

        if (number < 0) {
            break;
        }

        else if (number > 0){
            cout << "Square of input is "; 
            cout << number * number; 
        }

        else if (number == 0) {
            continue;
        }
    }

    // for executable file
    cout << "press Enter to exit";
    cin.ignore();    
    cin.get();
    return 0;      
}